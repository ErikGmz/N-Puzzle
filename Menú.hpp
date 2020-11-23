//-----Compilación de la cabecera-----//.
#ifndef Menú_hpp
#define Menú_hpp

//-----Funciones-----//.
//Se determina en cuál ícono se ha posicionado el cursor.
int posicionado(int x, int y){
    if(x >= 200 && x <= 600 && y >= 50 && y <= 110) return 1;
    else if(x >= 250 && x <= 550 && y >= 170 && y <= 230) return 2;
    else if(x >= 320 && x <= 481 && y >= 290 && y <= 350) return 3;
    else return 4;
}

//Se imprimen los elementos del menú principal.
void imprimir_elementos(ALLEGRO_FONT* letra, int seleccion){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(200, 50, 600, 110, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(250, 170, 550, 230, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(320, 290, 481, 350, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(50, 200, 150, 300, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(650, 200, 750, 300, al_map_rgb(255, 255, 255));
    al_draw_text(letra, al_map_rgb(245, 206, 170), 400, 410, ALLEGRO_ALIGN_CENTRE, "'SELECCIONE UNA OPCION'");
    al_flip_display();
}

//Se imprime la interfaz del menú principal.
int imprimir_menu(ALLEGRO_DISPLAY* pantalla, ALLEGRO_FONT* letra){
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    bool continuar = false, reanudar, sonido = false;
    int x = 0, y = 0, retorno, auxiliar = 4;

    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());
    imprimir_elementos(letra, auxiliar);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = evento.mouse.x;
            y = evento.mouse.y;
            auxiliar = posicionado(x, y);

            if(auxiliar >= 1 && auxiliar <= 3){
                if(!sonido){
                    sonido = true;
                    //al_play_sample(opcion, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
            }
            else{
                sonido = false;
            }
            imprimir_elementos(letra, auxiliar);
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if(auxiliar >= 1 && auxiliar <= 3){
                retorno = auxiliar;
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    imprimir_elementos(letra, auxiliar);
                    reanudar = true;
                }
            }
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    return retorno;
}
#endif
