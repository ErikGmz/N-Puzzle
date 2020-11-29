//-----Compilación de la cabecera-----//.
#ifndef Selector_dificultad_hpp
#define Selector_dificultad_hpp

//-----Funciones-----//.
//Se determina en cuál ícono, del menú para la selección de dificultades, se ha posicionado el cursor.
int posicionado3(int x, int y) {
	if (x >= 300 && x <= 500 && y >= 150 && y <= 210) return 1;
	else if (x >= 290 && x <= 510 && y >= 280 && y <= 340) return 2;
	else if (x >= 280 && x <= 520 && y >= 410 && y <= 470) return 3;
	else if (x >= 64 && x <= 122 && y >= 409 && y <= 471) return 4;
	else return 5;
}

//Se imprimen los elementos de la interfaz.
void escribir_elementos(ALLEGRO_FONT* fuente) {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(fuente, al_map_rgb(189, 252, 166), 400, 50, ALLEGRO_ALIGN_CENTRE, "SELECCIONE LA DIFICULTAD");

	al_draw_filled_rectangle(300, 150, 500, 210, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(290, 280, 510, 340, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(280, 410, 520, 470, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(65, 410, 121, 470, al_map_rgb(255, 255, 255));

	al_flip_display();
}

//Se imprime el selector de dificultad.
int imprimir_selector(ALLEGRO_DISPLAY* pantalla, ALLEGRO_FONT* fuente) {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
	ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
	al_reserve_samples(3);

	bool continuar = false, reanudar, sonido = false;
	int x = 0, y = 0, auxiliar = 5, retorno;

	al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());

	escribir_elementos(fuente);
	while (!continuar) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = posicionado3(x, y);

			if (auxiliar >= 1 && auxiliar <= 4) {
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
			if (auxiliar >= 1 && auxiliar <= 4) {
				al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

				al_rest(0.5);
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_flip_display();
				al_rest(0.5);
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
					escribir_elementos(fuente);
					reanudar = true;
				}
			}
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			retorno = 5;
			continuar = true;
			break;
		}
	}
	al_destroy_event_queue(fila_evento);
	al_destroy_sample(avance);
	al_destroy_sample(apuntado);
	return retorno;
}
#endif