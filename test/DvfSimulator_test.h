#ifndef DVF_SIM_HPP
#define DVF_SIM_HPP

#include "DvfSimulator.h"

class DvfSimulatorTest : public IDvfSimulator
{
public:
    static IDvfSimulator* Create() noexcept
    {
        return static_cast<IDvfSimulator*>(new DvfSimulatorTest());
    }
 
    virtual OrderBook GetOrderBook() noexcept override {return ob;};

    virtual std::optional<OrderID> PlaceOrder(double price, double amount) noexcept override {return std::optional<IDvfSimulator::OrderID>{123};};

    virtual bool CancelOrder(OrderID oid) noexcept override {return true;};

    OrderBook ob;
};

#endif