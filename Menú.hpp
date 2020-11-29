//-----Compilación de la cabecera-----//.
#ifndef Menú_hpp
#define Menú_hpp

//-----Funciones-----//.
//Se determina en cuál ícono se ha posicionado el cursor.
int posicionado(int x, int y) {
    if (x >= 200 && x <= 600 && y >= 60 && y <= 120) return 1;
    else if (x >= 250 && x <= 550 && y >= 180 && y <= 240) return 2;
    else if (x >= 320 && x <= 481 && y >= 300 && y <= 360) return 3;
    else return 4;
}

//Se imprimen los elementos del menú principal.
void imprimir_elementos(ALLEGRO_FONT* letra, int& contador, bool& parpadeo) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(200, 60, 600, 120, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(250, 180, 550, 240, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(320, 300, 481, 360, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(50, 210, 150, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(650, 210, 750, 310, al_map_rgb(255, 255, 255));

    if (contador == 55) {
        if (parpadeo) {
            parpadeo = false;
        }
        else {
            parpadeo = true;
        }
        contador = 0;
    }
    if (parpadeo) al_draw_text(letra, al_map_rgb(220, 220, 220), 400, 430, ALLEGRO_ALIGN_CENTRE, "SELECCIONE UNA OPCION");
    al_flip_display();
}

//Se imprime la interfaz del menú principal.
int imprimir_menu(ALLEGRO_DISPLAY* pantalla, ALLEGRO_FONT* letra) {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false, parpadeo;
    int x = 0, y = 0, retorno, auxiliar = 4, seleccion = 0, contador = 0;

    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = evento.mouse.x;
            y = evento.mouse.y;
            auxiliar = posicionado(x, y);

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
                    imprimir_elementos(letra, ++contador, parpadeo);
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            imprimir_elementos(letra, ++contador, parpadeo);
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
