#include "Sistema.hpp"

//-------------------------------------Class Public Methods----------------------------------------

Sistema::Sistema() {
    this->vector = NULL;
}

Sistema::~Sistema() {
    delete this->vector;
}

void Sistema::pantalla_Principal() {
    this->printTitulo();
    this->capturaDimVec();
    return;
}

void Sistema::pantalla_Vectores() {
    system("cls");
    this->printTitulo();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "[Vectores Generados]\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\t\t\t   [Vector Ascendente]\n" << endl;
    this->vector->UpFill();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "   ";
    this->vector->printVector();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\n\t\t\t   [Vector Aleatorio]\n" << endl;
    this->vector->randomFill(1, this->vector->length());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "   ";
    this->vector->printVector();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\n\t\t\t   [Vector Descendente]\n" << endl;
    this->vector->DownFill();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "   ";
    this->vector->printVector();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "\n\n\n----Presone una tecla para iniciar el ordenamiento de los vectores---" << endl;
    cin.get();
    return;
}

void Sistema::pantalla_Ordenacion() {
    system("cls");
    this->printTitulo();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\n\n\n\t\t\t   ORDENANDO VECTORES\n" << endl;
    for (size_t i = 0; i < 7; i++)
        this->ejecutaMetodos(i);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\n\t\t\t     VECTORES ORDENADOS\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "\n\n\n----Presone una tecla para visualizar el analisis de tiempos de ejecucion---" << endl;
    cin.get();
    return;
}

void Sistema::pantalla_StatusTiempo() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\t\tTABLA COMPARATIVA DE TIEMPOS DE EJECUCION\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\tMETODO\t\tORDENADO\tDESORDENADO\tORDEN INVERSO\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    for (int i = 0; i < 7; i++)
        cout << this->metodos[i].nombre << "\t\t" << this->metodos[i].tiempoAse << " ms\t\t" << this->metodos[i].tiempoAl << " ms\t\t" << this->metodos[i].tiempoDes << " ms \n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "----Presone una tecla para visualizar el analisis de calculos realizados---" << endl;
    cin.get();
    return;
}

void Sistema::pantalla_StatusCalculos() {
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\t\tTABLA COMPARATIVA DE CALCULOS REALIZADOS\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\tMETODO\t\tORDENADO\tDESORDENADO\tORDEN INVERSO\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    for (int i = 0, y = 0; i < 7; i++, y += 3) {
        cout << this->metodos[i].nombre << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        this->gotoxy(15, 4 + y);
        cout << "COMP";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        this->gotoxy(24, 4 + y);
        cout << this->metodos[i].C_Ase;
        this->gotoxy(40, 4 + y); 
        cout << this->metodos[i].C_Al;
        this->gotoxy(56, 4 + y);
        cout << this->metodos[i].C_Des << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        this->gotoxy(15, 5 + y);
        cout << "MOV";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        this->gotoxy(24, 5 + y);
        cout << this->metodos[i].M_Ase;
        this->gotoxy(40, 5 + y);
        cout << this->metodos[i].M_Al;
        this->gotoxy(56, 5 + y);
        cout << this->metodos[i].M_Des << endl << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "\t----Presone una tecla para finalizar el programa---" << endl;
    cin.get();
    return;
}

//------------------------------------Class Private Methods----------------------------------------

void Sistema::printTitulo() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\t\t\tANALISIS DE EFICIENCIA DE LOS " << endl;
    cout << "\t\t\t   METODOS DE ORDENACION\n" << endl;
    return;
}

void Sistema::capturaDimVec() {
    int n;
    do {
        system("cls");
        this->printTitulo();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "Longitud del vector a ordenar: ";
        cin >> n;
        cin.ignore();
    } while (n < 1 || n > 20000);
    this->vector = new Vector(n);
    return;
}

void Sistema::statusBar(int n) {
    system("cls");
    this->printTitulo();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\n\n\n\t\t\t    ORDENANDO VECTORES\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "\t\t\t       " << this->metodos[n].nombre << endl << endl;
    n *= 7;
    cout << "\t\t[";
    for (int i = 0; i < 42; i++) {
        if (i < n)
            cout << "=";
        else
            cout << "-";
    }
    cout << "]" << endl;
    return;
}

void Sistema::ejecutaMetodos(int i) {
    Vector vecOrd(*(this->vector));
    switch (i) {
    case 0:
        this->metodos[i].nombre = "Insertion Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->insertionSort();
        this->timer.stop();
        this->metodos[i].tiempoAse = this->timer.getTime();
        this->metodos[i].C_Ase = vecOrd.getC();
        this->metodos[i].M_Ase = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->insertionSort();
        this->timer.stop();
        this->metodos[i].tiempoAl = this->timer.getTime();
        this->metodos[i].C_Al = vecOrd.getC();
        this->metodos[i].M_Al = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->insertionSort();
        this->timer.stop();
        this->metodos[i].tiempoDes = this->timer.getTime();
        this->metodos[i].C_Des = vecOrd.getC();
        this->metodos[i].M_Des = vecOrd.getM();
        break;
    case 1:
        this->metodos[i].nombre = "Selection Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->selectionSort();
        this->timer.stop();
        this->metodos[i].tiempoAse = this->timer.getTime();
        this->metodos[i].C_Ase = vecOrd.getC();
        this->metodos[i].M_Ase = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->selectionSort();
        this->timer.stop();
        this->metodos[i].tiempoAl = this->timer.getTime();
        this->metodos[i].C_Al = vecOrd.getC();
        this->metodos[i].M_Al = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->selectionSort();
        this->timer.stop();
        this->metodos[i].tiempoDes = this->timer.getTime();
        this->metodos[i].C_Des = vecOrd.getC();
        this->metodos[i].M_Des = vecOrd.getM();
        break;
    case 2:
        this->metodos[i].nombre = "Bubble Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->bubbleSort();
        this->timer.stop();
        this->metodos[i].tiempoAse = this->timer.getTime();
        this->metodos[i].C_Ase = vecOrd.getC();
        this->metodos[i].M_Ase = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->bubbleSort();
        this->timer.stop();
        this->metodos[i].tiempoAl = this->timer.getTime();
        this->metodos[i].C_Al = vecOrd.getC();
        this->metodos[i].M_Al = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->bubbleSort();
        this->timer.stop();
        this->metodos[i].tiempoDes = this->timer.getTime();
        this->metodos[i].C_Des = vecOrd.getC();
        this->metodos[i].M_Des = vecOrd.getM();
        break;
    case 3:
        this->metodos[i].nombre = "Merge Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->mergeSort();
        this->timer.stop();
        this->metodos[i].tiempoAse = this->timer.getTime();
        this->metodos[i].C_Ase = vecOrd.getC();
        this->metodos[i].M_Ase = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->mergeSort();
        this->timer.stop();
        this->metodos[i].tiempoAl = this->timer.getTime();
        this->metodos[i].C_Al = vecOrd.getC();
        this->metodos[i].M_Al = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->mergeSort();
        this->timer.stop();
        this->metodos[i].tiempoDes = this->timer.getTime();
        this->metodos[i].C_Des = vecOrd.getC();
        this->metodos[i].M_Des = vecOrd.getM();
        break;
    case 4:
        this->metodos[i].nombre = "Shell Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->shellSort();
        this->timer.stop();
        this->metodos[i].tiempoAse = this->timer.getTime();
        this->metodos[i].C_Ase = vecOrd.getC();
        this->metodos[i].M_Ase = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->shellSort();
        this->timer.stop();
        this->metodos[i].tiempoAl = this->timer.getTime();
        this->metodos[i].C_Al = vecOrd.getC();
        this->metodos[i].M_Al = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->shellSort();
        this->timer.stop();
        this->metodos[i].tiempoDes = this->timer.getTime();
        this->metodos[i].C_Des = vecOrd.getC();
        this->metodos[i].M_Des = vecOrd.getM();
        break;
    case 5:
        this->metodos[i].nombre = "Quick Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->quickSort();
        this->timer.stop();
        this->metodos[i].tiempoAse = this->timer.getTime();
        this->metodos[i].C_Ase = vecOrd.getC();
        this->metodos[i].M_Ase = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->quickSort();
        this->timer.stop();
        this->metodos[i].tiempoAl = this->timer.getTime();
        this->metodos[i].C_Al = vecOrd.getC();
        this->metodos[i].M_Al = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->quickSort();
        this->timer.stop();
        this->metodos[i].tiempoDes = this->timer.getTime();
        this->metodos[i].C_Des = vecOrd.getC();
        this->metodos[i].M_Des = vecOrd.getM();
        break;
    case 6:
        this->metodos[i].nombre = "Heap Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->heapSort();
        this->timer.stop();
        this->metodos[i].tiempoAse = this->timer.getTime();
        this->metodos[i].C_Ase = vecOrd.getC();
        this->metodos[i].M_Ase = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->heapSort();
        this->timer.stop();
        this->metodos[i].tiempoAl = this->timer.getTime();
        this->metodos[i].C_Al = vecOrd.getC();
        this->metodos[i].M_Al = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->heapSort();
        this->timer.stop();
        this->metodos[i].tiempoDes = this->timer.getTime();
        this->metodos[i].C_Des = vecOrd.getC();
        this->metodos[i].M_Des = vecOrd.getM();
        break;
    }
    return;
}

void Sistema::gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
    return;
}