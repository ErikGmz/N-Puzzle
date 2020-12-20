#include "Vector.hpp"

//-------------------------------------Class Public Methods----------------------------------------

Vector::Vector(int longitud_vector = 0) { //Contructor con argumentos.
    this->longitud_vector = longitud_vector;
    this->elementos_vector = new int[this->longitud_vector];
    this->comparaciones = 0;
    this->permutaciones = 0;
}

Vector::Vector(Vector& V) { //Constructor de copia.
    this->longitud_vector = V.longitud_vector;
    this->elementos_vector = new int[this->longitud_vector];
    for (int i = 0; i < this->longitud_vector; i++)
        this->elementos_vector[i] = V.elementos_vector[i];
    this->comparaciones = V.comparaciones;
    this->permutaciones = V.permutaciones;
}

void Vector::printVector() { //Imprime el vector.
    cout << "[ ";
    for (int i = 0; i < this->longitud_vector; i++) {
        if (i < 10)
            cout << this->elementos_vector[i] << ", ";
        else {
            cout << "..., " << this->elementos_vector[this->longitud_vector - 1] << ", ";
            break;
        }
    }
    cout << "\b\b ]" << endl;
    return;
}

void Vector::randomFill(int li, int ls) { //Llena aleatoriamente el vector.
    for (int i = 0; i < this->longitud_vector; i++)
        this->elementos_vector[i] = li + rand() % ls;
    return;
}

void Vector::UpFill() { //Llena ascendentemente el vector.
    for (int i = 0; i < this->longitud_vector; i++)
        this->elementos_vector[i] = i + 1;
    return;
}

void Vector::DownFill() { //Llena descendentemente el vector.
    int val = this->longitud_vector + 1;
    for (int i = 0; i < this->longitud_vector; i++)
        this->elementos_vector[i] = --val;
    return;
}

Vector& Vector::insertionSort() { //Metodo de ordenacion por insercion.
    Vector* vector_ordenamiento = new Vector(*this);
    int pos, tempo;
    for (int i = 0; i < vector_ordenamiento->longitud_vector; i++) {
        tempo = vector_ordenamiento->elementos_vector[i];
        pos = i;
        while (pos > 0 && vector_ordenamiento->elementos_vector[pos - 1] > tempo) {
            vector_ordenamiento->comparaciones++;
            vector_ordenamiento->elementos_vector[pos] = vector_ordenamiento->elementos_vector[pos - 1];
            vector_ordenamiento->permutaciones++;
            pos--;
        }
        vector_ordenamiento->comparaciones++;
        vector_ordenamiento->elementos_vector[pos] = tempo;
    }
    return *vector_ordenamiento;
}

Vector& Vector::selectionSort() { //Metodo de ordenamiento por seleccion.
    Vector* vector_ordenamiento = new Vector(*this);
    int tempo, min;
    for (int i = 0; i < vector_ordenamiento->longitud_vector; i++) {
        min = i;
        for (int j = i + 1; j < vector_ordenamiento->longitud_vector; j++) {
            if (vector_ordenamiento->elementos_vector[j] < vector_ordenamiento->elementos_vector[min])
                min = j;
            vector_ordenamiento->comparaciones++;
        }
        tempo = vector_ordenamiento->elementos_vector[i];
        vector_ordenamiento->elementos_vector[i] = vector_ordenamiento->elementos_vector[min];
        vector_ordenamiento->elementos_vector[min] = tempo;
        vector_ordenamiento->permutaciones++;
    }
    return *vector_ordenamiento;
}

Vector& Vector::bubbleSort() { //Metodo de ordenacion por intercalacion (Metodo burbuja).
    Vector* vector_ordenamiento = new Vector(*this);
    int tempo;
    for (int i = 0; i < vector_ordenamiento->longitud_vector; i++)
        for (int j = i; j < (vector_ordenamiento->longitud_vector - 1); j++) {
            if (vector_ordenamiento->elementos_vector[j] > vector_ordenamiento->elementos_vector[j + 1]) {
                tempo = vector_ordenamiento->elementos_vector[j];
                vector_ordenamiento->elementos_vector[j] = vector_ordenamiento->elementos_vector[j + 1];
                vector_ordenamiento->elementos_vector[j + 1] = tempo;
                vector_ordenamiento->permutaciones++;
            }
            vector_ordenamiento->comparaciones++;
        }
    return *vector_ordenamiento;
}

Vector& Vector::mergeSort() { //Metodo de ordenacion por mezcla (mergeSort).
    Vector* vector_ordenamiento = new Vector(*this);
    vector_ordenamiento->mergeSort(vector_ordenamiento->elementos_vector, vector_ordenamiento->longitud_vector);
    return *vector_ordenamiento;
}

Vector& Vector::shellSort() { //Metodo de ordenacion Shell (shellSort).
    Vector* vector_ordenamiento = new Vector(*this);
    int tempo;
    for (int gap = longitud_vector / 2; gap > 0; gap /= 2)
        for (int i = gap; i < vector_ordenamiento->longitud_vector; i++) {
            tempo = vector_ordenamiento->elementos_vector[i];
            int j;
            for (j = i; j >= gap && vector_ordenamiento->elementos_vector[j - gap] > tempo; j -= gap) {
                vector_ordenamiento->comparaciones++;
                vector_ordenamiento->elementos_vector[j] = vector_ordenamiento->elementos_vector[j - gap];
            }
            vector_ordenamiento->comparaciones++;
            vector_ordenamiento->elementos_vector[j] = tempo;
            vector_ordenamiento->permutaciones++;
        }
    return *vector_ordenamiento;
}

Vector& Vector::quickSort() { //Metodo de ordenacion rapido (quickSort).
    Vector* vector_ordenamiento = new Vector(*this);
    vector_ordenamiento->quickSort(vector_ordenamiento->elementos_vector, 0, vector_ordenamiento->longitud_vector - 1);
    return *vector_ordenamiento;
}

Vector& Vector::heapSort() { //Metodo de ordenacion por monticulo (heapSort).
    Vector* vector_ordenamiento = new Vector(*this);
    vector_ordenamiento->heapify(vector_ordenamiento->elementos_vector, 0, vector_ordenamiento->longitud_vector - 1); //Colocamos el elemento mayor en la posicion 0.
    int sup = vector_ordenamiento->longitud_vector - 1;
    while (sup > 0) {
        vector_ordenamiento->comparaciones++;
        //Intercambiamos el elemento mayor con el elemento vecOrd[sup].
        int tempo = vector_ordenamiento->elementos_vector[sup];
        vector_ordenamiento->elementos_vector[sup] = vector_ordenamiento->elementos_vector[0];
        vector_ordenamiento->elementos_vector[0] = tempo;
        vector_ordenamiento->permutaciones++;
        --sup;
        vector_ordenamiento->shiftRight(vector_ordenamiento->elementos_vector, 0, sup); //Aseguramos la propiedad del heap en los elementos.
    }
    vector_ordenamiento->comparaciones++;
    return *vector_ordenamiento;
}

Vector::~Vector() { //Destructor de clase.
    delete [] this->elementos_vector;
}

//-----------------------------------Class Operator Methods----------------------------------------

const Vector& Vector::operator=(const Vector& V) { //Sobrecarga del operador de asignaci�n.
    if (this != &V) {
        delete this->elementos_vector;
        this->longitud_vector = V.longitud_vector;
        this->elementos_vector = new int[this->longitud_vector];
        for (int i = 0; i < this->longitud_vector; i++)
            this->elementos_vector[i] = V.elementos_vector[i];
        this->comparaciones = V.comparaciones;
        this->permutaciones = V.permutaciones;
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
        this->comparaciones++;
        this->permutaciones++;
        k++;
    }
    while (i < nIzq)
        vec[k++] = izq[i++];
    while (j < nDer)
        vec[k++] = der[j++];
    return;
}


void Vector::shiftRight(int* vec, int inferior, int superior) { //Verifica que se cumpla la propiedad del mont�culo.
    int raiz = inferior;
    while ((raiz * 2) + 1 <= superior) {
        int hijoIzq = (raiz * 2) + 1;
        int hijoDer = hijoIzq + 1;
        int swapIdx = raiz;
        if (vec[swapIdx] < vec[hijoIzq]) //Revisamos si la raiz es menor que el hijo izquierdo.
            swapIdx = hijoIzq;
        if ((hijoDer <= superior) && (vec[swapIdx] < vec[hijoDer])) //Si el hijo derecho existe, revisamos si es menor que la raiz local.
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

void Vector::heapify(int* vec, int inferior, int superior) { //Se insertan los valores en el mont�culo.
    int midIdx = (superior - inferior - 1) / 2;
    while (midIdx >= 0) {
        shiftRight(vec, midIdx, superior);
        --midIdx;
    }
    return;
}

//-----------------------------------Class Recursive Methods---------------------------------------

void Vector::mergeSort(int* vec, int longitud_vector) { //Metodo de ordenacion por mezcla (MergeSort); solucion recursiva.
    if (longitud_vector == 1)
        return;
    int mitad = longitud_vector / 2;
    int* izq = new int[mitad];
    int* der = new int[longitud_vector - mitad];
    for (int i = 0; i < mitad; i++)
        izq[i] = vec[i];
    for (int i = 0, j = mitad; j < longitud_vector; i++, j++)
        der[i] = vec[j];
    this->mergeSort(izq, mitad);
    this->mergeSort(der, longitud_vector - mitad);
    this->merge(izq, mitad, der, longitud_vector - mitad, vec);
    delete[] izq;
    delete[] der;
}

void Vector::quickSort(int* vec, int inferior, int superior) { //Metodo de ordenacion rapido (quickSort); solucion recursiva.
    int i = inferior, j = superior, pivote = vec[(inferior + superior) / 2], tempo;
    do {
        while (vec[i] < pivote) i++;
        while (vec[j] > pivote) j--;
        if (i <= j) {
            tempo = vec[j];
            vec[j] = vec[i];
            vec[i] = tempo;
            i++;
            j--;
            this->permutaciones++;
        }
        this->comparaciones++;
    } while (i <= j);
    if (inferior < j) this->quickSort(vec, inferior, j);
    if (superior > i) this->quickSort(vec, i, superior);
}