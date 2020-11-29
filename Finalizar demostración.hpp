//-----Compilación de la cabecera-----//.
#ifndef Finalizar_demostración_hpp
#define Finalizar_demostración_hpp

//-----Funciones-----//.
//Se imprimen los elementos de la interfaz.
void mostrar_escritura(ALLEGRO_FONT* letra, int& contador, bool& parpadeo) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(letra, al_map_rgb(249, 192, 249), 400, 50, ALLEGRO_ALIGN_CENTRE, "DEMOSTRACION FINALIZADA");

    if (contador == 55) {
        if (parpadeo) {
            parpadeo = false;
        }
        else {
            parpadeo = true;
        }
        contador = 0;
    }
    if (parpadeo) al_draw_text(letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
}

//Se imprime la interfaz para indicar el fin de la demostración de partidas.
bool imprimir_fin_demostracion(ALLEGRO_DISPLAY* pantalla, ALLEGRO_FONT* letra) {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar, parpadeo;
    int contador = 0;

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
                    mostrar_escritura(letra, ++contador, parpadeo);
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            mostrar_escritura(letra, ++contador, parpadeo);
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