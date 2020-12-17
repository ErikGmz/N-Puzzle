//-----Compilación del archivo fuente-----//.
#ifndef Puzzle_cpp
#define Puzzle_cpp

//-----Librerías-----//.
#include "Puzzle.hpp"

//-----Métodos de la clase 'Puzzle'-----//.
//---Funciones privadas---//.
//Se verifica que el caracter ingresado sea numérico.
char Puzzle::validar_entrada(ALLEGRO_EVENT evento) {
    char letra;
    switch (evento.keyboard.keycode) {
    case ALLEGRO_KEY_1: letra = '1'; break; case ALLEGRO_KEY_2: letra = '2'; break; case ALLEGRO_KEY_3: letra = '3'; break;
    case ALLEGRO_KEY_4: letra = '4'; break; case ALLEGRO_KEY_5: letra = '5'; break; case ALLEGRO_KEY_6: letra = '6'; break;
    case ALLEGRO_KEY_7: letra = '7'; break; case ALLEGRO_KEY_8: letra = '8'; break; case ALLEGRO_KEY_9: letra = '9'; break;
    case ALLEGRO_KEY_0: letra = '0'; break;
    case ALLEGRO_KEY_BACKSPACE: letra = '-'; break; default: letra = '+'; break;
    }
    return letra;
}

//Se verifica si la entrada actual es repetida/válida o no.
bool Puzzle::entrada_valida(int fila, int columna) {
    int limite;

    switch (this->tipo_puzzle) {
    case 3: limite = 9; break;
    case 4: limite = 16; break;
    case 5: limite = 25; break;
    }

    int auxiliar = stoi(this->puzzle[0][fila][columna]);
    if (auxiliar > limite || auxiliar < 1) {
        return false;
    }

    for (int i = 0; i < this->tipo_puzzle; i++) {
        for (int j = 0; j < this->tipo_puzzle; j++) {
            if (!(i == fila && j == columna)) {
                if (this->puzzle[0][i][j] == this->puzzle[0][fila][columna]) {
                    return false;
                }
            }
        }
    }
    return true;
}

//Se calcula el costo que requiere resolver un puzzle inicial a uno meta.
int Puzzle::calculaCosto(vector<vector<string>>& puzzle_inicial, vector<vector<string>>& puzzle_final) {
    int costo = 0;
    for (int i = 0; i < this->tipo_puzzle; i++) {
        for (int j = 0; j < this->tipo_puzzle; j++) {
            if (puzzle_inicial[i][j] != "0" && puzzle_final[i][j] != puzzle_final[i][j]) {
                costo++;
            }
        }
    }
    return costo;
}

//Se verifica si dos elementos, según el tamaño del puzzle.
bool Puzzle::esCoordenada(int x, int y) {
    return (x >= 0 && x < this->tipo_puzzle&& y >= 0 && y < this->tipo_puzzle);
}

//Se imprime la ruta más optima para resolver el puzzle.
void Puzzle::imprimeRuta(Nodo* raiz) {
    if (raiz == NULL)
        return;
    this->imprimeRuta(raiz->padre);
    this->imprimePuzzle();
    cout << endl;
}

//Se convierte un string a un valor numérico.  
int Puzzle::convertir_string(string valor) {
    if (valor == "1") return 0;         else if (valor == "2") return 1;    else if (valor == "3") return 2;
    else if (valor == "4") return 3;    else if (valor == "5") return 4;    else if (valor == "6") return 5;
    else if (valor == "7") return 6;    else if (valor == "8") return 7;    else if (valor == "9") return 8;
    else if (valor == "10") return 9;   else if (valor == "11") return 10;  else if (valor == "12") return 11;
    else if (valor == "13") return 12;  else if (valor == "14") return 13;  else if (valor == "15") return 14;
    else if (valor == "16") return 15;  else if (valor == "17") return 16;  else if (valor == "18") return 17;
    else if (valor == "19") return 18;  else if (valor == "20") return 19;  else if (valor == "21") return 20;
    else if (valor == "22") return 21;  else if (valor == "23") return 22;  else if (valor == "24") return 23;
    else return 0;
}

//---Constructor y destructor---//.
//Constructor con argumentos.
Puzzle::Puzzle(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana, int tipo_puzzle) {
    this->x = this->y = this->contador = 0;
    this->letra = formato;
    this->pantalla = ventana;
    this->tipo_puzzle = tipo_puzzle;
    this->puzzle = new vector<vector<string>>(this->tipo_puzzle, vector<string>(this->tipo_puzzle, ""));
}

//Destructor.
Puzzle::~Puzzle() {
    delete this->puzzle;
}

//---Métodos---//.
//Se genera el puzzle de forma aleatoria.
void Puzzle::generaPuzzle() {
	string random;
	int contador_y = 0, contador_x = 0;
    vector<string>* num_aleatorios = new vector<string>;

    for (int i = 0; i < pow(this->tipo_puzzle, 2); i++) num_aleatorios->push_back(to_string(i));
    int k = pow(this->tipo_puzzle, 2) - 1;

    for (int i = 0; i < pow(this->tipo_puzzle, 2); i++) {
        int j = rand() % (k + 1);

        string intercambio = num_aleatorios[0][j + i];
        num_aleatorios[0][j + i] = num_aleatorios[0][i];
        num_aleatorios[0][i] = intercambio;

        k--;
    }
    for (int i = 0; i < this->tipo_puzzle; i++) {
        for (int j = 0; j < this->tipo_puzzle; j++) {
            this->puzzle[0][i][j] = num_aleatorios->back();
            num_aleatorios->pop_back();
        }
    }
    delete num_aleatorios;
	return;
}

//Si tiene solución, se resuelve el puzzle por medio del algoritmo branch and bound.
void Puzzle::resuelve(int x,int y, vector<vector<string>> &puzzle_final) {
    // Para los movimientos de las fichas.
    // Abajo, Izq, Arriba, Der.
    int row[] = { 1, 0, -1, 0 }; 
    int col[] = { 0, -1, 0, 1 }; 

    // Creamos una cola de prioridad para almacenar los nodos vivos del arbol de busqeda.
    priority_queue<Nodo*, vector<Nodo*>, comp> nodosVivos; 

    // Creamos un nuevo nodo y calculamos su costo.
    Nodo* raiz = new Nodo(*(this->puzzle), x, y, x, y, 0, NULL);  

    raiz->costo = this->calculaCosto(*(this->puzzle), puzzle_final); 
    // Agregamos la raiz a la cola de prioridad (lista de nododos vivos).

    nodosVivos.push(raiz); 
    // Buscamos el nodo vivo de menor costo, agregamos a sus hijos a la lista de nodos vivos y lo eliminamos de la lista.

    while (!nodosVivos.empty()) { 
        Nodo* min = nodosVivos.top(); //Extraemos el nodo vivo con menor costo estimado.

        nodosVivos.pop(); //Eliminamos al nodo extraido de la lista de nodos vivos.

        if (min->costo == 0) { // Si el nodo extraido es un nodo solucion.
            this->imprimeRuta(min); //Imprimimos el recorrido, de la raiz local al destino.
            return; 
        } 

        //Ciclo para crear los nodos hijo del elemento extraido (maximo cuatro hijos por nodoi).
        for (int i = 0; i < 4; i++) {
            if (this->esCoordenada(min->x + row[i], min->y + col[i])) {

                // Creamos un nuevo hijo y calculamos su costo.
                Nodo* hijo = new Nodo(min->mat, min->x, min->y, min->x + row[i], min->y + col[i], min->nivel + 1, min);

                hijo->costo = this->calculaCosto(hijo->mat, puzzle_final);
                // Agregamos el hijo a la lista de nodos vivos. 
                nodosVivos.push(hijo);
            }
        }
    } 
}

//Se compara si ambos puzzles son exactamente iguales.
bool Puzzle::operator==(Puzzle &puzzle) {
    for (int i = 0; i < this->tipo_puzzle; i++) {
        for (int j = 0; j < this->tipo_puzzle; j++) {
            if (this->puzzle[0][i][j] != puzzle.puzzle[0][i][j]) return false;
        }
    }
    return true;
}

//Se retorna un vector relacionado con el tablero.
vector<string> &Puzzle::operator[](int elemento) {
    return this->puzzle[0][elemento];
}

//Se intercambian dos valores dentro del tablero.
void Puzzle::swap(int direccion) {
    string auxiliar;

    for (int i = 0; i < this->tipo_puzzle; i++) {
        for (int j = 0; j < this->tipo_puzzle; j++) {
            if (this->puzzle[0][i][j] == "0") {
                switch (direccion) {
                case 1:
                    auxiliar = this->puzzle[0][i][j];
                    this->puzzle[0][i][j] = this->puzzle[0][i - 1][j];
                    this->puzzle[0][i - 1][j] = auxiliar;
                    break;
                case 2:
                    auxiliar = this->puzzle[0][i][j];
                    this->puzzle[0][i][j] = this->puzzle[0][i + 1][j];
                    this->puzzle[0][i + 1][j] = auxiliar;
                    break;
                case 3:
                    auxiliar = this->puzzle[0][i][j];
                    this->puzzle[0][i][j] = this->puzzle[0][i][j - 1];
                    this->puzzle[0][i][j - 1] = auxiliar;
                    break;
                case 4:
                    auxiliar = this->puzzle[0][i][j];
                    this->puzzle[0][i][j] = this->puzzle[0][i][j + 1];
                    this->puzzle[0][i][j + 1] = auxiliar;
                    break;
                }
                return;
            }
        }
    }
}


//Se retorna la cantidad de permutaciones del tablero actual.
int Puzzle::inversiones(int* arreglo) {
    int inversiones = 0;

    for (int i = 0; i < this->tipo_puzzle * this->tipo_puzzle - 1; i++) {
        for (int j = i + 1; j < this->tipo_puzzle * this->tipo_puzzle; j++) {
            if (arreglo[i] && arreglo[j] && arreglo[i] > arreglo[j]) {
                inversiones++;
            }
        }
    }
    return inversiones;
}

//Se imprime el contenido del puzzle.
void Puzzle::imprimePuzzle() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    ALLEGRO_BITMAP* puzzle_3x3 = al_load_bitmap("Sources/TableroFacil3x3.png");
    ALLEGRO_BITMAP* puzzle_4x4 = al_load_bitmap("Sources/TableroMedio4x4.png");
    ALLEGRO_BITMAP* puzzle_5x5 = al_load_bitmap("Sources/TableroDificil5x5.png");
    ALLEGRO_BITMAP* cubo1 = al_load_bitmap("Sources/Cubo chico 1.png");
    ALLEGRO_BITMAP* cubo2 = al_load_bitmap("Sources/Cubo chico 2.png");
    ALLEGRO_BITMAP* cubo3 = al_load_bitmap("Sources/Cubo chico 3.png");
    ALLEGRO_BITMAP* cubo4 = al_load_bitmap("Sources/Cubo grande.png");

    vector<ALLEGRO_BITMAP*>* fichas = new vector<ALLEGRO_BITMAP*>;
    for (int i = 1; i < 25; i++) {
        string aux = "Sources/Fichas/F";
        ALLEGRO_BITMAP* elemento = al_load_bitmap((aux + to_string(i) + ".png").c_str());
        fichas->push_back(elemento);
    }
    al_draw_text(this->letra, al_map_rgb(164, 255, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "RESOLVIENDO PUZZLE...");

    al_draw_bitmap(cubo4, 50, 415, NULL);
    al_draw_bitmap(cubo1, 210, 435, NULL);
    al_draw_bitmap(cubo2, 330, 435, NULL);
    al_draw_bitmap(cubo3, 450, 435, NULL);
    al_draw_bitmap(cubo1, 570, 435, NULL);
    al_draw_bitmap(cubo2, 690, 435, NULL);

    switch (this->tipo_puzzle) {
    case 3:
        al_draw_bitmap(puzzle_3x3, 319, 180, NULL);
        break;
    case 4:
        al_draw_bitmap(puzzle_4x4, 293, 150, NULL);
        break;
    case 5:
        al_draw_bitmap(puzzle_5x5, 266, 120, NULL);
        break;
    }

    for (int i = 0; i < this->tipo_puzzle; i++) {
        for (int j = 0; j < this->tipo_puzzle; j++) {
            if (this->puzzle[0][i][j] != "0") {
                int auxiliar2 = this->convertir_string(this->puzzle[0][i][j]);

                switch (this->tipo_puzzle) {
                case 3: al_draw_bitmap(fichas[0][auxiliar2], 319 + j * 53 + 3, 180 + i * 53 + 3, NULL); break;
                case 4: al_draw_bitmap(fichas[0][auxiliar2], 293 + j * 53 + 3, 150 + i * 53 + 3, NULL); break;
                case 5: al_draw_bitmap(fichas[0][auxiliar2], 266 + j * 53 + 3, 120 + i * 53 + 3, NULL); break;
                }
            }
        }
    }
    al_flip_display();
    al_destroy_bitmap(puzzle_3x3); al_destroy_bitmap(puzzle_4x4);
    al_destroy_bitmap(puzzle_5x5); al_destroy_bitmap(cubo1);
    al_destroy_bitmap(cubo2); al_destroy_bitmap(cubo3);
    al_destroy_bitmap(cubo4); delete fichas;
}

//-----Métodos de la clase 'Puzzle_facil'-----//.
//---Métodos---//.
//Se verifica si el 8-puzzle puede resolverse con la meta predeterminada.
bool Puzzle_facil::resolvible_manual() {
    int inversiones = 0;
    int* arreglo = new int[9];

    for (int i = 0, contador = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            arreglo[contador++] = stoi(this->puzzle[0][i][j]);
        }
    }

    inversiones = this->inversiones(arreglo);
    delete arreglo;
    return inversiones % 2 == 0;
}

//-----Métodos de la clase 'Puzzle_medio'-----//.
//---Funciones privadas---//.
//Se retorna la posición horizontal del espacio.
int Puzzle_medio::posicion_x_cero() {
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (this->puzzle[0][i][j] == "0") {
                return this->tipo_puzzle - i;
            }
        }
    }
    return this->tipo_puzzle;
}

//---Métodos---//.
//Se verifica si el 15-puzzle puede resolverse con la meta predeterminada.
bool Puzzle_medio::resolvible_manual() {
    int inversiones = 0;
    int* arreglo = new int[16];

    for (int i = 0, contador = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arreglo[contador++] = stoi(this->puzzle[0][i][j]);
        }
    }

    inversiones = this->inversiones(arreglo);
    delete arreglo;

    if (this->posicion_x_cero() % 2 != 0) {
        return (inversiones % 2 == 0);
    }
    else {
        return (inversiones % 2 != 0);
    }
}

//-----Métodos de la clase 'Puzzle_dificil'-----//.
//---Métodos---//.
//Se verifica si el 24-puzzle puede resolverse con la meta predeterminada.
bool Puzzle_dificil::resolvible_manual() {
    int inversiones;
    int* arreglo = new int[25];
        ;
    for (int i = 0, contador = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arreglo[contador++] = stoi(this->puzzle[0][i][j]);
        }
    }

    inversiones = this->inversiones(arreglo);
    delete arreglo;
    return inversiones % 2 == 0;
}
#endif