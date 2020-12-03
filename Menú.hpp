//-----Compilación de la cabecera-----//.
#ifndef Menú_hpp
#define Menú_hpp

//-----Clase 'Menú'-----//.
class Menu {
private:
    //---Atributos---//.
    int x, y;
    int contador;
    bool parpadeo;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;

    //---Funciones privadas---//.
    int posicionado(); //Se determina en cuál ícono se ha posicionado el cursor.
    void imprimir_interfaz(); //Se imprime la interfaz del menú principal.
public:
    //---Contructor---//.
    Menu(ALLEGRO_FONT*, ALLEGRO_DISPLAY*); //Constructor con argumentos.

    //---Métodos---//.
    int generar_menu(); //Se genera el menú principal.
};

//-----Métodos de la clase 'Menú'-----//.
//---Funciones privadas---//.
//Se determina en cuál ícono se ha posicionado el cursor.
int Menu::posicionado() {
    if (this->x >= 200 && this->x <= 600 && this->y >= 60 && this->y <= 120) return 1;
    else if (this->x >= 250 && this->x <= 550 && this->y >= 180 && this->y <= 240) return 2;
    else if (this->x >= 320 && this->x <= 481 && this->y >= 300 && this->y <= 360) return 3;
    else return 4;
}

//Se imprime la interfaz del menú principal.
void Menu::imprimir_interfaz() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(200, 60, 600, 120, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(250, 180, 550, 240, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(320, 300, 481, 360, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(50, 210, 150, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(650, 210, 750, 310, al_map_rgb(255, 255, 255));

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(220, 220, 220), 400, 430, ALLEGRO_ALIGN_CENTRE, "SELECCIONE UNA OPCION");
    al_flip_display();
}

//---Contructor---//.
//Constructor con argumentos.
Menu::Menu(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana) {
    this->x, this->y, this->contador = 0;
    this->parpadeo = true;
    this->letra = formato;
    this->pantalla = ventana;
}

//---Métodos---//.
//Se genera el menú principal.
int Menu::generar_menu() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int retorno, auxiliar = 4, seleccion = 0;

    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            this->x = evento.mouse.x;
            this->y = evento.mouse.y;
            auxiliar = this->posicionado();

            if (auxiliar >= 1 && auxiliar <= 3) {
                if (!sonido) {
                    sonido = true;
                    al_play_sample(apuntado, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
            }
            else {
                sonido = false;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (auxiliar >= 1 && auxiliar <= 3) {
                retorno = auxiliar;
                continuar = true;
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
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
            retorno = 4;
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    al_destroy_sample(apuntado);
    return retorno;
}
#endif
