#include <memory>
#include <unistd.h>
#include "DvfSimulator_test.h"
#include "market_bot.hpp"

int main()
{
    IDvfSimulator* p_sim = DvfSimulatorTest::Create();

    try
    {
        MarketBot* p_market_bot = new MarketBot(p_sim, 10.0, 2000.0);
    }
    catch(const std::exception& e)
    {
        std::cout << "Market Bot failed to start: " << e.what();
    }

    return true;
}