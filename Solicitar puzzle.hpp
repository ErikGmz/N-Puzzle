//-----Compilación de la cabecera-----//.
#ifndef Solicitar_puzzle_hpp
#define Solicitar_puzzle_hpp

//-----Clase 'Solicitud'-----//.
class Solicitud {
private:
    //---Atributos---//.
    int x, y, contador;
    int dificultad, tipo_puzzle;
    vector<vector<string>>* puzzle;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;

    //---Funciones privadas---//.
    bool entrada_valida(int, int); //Se verifica si la entrada actual es repetida/válida o no.
    void imprimir_interfaz(int, int, int); //Se imprime la interfaz para la solicitud.
    char validar_entrada(ALLEGRO_EVENT); //Se verifica que el caracter ingresado sea numérico.
public:
    //---Contructor---//.
    Solicitud(ALLEGRO_FONT*, ALLEGRO_DISPLAY*, int, int); //Constructor con argumentos.

    //---Métodos---//.
    vector<vector<string>> generar_solicitud(); //Se genera el menú para la solicitud del puzzle.
};

//-----Métodos de la clase 'Solicitud'-----//.
//-----Funciones privadas-----//.
//Se verifica si la entrada actual es repetida/válida o no.
bool Solicitud::entrada_valida(int fila, int columna) {
    int limite;

    switch (this->dificultad) {
    case 3: limite = 9; break;
    case 4: limite = 16; break;
    case 5: limite = 25; break;
    }

    int auxiliar = stoi(this->puzzle[0][fila][columna]);
    if (auxiliar > limite || auxiliar < 1) {
        return false;
    }

    for (int i = 0; i < this->dificultad; i++) {
        for (int j = 0; j < this->dificultad; j++) {
            if (!(i == fila && j == columna)) {
                if (this->puzzle[0][i][j] == this->puzzle[0][fila][columna]) {
                    return false;
                }
            }
        }
    }
    return true;
}

//Se imprimen los elementos para la solicitud del puzzle.
void Solicitud::imprimir_interfaz(int fila, int columna, int tipo_puzzle) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if(tipo_puzzle == 1) al_draw_text(this->letra, al_map_rgb(255, 195, 243), 400, 40, ALLEGRO_ALIGN_CENTRE, "PUZZLE INICIAL");
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

    switch (this->dificultad) {
    case 3: al_draw_filled_rectangle(200, 200, 353, 353, al_map_rgb(255, 255, 255)); break;
    case 4: al_draw_filled_rectangle(200, 200, 403, 403, al_map_rgb(255, 255, 255)); break;
    case 5: al_draw_filled_rectangle(200, 200, 453, 453, al_map_rgb(255, 255, 255)); break;
    }

    for (int i = 0; i < this->dificultad ; i++) {
        for (int j = 0; j < this->dificultad; j++) {
            al_draw_filled_rectangle(200 + i * 50 + 3, 200 + j * 50 + 3, 200 + (i + 1) * 50, 200 + (j + 1) * 50, al_map_rgb(25, 177, 201));
        }
    }
    al_flip_display();
    delete auxiliar;
}

//Se verifica que el caracter ingresado sea numérico.
char Solicitud::validar_entrada(ALLEGRO_EVENT evento) {
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

//---Contructor---//.
//Constructor con argumentos.
Solicitud::Solicitud(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana, int dificul, int puzzle) {
    this->x = this->y = this->contador = 0;
    this->dificultad = dificul;
    this->letra = formato;
    this->pantalla = ventana;
    this->puzzle = new vector<vector<string>>(dificultad, vector<string>(dificultad, ""));
    this->tipo_puzzle = puzzle;
}

//Se genera el menú para la solicitud del puzzle.
vector<vector<string>> Solicitud::generar_solicitud() {
    bool cancelar = false;

    for (int i = 0; i < this->dificultad && !cancelar; i++) {
        for (int j = 0; j < dificultad && !cancelar; j++) {

            ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
            bool continuar = false, reanudar, sonido = false;

            al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
            al_register_event_source(fila_evento, al_get_keyboard_event_source());

            this->imprimir_interfaz(i, j, this->tipo_puzzle); 
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
                            this->imprimir_interfaz(i, j, this->tipo_puzzle);
                        }
                        if (auxiliar == '-' && this->puzzle[0][i][j].length() > 0) {
                            this->puzzle[i][j].pop_back();
                            this->imprimir_interfaz(i, j, this->tipo_puzzle);
                        }
                    }
                    break;
                case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                    reanudar = false;
                    while (!reanudar) {
                        ALLEGRO_EVENT evento2;
                        al_wait_for_event(fila_evento, &evento2);

                        if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                            this->imprimir_interfaz(i, j, this->tipo_puzzle);
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
    return *puzzle;
}
#endif
