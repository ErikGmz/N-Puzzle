#include "Sistema.hpp"

//-------------------------------------Class Public Methods----------------------------------------

Sistema::Sistema() { //Constructor predeterminado.
    this->vector = NULL;
}

Sistema::~Sistema() { //Destructor de clase.
    delete this->vector;
}

void Sistema::pantalla_Principal() { // Se imprime la pantalla principal.
    this->printTitulo();
    this->capturaDimVec();
    return;
}

void Sistema::pantalla_Vectores() { //Se imprime la pantalla que muestra los vectores generados.
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

void Sistema::pantalla_Ordenacion() { //Se imprime la pantalla de ordenamiento de vectores.
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

void Sistema::pantalla_StatusTiempo() { //Se imprime un an�lisis de los tiempos de ejecuci�n de cada m�todo ordenaci�n.
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "\t\tTABLA COMPARATIVA DE TIEMPOS DE EJECUCION\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\tMETODO\t\tORDENADO\tDESORDENADO\tORDEN INVERSO\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    for (int i = 0; i < 7; i++)
        cout << this->metodos[i].nombre << "\t\t" << this->metodos[i].tiempo_ascendente << " ms\t\t" << this->metodos[i].tiempo_aleatorio << " ms\t\t" << this->metodos[i].tiempo_descendente << " ms \n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "----Presone una tecla para visualizar el analisis de calculos realizados---" << endl;
    cin.get();
    return;
}

void Sistema::pantalla_StatusCalculos() { //Se imprime un an�lisis de los calculos realizados por cada m�todo de ordenaci�n.
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
        cout << this->metodos[i].comp_ascendente;
        this->gotoxy(40, 4 + y); 
        cout << this->metodos[i].comp_aleatorio;
        this->gotoxy(56, 4 + y);
        cout << this->metodos[i].comp_descendente << endl << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        this->gotoxy(15, 5 + y);
        cout << "MOV";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        this->gotoxy(24, 5 + y);
        cout << this->metodos[i].permut_ascendente;
        this->gotoxy(40, 5 + y);
        cout << this->metodos[i].permut_aleatorio;
        this->gotoxy(56, 5 + y);
        cout << this->metodos[i].permut_descendente << endl << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    this->gotoxy(35, 25);
    cout << "COMP = Comparaciones realizadas";
    this->gotoxy(35, 26);
    cout << "MOV  = Movimientos Realizados" << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout << "\t----Presone una tecla para finalizar el programa---" << endl;
    cin.get();
    return;
}

//------------------------------------Class Private Methods----------------------------------------

void Sistema::printTitulo() { //Se imprime el titulo.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\t\t\tANALISIS DE EFICIENCIA DE LOS " << endl;
    cout << "\t\t\t   METODOS DE ORDENACION\n" << endl;
    return;
}

void Sistema::capturaDimVec() { //Se genera la pantalla para solicitud de la dimensi�n del vector de prueba.
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

void Sistema::statusBar(int n) { //Imprime la barra de estado de la ordenaci�n de vetores.
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

void Sistema::ejecutaMetodos(int i) { //Se ejecutan todos los m�todos de ordenaci�n.
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
        this->metodos[i].tiempo_ascendente = this->timer.getTime();
        this->metodos[i].comp_ascendente = vecOrd.getC();
        this->metodos[i].permut_ascendente = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->insertionSort();
        this->timer.stop();
        this->metodos[i].tiempo_aleatorio = this->timer.getTime();
        this->metodos[i].comp_aleatorio = vecOrd.getC();
        this->metodos[i].permut_aleatorio = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->insertionSort();
        this->timer.stop();
        this->metodos[i].tiempo_descendente = this->timer.getTime();
        this->metodos[i].comp_descendente = vecOrd.getC();
        this->metodos[i].permut_descendente = vecOrd.getM();
        break;
    case 1:
        this->metodos[i].nombre = "Selection Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->selectionSort();
        this->timer.stop();
        this->metodos[i].tiempo_ascendente = this->timer.getTime();
        this->metodos[i].comp_ascendente = vecOrd.getC();
        this->metodos[i].permut_ascendente = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->selectionSort();
        this->timer.stop();
        this->metodos[i].tiempo_aleatorio = this->timer.getTime();
        this->metodos[i].comp_aleatorio = vecOrd.getC();
        this->metodos[i].permut_aleatorio = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->selectionSort();
        this->timer.stop();
        this->metodos[i].tiempo_descendente = this->timer.getTime();
        this->metodos[i].comp_descendente = vecOrd.getC();
        this->metodos[i].permut_descendente = vecOrd.getM();
        break;
    case 2:
        this->metodos[i].nombre = "Bubble Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->bubbleSort();
        this->timer.stop();
        this->metodos[i].tiempo_ascendente = this->timer.getTime();
        this->metodos[i].comp_ascendente = vecOrd.getC();
        this->metodos[i].permut_ascendente = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->bubbleSort();
        this->timer.stop();
        this->metodos[i].tiempo_aleatorio = this->timer.getTime();
        this->metodos[i].comp_aleatorio = vecOrd.getC();
        this->metodos[i].permut_aleatorio = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->bubbleSort();
        this->timer.stop();
        this->metodos[i].tiempo_descendente = this->timer.getTime();
        this->metodos[i].comp_descendente = vecOrd.getC();
        this->metodos[i].permut_descendente = vecOrd.getM();
        break;
    case 3:
        this->metodos[i].nombre = "Merge Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->mergeSort();
        this->timer.stop();
        this->metodos[i].tiempo_ascendente = this->timer.getTime();
        this->metodos[i].comp_ascendente = vecOrd.getC();
        this->metodos[i].permut_ascendente = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->mergeSort();
        this->timer.stop();
        this->metodos[i].tiempo_aleatorio = this->timer.getTime();
        this->metodos[i].comp_aleatorio = vecOrd.getC();
        this->metodos[i].permut_aleatorio = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->mergeSort();
        this->timer.stop();
        this->metodos[i].tiempo_descendente = this->timer.getTime();
        this->metodos[i].comp_descendente = vecOrd.getC();
        this->metodos[i].permut_descendente = vecOrd.getM();
        break;
    case 4:
        this->metodos[i].nombre = "Shell Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->shellSort();
        this->timer.stop();
        this->metodos[i].tiempo_ascendente = this->timer.getTime();
        this->metodos[i].comp_ascendente = vecOrd.getC();
        this->metodos[i].permut_ascendente = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->shellSort();
        this->timer.stop();
        this->metodos[i].tiempo_aleatorio = this->timer.getTime();
        this->metodos[i].comp_aleatorio = vecOrd.getC();
        this->metodos[i].permut_aleatorio = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->shellSort();
        this->timer.stop();
        this->metodos[i].tiempo_descendente = this->timer.getTime();
        this->metodos[i].comp_descendente = vecOrd.getC();
        this->metodos[i].permut_descendente = vecOrd.getM();
        break;
    case 5:
        this->metodos[i].nombre = "Quick Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->quickSort();
        this->timer.stop();
        this->metodos[i].tiempo_ascendente = this->timer.getTime();
        this->metodos[i].comp_ascendente = vecOrd.getC();
        this->metodos[i].permut_ascendente = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->quickSort();
        this->timer.stop();
        this->metodos[i].tiempo_aleatorio = this->timer.getTime();
        this->metodos[i].comp_aleatorio = vecOrd.getC();
        this->metodos[i].permut_aleatorio = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->quickSort();
        this->timer.stop();
        this->metodos[i].tiempo_descendente = this->timer.getTime();
        this->metodos[i].comp_descendente = vecOrd.getC();
        this->metodos[i].permut_descendente = vecOrd.getM();
        break;
    case 6:
        this->metodos[i].nombre = "Heap Sort";
        this->statusBar(i);
        //Prueba vector Ascendente (Mejor caso).
        this->vector->UpFill();
        this->timer.start();
        vecOrd = this->vector->heapSort();
        this->timer.stop();
        this->metodos[i].tiempo_ascendente = this->timer.getTime();
        this->metodos[i].comp_ascendente = vecOrd.getC();
        this->metodos[i].permut_ascendente = vecOrd.getM();
        //Prueba vector desordenado (Caso intermedio).
        this->vector->randomFill(1, this->vector->length());
        this->timer.start();
        vecOrd = this->vector->heapSort();
        this->timer.stop();
        this->metodos[i].tiempo_aleatorio = this->timer.getTime();
        this->metodos[i].comp_aleatorio = vecOrd.getC();
        this->metodos[i].permut_aleatorio = vecOrd.getM();
        //Prueba vector Descendente (Peor caso).
        this->vector->DownFill();
        this->timer.start();
        vecOrd = this->vector->heapSort();
        this->timer.stop();
        this->metodos[i].tiempo_descendente = this->timer.getTime();
        this->metodos[i].comp_descendente = vecOrd.getC();
        this->metodos[i].permut_descendente = vecOrd.getM();
        break;
    }
    return;
}

void Sistema::gotoxy(int x, int y) { //Funci�n gotoxy para dar est�tica al programa.
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
    return;
}