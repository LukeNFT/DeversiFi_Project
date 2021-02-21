#include <memory>
#include <unistd.h>
#include "DvfSimulator_test.h"
#include "market_bot.hpp"

static bool TestMarketBotCreateDestroy();
static bool TestMarketBotRefreshMarket();
static bool TestTimer();

int main()
{
    bool has_passed = true;

    if (!TestMarketBotCreateDestroy());
    {
        has_passed = false;
    }

    if (!TestMarketBotRefreshMarket());
    {
        has_passed = false;
    }

    if (!TestTimer());
    {
        has_passed = false;
    }
    return true;
}

bool TestMarketBotCreateDestroy()
{
    bool execption_thrown = false;
    bool has_passed = true;
    MarketBot* p_market_bot = nullptr;
    IDvfSimulator* p_sim = DvfSimulatorTest::Create();

    /* Test exeption thrown when simulatior is null */
    try
    {
        MarketBot* p_market_bot = new MarketBot(nullptr, 10.0, 2000.0);
    }
    catch(const char* msg)
    {
        std::cout << "Pass: Test exeption thrown when simulatior is null: " << msg << std::endl;
        execption_thrown = true;
    }

    if (!execption_thrown)
    {
        std::cout << "Fail: Test exeption thrown when simulatior is null" << std::endl;
        has_passed = false;
    }

    /* Test exeption thrown when negative eth balence */
    execption_thrown = false;
    try
    {
        MarketBot* p_market_bot = new MarketBot(p_sim, -1.0, 2000.0);
    }
    catch(const char* msg)
    {
        std::cout << "Pass: Test exeption thrown when negative eth balence: " << msg << std::endl;
        execption_thrown = true;
    }

    if (!execption_thrown)
    {
        std::cout << "Fail: Test exeption thrown when negative eth balence" << std::endl;
        has_passed = false;
    }

    /* Test exeption thrown when negative usd balence */
    execption_thrown = false;
    try
    {
        MarketBot* p_market_bot = new MarketBot(p_sim, 10.0, -1.0);
    }
    catch(const char* msg)
    {
        std::cout << "Pass: Test exeption thrown when negative usd balence: " << msg << std::endl;
        execption_thrown = true;
    }

    if (!execption_thrown)
    {
        std::cout << "Fail: Test exeption thrown when negative usd balence" << std::endl;
        has_passed = false;
    }

    /* Test MarketBot success */
    execption_thrown = false;
    try
    {
       MarketBot* p_market_bot = new MarketBot(p_sim, 10.0, 2000.0);
    }
    catch(const char* msg)
    {
        std::cout << "Fail: Test MarketBot success: " << msg << std::endl;
        execption_thrown = true;
        has_passed = false;
    }

    if (!execption_thrown)
    {
        std::cout << "Pass: Test MarketBot success" << std::endl;
    }

    /* Improvement: I would like to test that the timers are successfully created */

    return has_passed;
}

bool TestMarketBotRefreshMarket()
{
    IDvfSimulator* p_sim = DvfSimulator::Create();
    bool execption_thrown = false;
    bool has_passed = true;

    /* Init Market Bot */
    try
    {
        MarketBot* p_market_bot = new MarketBot(p_sim, 10.0, 2000.0);
    }
    catch(const char* msg)
    {
        std::cout << "Fail: Could not init MarketBot: " << msg << std::endl;
        execption_thrown = true;
    }

    if (!execption_thrown)
    {
        /* Test empty bid order map, and PlaceOrder fails  */
   
        /* Test empty ask order map, and PlaceOrder fails  */

        /* Test empty bid order map, and Check that the orders placed in the simulator are as expected  */
        /* For this we would need to mock the simulator and check the values passed PlaceOrder */
  
        /* Test empty ask order map, and Check that the orders placed in the simulator are as expected  */
        /* For this we would need to mock the simulator and check the values passed PlaceOrder */
  
        /* Test full bid order map, and check that the balence is ajusted accordingly and that the correct orders are cancelled */
        /* For this we would need to mock the simulator and check the values passed to CancelOrder */

        /* Test full ask order map, and check that the balence is ajusted accordingly and that the correct orders are cancelled */
        /* For this we would need to mock the simulator and check the values passed to CancelOrder */
    }
    else
    {
         has_passed = false;
    }

    return has_passed;
}

bool TestTimer()
{
    /* Test Creation and destruction stops threads */
    /* Improvement: this is currently not handled */

    /* Test thread behaviour when the function failes  */
    /* Improvement: this is currently not handled */

    /* Test that the function is called in the correct time */

    /* Test that the function is called multiple times until the thread is terminated */

    return true;
}