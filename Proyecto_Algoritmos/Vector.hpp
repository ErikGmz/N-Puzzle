#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
using namespace std;

class Vector {
    //-----------------Class Atributes---------------
private:
    int* elem;
    int n;
    long int C;
    long int  M;
    //-----------------Class Methods-----------------
public:
    Vector(int);
    Vector(Vector&);
    int length() { return this->n; }
    void printVector();
    void randomFill(int, int);
    void UpFill();
    void DownFill();
    Vector& insertionSort();
    Vector& selectionSort();
    Vector& bubbleSort();
    Vector& mergeSort();
    Vector& shellSort();
    Vector& quickSort();
    Vector& heapSort();
    long int getC() { return this->C; }
    long int getM() { return this->M; }
    ~Vector();
    //----------------Operator Methods---------------
    const Vector& operator=(const Vector&);
private:
    void merge(int*, int, int*, int, int*);
    void shiftRight(int*, int, int);
    void heapify(int*, int, int);
    //----------------Recursive Methods--------------
    void mergeSort(int*, int);
    void quickSort(int*, int, int);
};

#endif