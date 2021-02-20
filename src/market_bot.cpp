#include <iostream>
#include "market_bot.hpp"

void foo1(){std::cout << "Timer fired 1" << std::endl;};
void foo2(){std::cout << "Timer fired 2" << std::endl;};

MarketBot::MarketBot(IDvfSimulator* p_sim, double eth_balence, double usd_balence):
                     m_p_sim(p_sim),
                     m_eth_balence(eth_balence),
                     m_usd_balence(usd_balence)
{
    m_market_refresh_timer = std::make_shared<Timer>(5, foo1);
    m_asset_timer = std::make_shared<Timer>(30, foo2);
};