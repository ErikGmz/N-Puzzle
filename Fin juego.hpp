//-----Compilación de la cabecera-----//.
#ifndef Fin_juego_hpp
#define Fin_juego_hpp

//-----Funciones-----//.
//Genera un ordenamiento descendente para el vector de jugadores.
bool ordenamiento_descendente(Datos a, Datos b) {
    return (a.puntaje > b.puntaje);
}

//-----Clase 'Finalizar'-----//.
class Finalizar {
private:
    //---Atributos---//.
    int contador, tiempo;
    bool parpadeo;
    Datos* jugador_actual;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;

    //---Funciones privadas---//.
    void actualizar_archivo(); //Se actualiza el contenido del registro.
    char numero_a_caracter(int); //Se retorna un dígito en forma de caracter.
    char* formato_tiempo(); //Se convierte una cifra en un formato de tiempo.
    void imprimir_interfaz(); //Se imprime la interfaz del menú de finalización.
public:
    //---Contructor---//.
    Finalizar(ALLEGRO_FONT*, ALLEGRO_DISPLAY*, Datos*, int); //Constructor con argumentos.

    //---Métodos---//.
    bool generar_fin_partida(); //Se genera el menú de finalización.
};

//-----Métodos de la clase 'Finalizar'-----//.
//---Funciones privadas---//.
//Se actualiza el contenido del registro.
void Finalizar::actualizar_archivo() {
    fstream archivo("registro.dat", ios::binary | ios::in);
    if (!archivo) {
        archivo.close();
        archivo.open("registro.dat", ios::binary | ios::out);
        archivo.close();
        fstream archivo("registro.dat", ios::binary | ios::in);
    }
    Datos* aux1 = new Datos;
    Datos_Guardar* aux2 = new Datos_Guardar;
    list<Datos>* ordenamiento = new list<Datos>;
    bool encontrado = false;

    archivo.read(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    while (!archivo.eof()) {
        aux1->nombre = aux2->nombre;
        if (aux1->nombre == this->jugador_actual->nombre) {
            encontrado = true;
            aux1->puntaje = this->jugador_actual->puntaje;
            aux1->fecha = this->jugador_actual->fecha;
        }
        else {
            aux1->puntaje = aux2->puntaje;
            aux1->fecha = aux2->fecha;
        }
        ordenamiento->push_back(*aux1);
        archivo.read(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    }
    if (!encontrado) {
        aux1->nombre = this->jugador_actual->nombre;
        aux1->puntaje = this->jugador_actual->puntaje;
        aux1->fecha = this->jugador_actual->fecha;
        ordenamiento->push_back(*aux1);
    }
    ordenamiento->sort(ordenamiento_descendente);

    archivo.clear(); archivo.close();
    remove("registro.dat");
    archivo.open("registro.dat", ios::binary | ios::out);

    for (auto it = ordenamiento->begin(); it != ordenamiento->end(); ++it) {
        strcpy_s(aux2->nombre, 40, it->nombre.c_str());
        aux2->puntaje = it->puntaje;
        strcpy_s(aux2->fecha, 40, it->fecha.c_str());
        archivo.write(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    }
    archivo.clear(); archivo.close();
    delete aux1, aux2, ordenamiento;
}

//Se retorna un dígito en forma de caracter.
char Finalizar::numero_a_caracter(int digito) {
    switch (digito) {
    case 0: return '0'; break;
    case 1: return '1'; break;
    case 2: return '2'; break;
    case 3: return '3'; break;
    case 4: return '4'; break;
    case 5: return '5'; break;
    case 6: return '6'; break;
    case 7: return '7'; break;
    case 8: return '8'; break;
    case 9: return '9'; break;
    default: return 'a'; break;
    }
}

//Se convierte una cifra en un formato de tiempo.
char* Finalizar::formato_tiempo() {
    string formato;
    int minutos = 0, segundos = 0, horas = 0;
    int auxiliar = this->tiempo;

    while (auxiliar >= 3600) {
        horas++;
        auxiliar -= 3600;
    }
    while (auxiliar >= 60) {
        minutos++;
        auxiliar -= 60;
    }
    if (auxiliar > 0) {
        segundos += auxiliar;
    }
    if (horas < 10) {
        formato.push_back('0');
        formato.push_back(numero_a_caracter(horas));
    }
    else {
        formato.push_back(numero_a_caracter(horas / 10));
        formato.push_back(numero_a_caracter(horas % 10));
    }
    formato.push_back(':');

    if (minutos < 10) {
        formato.push_back('0');
        formato.push_back(numero_a_caracter(minutos));
    }
    else {
        formato.push_back(numero_a_caracter(minutos / 10));
        formato.push_back(numero_a_caracter(minutos % 10));
    }
    formato.push_back(':');

    if (segundos < 10) {
        formato.push_back('0');
        formato.push_back(numero_a_caracter(segundos));
    }
    else {
        formato.push_back(numero_a_caracter(segundos / 10));
        formato.push_back(numero_a_caracter(segundos % 10));
    }

    char* retorno = new char[10];
    strcpy_s(retorno, 10, formato.c_str());
    return retorno;
}

//Se imprime la interfaz del menú de finalización.
void Finalizar::imprimir_interfaz() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(255, 192, 201), 400, 50, ALLEGRO_ALIGN_CENTRE, "PARTIDA FINALIZADA");
    al_draw_text(this->letra, al_map_rgb(255, 204, 102), 400, 130, ALLEGRO_ALIGN_CENTRE, "EL PUNTAJE DEL JUGADOR");
    al_draw_text(this->letra, al_map_rgb(255, 204, 102), 400, 180, ALLEGRO_ALIGN_CENTRE, ((this->jugador_actual->nombre + " FUE " + to_string(this->jugador_actual->puntaje)).c_str()));

    al_draw_text(this->letra, al_map_rgb(229, 229, 255), 400, 260, ALLEGRO_ALIGN_CENTRE, "EL TIEMPO UTILIZADO FUE");
    al_draw_text(this->letra, al_map_rgb(229, 229, 255), 400, 310, ALLEGRO_ALIGN_CENTRE, this->formato_tiempo());

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
}

//---Contructor---//.
//Constructor con argumentos.
Finalizar::Finalizar(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana, Datos* jugador, int temporizador) {
    this->contador = 0;
    this->parpadeo = true;
    this->jugador_actual = jugador;
    this->tiempo = temporizador;
    this->letra = formato;
    this->pantalla = ventana;
}

//---Métodos---//.
//Se genera el menú de finalización.
bool Finalizar::generar_fin_partida() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance1 = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    this->actualizar_archivo();
    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                al_play_sample(avance1, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return false;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance1);
    return true;
}
#endif