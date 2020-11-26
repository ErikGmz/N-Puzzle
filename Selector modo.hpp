//-----Compilación de la cabecera-----//.
#ifndef Selector_modo_hpp
#define Selector_modo_hpp

//-----Funciones-----//.
//Se determina en cuál ícono, del menú para la selección del modo, se ha posicionado el cursor.
int posicionado4(int x, int y) {
	if (x >= 290 && x <= 510 && y >= 200 && y <= 260) return 1;
	else if (x >= 270 && x <= 530 && y >= 360 && y <= 420) return 2;
	else if (x >= 65 && x <= 121 && y >= 360 && y <= 420) return 3;
	else return 4;
}

//Se imprimen los elementos de la interfaz.
void colocar_elementos(ALLEGRO_FONT* fuente, int selector){
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(fuente, al_map_rgb(245, 206, 170), 400, 50, ALLEGRO_ALIGN_CENTRE, "'SELECCIONE EL MODO'");

	al_draw_filled_rectangle(290, 200, 510, 260, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(270, 360, 530, 420, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(65, 360, 121, 420, al_map_rgb(255, 255, 255));

	switch(selector){
	case 1: al_draw_rectangle(289, 199, 511, 261, al_map_rgb(255, 255, 81), 5.0); break;
	case 2: al_draw_rectangle(269, 359, 531, 421, al_map_rgb(255, 255, 81), 5.0); break;
	case 3: al_draw_rectangle(64, 359, 122, 421, al_map_rgb(255, 255, 81), 5.0); break;
	}

	al_flip_display();
}

//Se imprime el selector de modos.
int imprimir_modos(ALLEGRO_DISPLAY* pantalla, ALLEGRO_FONT* fuente){
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	bool continuar = false, reanudar, sonido = false;
	int x = 0, y = 0, auxiliar = 4, retorno;

	al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());

	colocar_elementos(fuente, auxiliar);
	while(!continuar){
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch(evento.type){
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = posicionado4(x, y);

			if(auxiliar >= 1 && auxiliar <= 4){
				if(!sonido){
					sonido = true;
					//al_play_sample(opcion, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
				}
			}
			else{
				sonido = false;
			}
			colocar_elementos(fuente, auxiliar);
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if(auxiliar >= 1 && auxiliar <= 4){
				/*al_play_sample(click, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

				al_rest(0.3);
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_flip_display();
				al_rest(0.3);*/
				retorno = auxiliar;
				continuar = true;
			}
			break;
		case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
			reanudar = false;
			while(!reanudar){
				ALLEGRO_EVENT evento2;
				al_wait_for_event(fila_evento, &evento2);

				if(evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN){
					colocar_elementos(fuente, auxiliar);
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