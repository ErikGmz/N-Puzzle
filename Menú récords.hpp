//-----Compilación de la cabecera-----//.
#ifndef Menú_récords_hpp
#define Menú_récords_hpp
#include "Sistema archivos.hpp"

//-----Funciones-----//.
//Se determina en cuál ícono, del menú de récords, se ha posicionado el cursor.
int posicionado2(int x, int y) {
	if (x >= 65 && x <= 121 && y >= 468 && y <= 525) return 1;
	else if (x >= 360 && x <= 710 && y >= 468 && y <= 525) return 2;
	else return 3;
}

//Se imprimen los elementos de la interfaz.
void agregar_elementos() {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	ALLEGRO_FONT* titulo = al_load_font("Fonts/slkscre.ttf", 35, NULL);
	ALLEGRO_FONT* letra = al_load_font("Fonts/slkscre.ttf", 25, NULL);

	al_draw_text(titulo, al_map_rgb(255, 163, 1), 400, 30, ALLEGRO_ALIGN_CENTRE, "RECORDS");
	al_draw_text(letra, al_map_rgb(253, 198, 104), 400, 80, ALLEGRO_ALIGN_CENTRE, "Lugar    Nombre    Puntaje     Fecha    ");
	al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 125, ALLEGRO_ALIGN_CENTRE, "1.-");
	al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 170, ALLEGRO_ALIGN_CENTRE, "2.-");
	al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 215, ALLEGRO_ALIGN_CENTRE, "3.-");
	al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 260, ALLEGRO_ALIGN_CENTRE, "4.-");
	al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 305, ALLEGRO_ALIGN_CENTRE, "5.-");
	al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 350, ALLEGRO_ALIGN_CENTRE, "6.-");
	al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 395, ALLEGRO_ALIGN_CENTRE, "7.-");
	mostrar_registro(letra);

	al_draw_filled_rectangle(65, 458, 121, 515, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(360, 458, 710, 515, al_map_rgb(255, 255, 255));
	al_flip_display();

	al_destroy_font(titulo); al_destroy_font(letra);
}

//Se imprime la tabla de los récords.
int imprimir_records(ALLEGRO_DISPLAY* pantalla) {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
	ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
	al_reserve_samples(3);

	bool continuar = false, reanudar, sonido = false;
	int x = 0, y = 0, auxiliar = 3, retorno;

	al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());

	agregar_elementos();
	while (!continuar) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = posicionado2(x, y);

			if (auxiliar >= 1 && auxiliar <= 2) {
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
			if (auxiliar >= 1 && auxiliar <= 2) {
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
					agregar_elementos();
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
	al_destroy_sample(avance);
	al_destroy_sample(apuntado);
	return retorno;
}
#endif