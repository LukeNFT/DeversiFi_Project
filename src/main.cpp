#include "DvfSimulator.h"

int main()
{
    auto* sim = DvfSimulator::Create();
    
    auto ob = sim->GetOrderBook();

    double price = 1.0, amount = 1.2;
    IDvfSimulator::OrderID oid = 1;
    // ... decide price and amount
    sim->PlaceOrder(price, amount);
    sim->CancelOrder(oid);

    return true;
}