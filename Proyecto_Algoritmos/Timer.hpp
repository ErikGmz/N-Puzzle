#ifndef TIMER_HPP
#define TIMER_HPP

//---------Librerías---------
#include <ctime>

class Timer {
//-----------------Class Atributes----------------
private:
    clock_t start_time;
    clock_t final_time;
//------------------Class Methods-----------------
public:
    void start() { this->start_time = clock(); } //Se inicia el temporizador.
    void stop() { this->final_time = clock(); } //Se detiene el temporizador.
    clock_t getTime() { return (this->final_time - start_time); } //Se obtiene el tiempo.
};

#endif