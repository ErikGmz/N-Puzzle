#ifndef SISTEMA_METORD_HPP
#define SISTEMA_METORD_HPP

//---------Librer�as---------
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
#include "Vector.hpp"
#include "Timer.hpp"

//--------Estructuras de datos---------
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
    Sistema(); //Constructor predeterminado.
    ~Sistema(); //Destructor de clase.
    void pantalla_Principal(); // Se imprime la pantalla principal.
    void pantalla_Vectores(); //Se imprime la pantalla que muestra los vectores generados.
    void pantalla_Ordenacion(); //Se imprime la pantalla de ordenamiento de vectores.
    void pantalla_StatusTiempo(); //Se imprime un an�lisis de los tiempos de ejecuci�n de cada m�todo ordenaci�n.
    void pantalla_StatusCalculos(); //Se imprime un an�lisis de los calculos realizados por cada m�todo de ordenaci�n.
private:
    void printTitulo(); //Se imprime el titulo.
    void capturaDimVec(); //Se genera la pantalla para solicitud de la dimensi�n del vector de prueba.
    void statusBar(int); //Imprime la barra de estado de la ordenaci�n de vetores.
    void ejecutaMetodos(int); //Se ejecutan todos los m�todos de ordenaci�n.
    void gotoxy(int,int); //Funci�n gotoxy para dar est�tica al programa.
};

#endif