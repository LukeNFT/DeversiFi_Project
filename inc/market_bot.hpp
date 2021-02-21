#ifndef MARKET_BOT_HPP
#define MARKET_BOT_HPP

#include <memory>
#include <map>
#include "DvfSimulator.h"
#include "timer.hpp"

/* Class to manage orders on the DvfSimulator */
class MarketBot
{
    public:
        MarketBot(IDvfSimulator* p_sim, double eth_balence, double usd_balence);
        ~MarketBot();

        /* Gets the current order book and refreshes the current orders */
        /* Improvement: Should not be public, Timer should have access */
        void RefreshMarket();

        /* Checks the current balence of Eth and USD */
        /* Improvement: Should not be public, Timer should have access */
        void CheckBalence();

    private:
        IDvfSimulator* m_p_sim;
        double m_eth_balence;
        double m_usd_balence;
        std::shared_ptr<Timer> m_market_refresh_timer;
        std::shared_ptr<Timer> m_asset_timer;
        std::map<IDvfSimulator::OrderID, std::pair<double, double>> m_bid_order_map;
        std::map<IDvfSimulator::OrderID, std::pair<double, double>> m_ask_order_map;

        /* Makes the orders as per the requirements */
        /* Note: order maps must be empty */
        void MakeOrders(double best_bid, double best_ask);
};
#endif
