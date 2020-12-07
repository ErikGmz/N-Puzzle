#include "Vector.hpp"

//-------------------------------------Class Public Methods----------------------------------------

Vector::Vector(int n = 0) { //Contructor con argumentos.
    this->n = n;
    this->elem = new int[this->n];
    this->C = 0;
    this->M = 0;
}

Vector::Vector(Vector& V) { //Constructor de copia.
    this->n = V.n;
    this->elem = new int[this->n];
    for (int i = 0; i < this->n; i++)
        this->elem[i] = V.elem[i];
    this->C = V.C;
    this->M = V.M;
}

void Vector::printVector() { //Imprime el vector.
    cout << "[ ";
    for (int i = 0; i < this->n; i++) {
        if (i < 10)
            cout << this->elem[i] << ", ";
        else {
            cout << "..., " << this->elem[this->n - 1] << ", ";
            break;
        }
    }
    cout << "\b\b ]" << endl;
    return;
}

void Vector::randomFill(int li, int ls) { //Llena aleatoriamente el vector.
    for (int i = 0; i < this->n; i++)
        this->elem[i] = li + rand() % ls;
    return;
}

void Vector::UpFill() { //Llena ascendentemente el vector.
    for (int i = 0; i < this->n; i++)
        this->elem[i] = i + 1;
    return;
}

void Vector::DownFill() { //Llena descendentemente el vector.
    int val = this->n + 1;
    for (int i = 0; i < this->n; i++)
        this->elem[i] = --val;
    return;
}

Vector& Vector::insertionSort() { //Metodo de ordenacion por insercion.
    Vector* vecOrd = new Vector(*this);
    int pos, temp;
    for (int i = 0; i < vecOrd->n; i++) {
        temp = vecOrd->elem[i];
        pos = i;
        while (pos > 0 && vecOrd->elem[pos - 1] > temp) {
            vecOrd->C++;
            vecOrd->elem[pos] = vecOrd->elem[pos - 1];
            vecOrd->M++;
            pos--;
        }
        vecOrd->C++;
        vecOrd->elem[pos] = temp;
    }
    return *vecOrd;
}

Vector& Vector::selectionSort() { //Metodo de ordenamiento por seleccion.
    Vector* vecOrd = new Vector(*this);
    int temp, min;
    for (int i = 0; i < vecOrd->n; i++) {
        min = i;
        for (int j = i + 1; j < vecOrd->n; j++) {
            if (vecOrd->elem[j] < vecOrd->elem[min])
                min = j;
            vecOrd->C++;
        }
        temp = vecOrd->elem[i];
        vecOrd->elem[i] = vecOrd->elem[min];
        vecOrd->elem[min] = temp;
        vecOrd->M++;
    }
    return *vecOrd;
}

Vector& Vector::bubbleSort() { //Metodo de ordenacion por intercalacion (Metodo burbuja).
    Vector* vecOrd = new Vector(*this);
    int temp;
    for (int i = 0; i < vecOrd->n; i++)
        for (int j = i; j < (vecOrd->n - 1); j++) {
            if (vecOrd->elem[j] > vecOrd->elem[j + 1]) {
                temp = vecOrd->elem[j];
                vecOrd->elem[j] = vecOrd->elem[j + 1];
                vecOrd->elem[j + 1] = temp;
                vecOrd->M++;
            }
            vecOrd->C++;
        }
    return *vecOrd;
}

Vector& Vector::mergeSort() { //Metodo de ordenacion por mezcla (mergeSort).
    Vector* vecOrd = new Vector(*this);
    vecOrd->mergeSort(vecOrd->elem, vecOrd->n);
    return *vecOrd;
}

Vector& Vector::shellSort() { //Metodo de ordenacion Shell (shellSort).
    Vector* vecOrd = new Vector(*this);
    int temp;
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < vecOrd->n; i++) {
            temp = vecOrd->elem[i];
            int j;
            for (j = i; j >= gap && vecOrd->elem[j - gap] > temp; j -= gap) {
                vecOrd->C++;
                vecOrd->elem[j] = vecOrd->elem[j - gap];
            }
            vecOrd->C++;
            vecOrd->elem[j] = temp;
            vecOrd->M++;
        }
    return *vecOrd;
}

Vector& Vector::quickSort() { //Metodo de ordenacion rapido (quickSort).
    Vector* vecOrd = new Vector(*this);
    vecOrd->quickSort(vecOrd->elem, 0, vecOrd->n - 1);
    return *vecOrd;
}

Vector& Vector::heapSort() { //Metodo de ordenacion por monticulo (heapSort).
    Vector* vecOrd = new Vector(*this);
    vecOrd->heapify(vecOrd->elem, 0, vecOrd->n - 1); //Colocamos el elemento mayor en la posicion 0.
    int sup = vecOrd->n - 1;
    while (sup > 0) {
        vecOrd->C++;
        //Intercambiamos el elemento mayor con el elemento vecOrd[sup].
        int tempo = vecOrd->elem[sup];
        vecOrd->elem[sup] = vecOrd->elem[0];
        vecOrd->elem[0] = tempo;
        vecOrd->M++;
        --sup;
        vecOrd->shiftRight(vecOrd->elem, 0, sup); //Aseguramos la propiedad del heap en los elementos.
    }
    vecOrd->C++;
    return *vecOrd;
}

Vector::~Vector() { //Destructor de clase.
    delete[] this->elem;
}

//-----------------------------------Class Operator Methods----------------------------------------

const Vector& Vector::operator=(const Vector& V) { //Sobrecarga del operador de asignaci�n.
    if (this != &V) {
        delete this->elem;
        this->n = V.n;
        this->elem = new int[this->n];
        for (int i = 0; i < this->n; i++)
            this->elem[i] = V.elem[i];
        this->C = V.C;
        this->M = V.M;
    }
    return *this;
}

//------------------------------------Class Private Methods----------------------------------------

void Vector::merge(int* izq, int nIzq, int* der, int nDer, int* vec) { //Junta dos vectores previamente ordenados.
    int i = 0, j = 0, k = 0;
    while (i < nIzq && j < nDer) {
        if (izq[i] < der[j])
            vec[k] = izq[i++];
        else
            vec[k] = der[j++];
        this->C++;
        this->M++;
        k++;
    }
    while (i < nIzq)
        vec[k++] = izq[i++];
    while (j < nDer)
        vec[k++] = der[j++];
    return;
}


void Vector::shiftRight(int* vec, int inf, int sup) { //Verifica que se cumpla la propiedad del mont�culo.
    int raiz = inf;
    while ((raiz * 2) + 1 <= sup) {
        int hijoIzq = (raiz * 2) + 1;
        int hijoDer = hijoIzq + 1;
        int swapIdx = raiz;
        if (vec[swapIdx] < vec[hijoIzq]) //Revisamos si la raiz es menor que el hijo izquierdo.
            swapIdx = hijoIzq;
        if ((hijoDer <= sup) && (vec[swapIdx] < vec[hijoDer])) //Si el hijo derecho existe, revisamos si es menor que la raiz local.
            swapIdx = hijoDer;
        if (swapIdx != raiz) { //Hacemos que el elemento mas grande de la raiz sea la nueva raiz .
            int tempo = vec[raiz];
            vec[raiz] = vec[swapIdx];
            vec[swapIdx] = tempo;
            raiz = swapIdx;
        }
        else
            break;
    }
    return;
}

void Vector::heapify(int* vec, int inf, int sup) { //Se insertan los valores en el mont�culo.
    int midIdx = (sup - inf - 1) / 2;
    while (midIdx >= 0) {
        shiftRight(vec, midIdx, sup);
        --midIdx;
    }
    return;
}

//-----------------------------------Class Recursive Methods---------------------------------------

void Vector::mergeSort(int* vec, int n) { //Metodo de ordenacion por mezcla (MergeSort); solucion recursiva.
    if (n == 1)
        return;
    int mitad = n / 2;
    int* izq = new int[mitad];
    int* der = new int[n - mitad];
    for (int i = 0; i < mitad; i++)
        izq[i] = vec[i];
    for (int i = 0, j = mitad; j < n; i++, j++)
        der[i] = vec[j];
    this->mergeSort(izq, mitad);
    this->mergeSort(der, n - mitad);
    this->merge(izq, mitad, der, n - mitad, vec);
    delete[] izq;
    delete[] der;
}

void Vector::quickSort(int* vec, int inf, int sup) { //Metodo de ordenacion rapido (quickSort); solucion recursiva.
    int i = inf, j = sup, pivote = vec[(inf + sup) / 2], temp;
    do {
        while (vec[i] < pivote) i++;
        while (vec[j] > pivote) j--;
        if (i <= j) {
            temp = vec[j];
            vec[j] = vec[i];
            vec[i] = temp;
            i++;
            j--;
            this->M++;
        }
        this->C++;
    } while (i <= j);
    if (inf < j) this->quickSort(vec, inf, j);
    if (sup > i) this->quickSort(vec, i, sup);
}