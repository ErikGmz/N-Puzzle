#ifndef SISTEMA_METORD_HPP
#define SISTEMA_METORD_HPP
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
#include "Vector.hpp"
#include "Timer.hpp"


struct Metodo {
    string nombre;
    clock_t tiempoAse;
    clock_t tiempoAl;
    clock_t tiempoDes;
    long int C_Ase;
    long int C_Al;
    long int C_Des;
    long int M_Ase;
    long int M_Al;
    long int M_Des;
};

class Sistema {
    //-----------------Class Atributes---------------
private:
    Metodo metodos[7];
    Vector* vector;
    Timer timer;
    //-----------------Class Methods-----------------
public:
    Sistema();
    ~Sistema();
    void pantalla_Principal();
    void pantalla_Vectores();
    void pantalla_Ordenacion();
    void pantalla_StatusTiempo();
    void pantalla_StatusCalculos();
private:
    void printTitulo();
    void capturaDimVec();
    void statusBar(int);
    void ejecutaMetodos(int);
    void gotoxy(int,int);
};

#endif