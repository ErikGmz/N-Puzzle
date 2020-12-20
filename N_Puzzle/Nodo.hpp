//-----Compilación de la cabecera-----//.
#ifndef Nodo_hpp
#define Nodo_hpp

//-----Librerías-----//.
#include "Allegro.hpp"

//-----Estructuras-----//.
struct Espacio {
    int x;
    int y;
};

//-----Clase 'Nodo'-----//.
class Nodo {
public:
    //---Atributos---//.
    Nodo *padre;
    vector<vector<string>> mat;
    Espacio espacio_vacio; // Coordenadas del espacio vacio del puzzle.
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