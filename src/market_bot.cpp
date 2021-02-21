#include <iostream>
#include "market_bot.hpp"

MarketBot::MarketBot(IDvfSimulator* p_sim, double eth_balence, double usd_balence):
                     m_p_sim(p_sim),
                     m_eth_balence(eth_balence),
                     m_usd_balence(usd_balence)
{
    /* Throw if sim pointer invalid */
    if (!p_sim) throw;

    /* Create and start the market refresh timer which manages the current orders */
    m_market_refresh_timer = std::make_shared<Timer>(5, std::bind(&MarketBot::RefreshMarket, this));
    /* Create and start the balence timer which displayes the current Eth and Usd balence */
    m_asset_timer = std::make_shared<Timer>(30, std::bind(&MarketBot::CheckBalence, this));
};

MarketBot::~MarketBot()
{
    m_market_refresh_timer.reset();
    m_asset_timer.reset();
};

void MarketBot::RefreshMarket()
{
    IDvfSimulator::OrderBook current_order_book;
    double best_ask = -1;
    double best_bid = -1;

    /* Gets the current best bid and best ask from the orderbook*/
    current_order_book = m_p_sim->GetOrderBook();
    for (auto it = current_order_book.begin(); it < current_order_book.end(); it++)
    {
        if (it->second > 0.0)
        {
            if ((best_bid <= 0) || (it->first > best_bid))
            {
                best_bid = it->first;
            }
        }
        else
        {
            if ((best_ask <= 0) || (it->first < best_ask))
            {
                best_ask = it->first;
            }
        }
    }

    /* If we have bid orders, loop through them */
    if (!m_bid_order_map.empty())
    {
        for (auto it = m_bid_order_map.begin(); it != m_bid_order_map.end(); it++)
        {
            if (it->second.first > best_bid)
            {
                /* Order has been filled, update the balences */
                m_eth_balence -= it->second.second;
                m_usd_balence += (it->second.second * it->second.first);
            }
            /* Cancel any unfilled order */
            else if (!m_p_sim->CancelOrder(it->first))
            {
                throw;
            }
        }
        /* All bid orders have been handled and updated in the object */
        m_bid_order_map.clear();
    }

    /* If we have ask orders, loop through them */
    if (!m_ask_order_map.empty())
    {
        for (auto it = m_ask_order_map.begin(); it != m_ask_order_map.end(); it++)
        {
            if (it->second.first < best_ask)
            {
                /* Order has been filled, update the balences */
                m_eth_balence += it->second.second;
                m_usd_balence -= (it->second.second * it->second.first);
            }
            /* Cancel any unfilled order */
            else if (!m_p_sim->CancelOrder(it->first))
            {
                throw;
            }
        }
        /* All ask orders have been handled and updated in the object */
        m_ask_order_map.clear();
    }

    MakeOrders(best_bid, best_ask);
};

void MarketBot::MakeOrders(double best_bid, double best_ask)
{
    /* Each order should be 2% of the total eth balence */
    /* Improvement: I think there is a better way  */
    double eth_order_amount = 0.02*m_eth_balence;

    if (m_bid_order_map.empty())
    {
        /* Place 5 bids within 5% of the best bid at 1% intervals */
        for (uint32_t i = 1; i <= 5; i++)
        {
            double bid_price = best_bid - best_bid*(1.0/(100.0/static_cast<double>(i)));
            std::pair<double, double> order = std::make_pair (bid_price, eth_order_amount);
            auto oid = m_p_sim->PlaceOrder(bid_price, eth_order_amount);
            if (oid)
            {
                m_bid_order_map.insert(std::pair<IDvfSimulator::OrderID, std::pair<double, double>>(*oid, order));
            }
            else
            {
                /* Failed to place order */
                /* Improvement: Could use some logic here to adjust order price instead of failing */
                throw;
            }
        }
    }
    else
    {
        /* Current bid orders not processed */
        throw;
    }

    if (m_ask_order_map.empty())
    {
        /* Place 5 asks within 5% of the best ask at 1% intervals */
        for (uint32_t i = 1; i <= 5; i++)
        {
            double ask_price = best_ask + best_ask*(1.0/(100.0/static_cast<double>(i)));
            std::pair<double, double> order = std::make_pair (ask_price, eth_order_amount);
            auto oid = m_p_sim->PlaceOrder(ask_price, -eth_order_amount);
            if (oid)
            {
                m_ask_order_map.insert(std::pair<IDvfSimulator::OrderID, std::pair<double, double>>(*oid, order));
            }
        }
    }
    else
    {
        /* Current bid orders not processed */
        throw;
    }
}

void MarketBot::CheckBalence()
{
    /* Improvement: Not taken into account multithreaded printing */
    std::cout << "Current Balence: Eth " << m_eth_balence << ", USD " << m_usd_balence << std::endl;
};