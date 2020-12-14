//-----Compilación del archivo fuente-----//.
#ifndef Puzzle_cpp
#define Puzzle_cpp

//-----Librerías-----//.
#include "Puzzle.hpp"

//-----Métodos de la clase 'Puzzle'-----//.
//---Funciones privadas---//.
//Se imprime la interfaz para la solicitud.
void Puzzle::imprimir_interfaz_captura(int fila, int columna, int tipo_puzzle) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (tipo_puzzle == 1) al_draw_text(this->letra, al_map_rgb(255, 195, 243), 400, 40, ALLEGRO_ALIGN_CENTRE, "PUZZLE INICIAL");
    else al_draw_text(this->letra, al_map_rgb(166, 226, 255), 400, 40, ALLEGRO_ALIGN_CENTRE, "PUZZLE META");
    string* auxiliar = new string;
    *auxiliar = "POSICIONE EL";

    switch (this->contador) {
    case 0: *auxiliar += " ESPACIO"; break;     case 16: *auxiliar += " NUMERO 16"; break;
    case 1: *auxiliar += " NUMERO 1"; break;    case 17: *auxiliar += " NUMERO 17"; break;
    case 2: *auxiliar += " NUMERO 2"; break;    case 18: *auxiliar += " NUMERO 18"; break;
    case 3: *auxiliar += " NUMERO 3"; break;    case 19: *auxiliar += " NUMERO 19"; break;
    case 4: *auxiliar += " NUMERO 4"; break;    case 20: *auxiliar += " NUMERO 20"; break;
    case 5: *auxiliar += " NUMERO 5"; break;    case 21: *auxiliar += " NUMERO 21"; break;
    case 6: *auxiliar += " NUMERO 6"; break;    case 22: *auxiliar += " NUMERO 22"; break;
    case 7: *auxiliar += " NUMERO 7"; break;    case 23: *auxiliar += " NUMERO 23"; break;
    case 8: *auxiliar += " NUMERO 8"; break;    case 24: *auxiliar += " NUMERO 24"; break;
    case 9: *auxiliar += " NUMERO 9"; break;
    case 10: *auxiliar += " NUMERO 10"; break;
    case 11: *auxiliar += " NUMERO 11"; break;
    case 12: *auxiliar += " NUMERO 12"; break;
    case 13: *auxiliar += " NUMERO 13"; break;
    case 14: *auxiliar += " NUMERO 14"; break;
    case 15: *auxiliar += " NUMERO 15"; break;
    }
    al_draw_text(this->letra, al_map_rgb(189, 249, 201), 400, 100, ALLEGRO_ALIGN_CENTRE, auxiliar->c_str());
    al_draw_rectangle(350, 463, 450, 513, al_map_rgb(255, 184, 166), 5);
    al_draw_text(this->letra, al_map_rgb(255, 255, 139), 400, 471, ALLEGRO_ALIGN_CENTRE, this->puzzle[0][fila][columna].c_str());

    switch (this->tipo_puzzle) {
    case 3: al_draw_filled_rectangle(200, 200, 353, 353, al_map_rgb(255, 255, 255)); break;
    case 4: al_draw_filled_rectangle(200, 200, 403, 403, al_map_rgb(255, 255, 255)); break;
    case 5: al_draw_filled_rectangle(200, 200, 453, 453, al_map_rgb(255, 255, 255)); break;
    }

    for (int i = 0; i < this->tipo_puzzle; i++) {
        for (int j = 0; j < this->tipo_puzzle; j++) {
            al_draw_filled_rectangle(200 + i * 50 + 3, 200 + j * 50 + 3, 200 + (i + 1) * 50, 200 + (j + 1) * 50, al_map_rgb(25, 177, 201));
        }
    }
    al_flip_display();
    delete auxiliar;
}

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
    //this->imprimePuzzle();
    cout << endl;
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
//Se genera el menú para la solicitud del puzzle.
void Puzzle::capturaPuzzle() {
    bool cancelar = false;

    for (int i = 0; i < this->tipo_puzzle && !cancelar; i++) {
        for (int j = 0; j < this->tipo_puzzle && !cancelar; j++) {

            ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
            bool continuar = false, reanudar, sonido = false;

            al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
            al_register_event_source(fila_evento, al_get_keyboard_event_source());

            this->imprimir_interfaz_captura(i, j, this->tipo_puzzle); 
            while (!continuar) {
                ALLEGRO_EVENT evento;
                al_wait_for_event(fila_evento, &evento);

                switch (evento.type) {
                case ALLEGRO_EVENT_KEY_CHAR:
                    if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                        if (this->puzzle[0][i][j].length() == 0) {
                            al_show_native_message_box(pantalla, "Advertencia", "Error de formato", "Texto mal introducido", NULL, ALLEGRO_MESSAGEBOX_WARN);
                        }
                        else if (!this->entrada_valida(i, j)) {
                            al_show_native_message_box(pantalla, "Advertencia", "Error de entrada", "Valor repetido/invalidado", NULL, ALLEGRO_MESSAGEBOX_WARN);
                            this->puzzle[0][i][j].clear();
                        }
                        else {
                            /*al_play_sample(click, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                            al_rest(0.3);
                            al_clear_to_color(al_map_rgb(0, 0, 0));
                            al_flip_display();
                            al_rest(0.3);*/
                            contador++;
                            continuar = true;
                        }
                    }
                    else {
                        char auxiliar = this->validar_entrada(evento);
                        if (auxiliar != '+' && this->puzzle[0][i][j].length() < 2) {
                            //al_play_sample(tecla, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                        }
                        if (auxiliar != '+' && auxiliar != '-' && this->puzzle[0][i][j].length() < 2) {
                            this->puzzle[0][i][j].push_back(auxiliar);
                            this->imprimir_interfaz_captura(i, j, this->tipo_puzzle);
                        }
                        if (auxiliar == '-' && this->puzzle[0][i][j].length() > 0) {
                            this->puzzle[i][j].pop_back();
                            this->imprimir_interfaz_captura(i, j, this->tipo_puzzle);
                        }
                    }
                    break;
                case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                    reanudar = false;
                    while (!reanudar) {
                        ALLEGRO_EVENT evento2;
                        al_wait_for_event(fila_evento, &evento2);

                        if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                            this->imprimir_interfaz_captura(i, j, this->tipo_puzzle);
                            reanudar = true;
                        }
                    }
                    break;
                case ALLEGRO_EVENT_DISPLAY_CLOSE:
                    puzzle[0][0][0] = "c";
                    continuar = true;
                    cancelar = true;
                    break;
                }
            }
            al_destroy_event_queue(fila_evento);
        }
    }
    return;
}

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
#endif