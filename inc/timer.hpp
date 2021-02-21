#ifndef TIMER_HPP
#define TIMER_HPP

#include <atomic>
#include <iostream>
#include <functional>
#include <chrono>
#include <future>

/* A simple Timer class that executes a function at given intervals */
class Timer
{
    public:
        Timer(unsigned int time_to_execute, std::function<void(void)> func_to_execute)
        {
            /* Start thread to execute function  */
            m_timer_thread = std::thread([this, time_to_execute, func_to_execute]()
            {
                while(true)
                {
                    try
                    {
                        func_to_execute();         
                    }
                    catch(const std::exception& e)
                    {
                        /* Improvement: Decide what to do on error */
                        std::cout << "Executable function failed: " << e.what();
                    }

                    std::this_thread::sleep_for(
                    std::chrono::milliseconds(time_to_execute*1000));
                }
            });
        }
        ~Timer()
        {
            /* Improvement: Need to teardown cleanly */
        }
    private:
        std::thread m_timer_thread;
};
#endif