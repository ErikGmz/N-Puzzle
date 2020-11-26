//-----Compilación de la cabecera-----//.
#ifndef Inicio_hpp
#define Inicio_hpp

//-----Funciones-----//.
//Se imprimen los elementos de la interfaz.
void imprimir_texto(ALLEGRO_FONT* letra, int &contador, bool &parpadeo){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(100, 50, 700, 170, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(140, 230, 240, 330, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(320, 250, 380, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(460, 250, 520, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(600, 250, 660, 310, al_map_rgb(255, 255, 255));

    if(contador == 67){
        if(parpadeo){
            parpadeo = false;
        }
        else{
            parpadeo = true;
        }
        contador = 0;
    }
    if(parpadeo) al_draw_text(letra, al_map_rgb(245, 206, 170), 403, 400, ALLEGRO_ALIGN_CENTRE, "'PRESIONE ENTER'");
    al_flip_display();
}

//Se imprime la interfaz para la pantalla de título.
void imprimir_titulo(ALLEGRO_DISPLAY* pantalla, ALLEGRO_FONT* letra){
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    bool continuar = false, reanudar, parpadeo;
    int contador = 0;

    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while(!continuar){
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch(evento.type){
        case ALLEGRO_EVENT_KEY_DOWN:
            if(evento.keyboard.keycode == ALLEGRO_KEY_ENTER){
                /*al_play_sample(click, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.3);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.3);*/
                continuar = true;
            } 
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while(!reanudar){
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if(evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN){
                    imprimir_texto(letra, ++contador, parpadeo);
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            ++contador;
            imprimir_texto(letra, contador, parpadeo);
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
}
#endif