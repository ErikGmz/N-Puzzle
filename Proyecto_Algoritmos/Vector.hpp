#ifndef VECTOR_HPP
#define VECTOR_HPP

//---------Librer�as---------
#include <iostream>
using namespace std;

class Vector {
    //-----------------Class Atributes---------------
private:
    int* elementos_vector;
    int longitud_vector;
    long int comparaciones; //Comparaciones realizados por el m�todo de ordenamiento.
    long int  permutaciones; //Movimientos o permutaciones relizadas por el algoritmo de ordenamiento.
    //-----------------Class Methods-----------------
public:
    Vector(int); //Contructor con argumentos.
    Vector(Vector&); //Constructor de copia.
    int length() { return this->longitud_vector; } //Devuelve la longitud del vector.
    void printVector(); //Imprime el vector.
    void randomFill(int, int); //Llena aleatoriamente el vector.
    void UpFill(); //Llena ascendentemente el vector.
    void DownFill(); //Llena descendentemente el vector.
    Vector& insertionSort(); //M�todo de ordenci�n por inserci�n.
    Vector& selectionSort(); //M�todo de ordenci�n por selecci�n.
    Vector& bubbleSort(); //M�todo de ordenci�n por intercalaci�n (burbuja).
    Vector& mergeSort(); //M�todo de ordenci�n por mezcla.
    Vector& shellSort(); //M�todo de ordenci�n ShellSort.
    Vector& quickSort(); //M�todo de ordenci�n quicksort.
    Vector& heapSort(); //M�todo de ordenci�n por mont�culos (heapsort).
    long int getC() { return this->comparaciones; } //Devuelve el n�mero de comparaciones realizadas.
    long int getM() { return this->permutaciones; } //Devuelve el n�mero de permutaciones realizadas.
    ~Vector(); //Destructor de clase.
    //----------------Operator Methods---------------
    const Vector& operator=(const Vector&); //Sobrecarga del operador de asignaci�n.
private:
    void merge(int*, int, int*, int, int*); //Junta dos vectores previamente ordenados.
    void shiftRight(int*, int, int); //Verifica que se cumpla la propiedad del mont�culo.
    void heapify(int*, int, int); //Se insertan los valores en el mont�culo.
    //----------------Recursive Methods--------------
    void mergeSort(int*, int); //M�todo de ordenci�n por mezcla (Soluci�n recursiva).
    void quickSort(int*, int, int); //M�todo de ordenci�n quicksort (Soluci�n recursiva).
};

#endif