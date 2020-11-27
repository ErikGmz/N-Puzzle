//-----Compilación de la cabecera-----//.
#ifndef Confirmar_eliminación_hpp
#define Confirmar_eliminación_hpp

//-----Funciones-----//.
//Se determina en cuál ícono, del menú para confirmar la eliminación del registro, se ha posicionado el cursor.
int posicionado5(int x, int y) {
	if (x >= 270 && x <= 530 && y >= 200 && y <= 260) return 1;
	else if (x >= 270 && x <= 530 && y >= 360 && y <= 420) return 2;
	else return 3;
}

//Se imprimen los elementos de la interfaz.
void mostrar_elementos(ALLEGRO_FONT* fuente) {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(fuente, al_map_rgb(247, 188, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "CONFIRME LA ELIMINACION");
	al_draw_text(fuente, al_map_rgb(247, 188, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "DEL REGISTRO");
	al_draw_filled_rectangle(270, 200, 530, 260, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(270, 360, 530, 420, al_map_rgb(255, 255, 255));

	al_flip_display();
}

//Se imprime el menú para confirmar la eliminación del registro.
int imprimir_confirmacion(ALLEGRO_DISPLAY* pantalla, ALLEGRO_FONT* fuente) {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	bool continuar = false, reanudar, sonido = false;
	int x = 0, y = 0, auxiliar = 3, retorno;

	al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());

	mostrar_elementos(fuente);
	while (!continuar) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = posicionado5(x, y);

			if (auxiliar >= 1 && auxiliar <= 2) {
				if (!sonido) {
					sonido = true;
					//al_play_sample(opcion, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
				}
			}
			else {
				sonido = false;
			}
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if (auxiliar >= 1 && auxiliar <= 2) {
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
			while (!reanudar) {
				ALLEGRO_EVENT evento2;
				al_wait_for_event(fila_evento, &evento2);

				if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
					mostrar_elementos(fuente);
					reanudar = true;
				}
			}
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			retorno = 3;
			continuar = true;
			break;
		}
	}
	al_destroy_event_queue(fila_evento);
	return retorno;
}
#endif