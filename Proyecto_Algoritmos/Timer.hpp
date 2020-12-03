#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

class Timer {
private:
    clock_t start_time;
    clock_t final_time;
public:
    void start() { this->start_time = clock(); }
    void stop() { this->final_time = clock(); }
    clock_t getTime() { return (this->final_time - start_time); }
};

#endif