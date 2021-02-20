#ifndef MARKET_BOT_HPP
#define MARKET_BOT_HPP

#include <memory>
#include "DvfSimulator.h"
#include "timer.hpp"

class MarketBot
{
    public:
        MarketBot(IDvfSimulator* p_sim, double eth_balence, double usd_balence);
    private:
        IDvfSimulator* m_p_sim;
        double m_eth_balence;
        double m_usd_balence;
        std::shared_ptr<Timer> m_market_refresh_timer;
        std::shared_ptr<Timer> m_asset_timer;
};
#endif
