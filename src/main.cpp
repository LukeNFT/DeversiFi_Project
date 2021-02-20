#include <memory>
#include "DvfSimulator.h"
#include "market_bot.hpp"

int main()
{
    IDvfSimulator* p_sim = DvfSimulator::Create();
#if 0
    auto ob = sim->GetOrderBook();

    double price = 1.0, amount = 1.2;
    IDvfSimulator::OrderID oid = 1;
    // ... decide price and amount
    sim->PlaceOrder(price, amount);
    sim->CancelOrder(oid);
#endif
    std::shared_ptr<MarketBot> p_market_bot = std::make_shared<MarketBot>(p_sim, 10.0, 2000.0);

    return true;
}