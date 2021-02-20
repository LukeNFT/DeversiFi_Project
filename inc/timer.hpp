#ifndef TIMER_HPP
#define TIMER_HPP

#include <functional>
#include <chrono>
#include <future>

class Timer
{
    public:
        Timer(unsigned int time_to_execute, std::function<void(void)> func_to_execute)
        {
            m_timer_thread = std::thread([this, time_to_execute, func_to_execute]()
            {
                while(true)
                {
                    func_to_execute();                   
                    std::this_thread::sleep_for(
                    std::chrono::milliseconds(time_to_execute*1000));
                }
            });
        }
        ~Timer()
        {
            m_timer_thread.join();
        }
    private:
        std::thread m_timer_thread;
};
#endif