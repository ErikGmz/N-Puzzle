//-----Compilación de la cabecera-----//.
#ifndef Finalizar_demostración_hpp
#define Finalizar_demostración_hpp

//-----Clase 'Fin'-----//.
class Fin {
private:
    //---Atributos---//.
    int contador;
    bool parpadeo;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;

    //---Funciones privadas---//.
    void imprimir_interfaz(); //Se imprime la interfaz para el fin de la demostración.
public:
    //---Contructor---//.
    Fin(ALLEGRO_FONT*, ALLEGRO_DISPLAY*); //Constructor con argumentos.

    //---Métodos---//.
    bool generar_fin(); //Se genera la pantalla para el fin de la demostración.
};

//-----Métodos de la clase 'Fin'-----//.
//---Funciones privadas---//.
//Se imprime la interfaz para el fin de la demostración.
void Fin::imprimir_interfaz() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(249, 192, 249), 400, 50, ALLEGRO_ALIGN_CENTRE, "DEMOSTRACION FINALIZADA");

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
Fin::Fin(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana) {
    this->contador = 0;
    this->parpadeo = true;
    this->letra = formato;
    this->pantalla = ventana;
}

//---Métodos---//.
//Se genera la pantalla para el fin de la demostración.
bool Fin::generar_fin() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

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
    al_destroy_sample(avance);
    return true;
}
#endif