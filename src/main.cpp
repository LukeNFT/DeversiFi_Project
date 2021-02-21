#include <memory>
#include <unistd.h>
#include "DvfSimulator.h"
#include "market_bot.hpp"

int main()
{
    IDvfSimulator* p_sim = DvfSimulator::Create();

    try
    {
        MarketBot* p_market_bot = new MarketBot(p_sim, 10.0, 2000.0);
    }
    catch(const char* msg)
    {
        std::cout << "Market Bot failed to start: " << msg << std::endl;
    }

    sleep (100);

    return true;
}