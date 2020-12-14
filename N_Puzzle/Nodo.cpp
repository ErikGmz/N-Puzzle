//-----Compilaci�n del archivo fuente-----//.
#ifndef Nodo_cpp
#define Nodo_cpp

//-----Librer�as-----//.
#include "Nodo.hpp"

//---Constructor y destructor---//.
//Constructor.
Nodo::Nodo(vector<vector<string>> &mat,int x,int y,int newX,int newY,int nivel,Nodo *padre) {
    this->padre = padre;
    this->mat = mat;
    this->swap(this->mat[x][y], this->mat[newX][newY]); //Movemos el espacio vacio en una posici�n.
    this->costo = 0; 
    this->nivel = nivel;  
    // Nuevas coordenadas del espacio en blanco. 
    this->x = newX; 
    this->y = newY; 
}

//---M�todos---//.
//Se intercambian los valores de la matriz.
void Nodo::swap(string &val,string &newVal) {
    string tempo = val;
    val = newVal;
    newVal = tempo;
    return;
}
#endif