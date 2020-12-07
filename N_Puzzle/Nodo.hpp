#ifndef NODO_HPP
#define NODO_HPP
#include "Allegro.hpp"

class Nodo {
public:
    Nodo *padre;
    vector<vector<string>> mat;
    int x; //Coordenada x del espacio vacio.
    int y; //Coordenada y del espacio vacio.
    int costo; //Numero de fichas fuera de su lugar.
    int nivel; //Nivel de profundidad del nodo (numero de movimientos para la solución).
    Nodo(vector<vector<string>> &,int,int,int,int,int,Nodo *);
    ~Nodo();
private:
    void swap(string &,string &); //Se intercambian los valores de la matriz.
};

#endif