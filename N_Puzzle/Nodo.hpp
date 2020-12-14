//-----Compilación de la cabecera-----//.
#ifndef Nodo_hpp
#define Nodo_hpp

//-----Librerías-----//.
#include "Allegro.hpp"

//-----Clase 'Nodo'-----//.
class Nodo {
public:
    //---Atributos---//.
    Nodo *padre;
    vector<vector<string>> mat;
    int x; //Coordenada x del espacio vacio.
    int y; //Coordenada y del espacio vacio.
    int costo; //Numero de fichas fuera de su lugar.
    int nivel; //Nivel de profundidad del nodo (numero de movimientos para la solución).

    //---Constructor y destructor---//.
    Nodo(vector<vector<string>> &, int, int, int, int, int, Nodo *); //Constructor.
    ~Nodo(); //Destructor.
private:
    //---Métodos---//.
    void swap(string &,string &); //Se intercambian los valores de la matriz.
};

#endif