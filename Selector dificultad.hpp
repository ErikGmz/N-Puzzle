//-----Compilación de la cabecera-----//.
#ifndef Selector_dificultad_hpp
#define Selector_dificultad_hpp

//-----Clase 'Dificultad'-----//.
class Dificultad {
private:
	//---Atributos---//.
	int x, y;
	ALLEGRO_FONT* letra;
	ALLEGRO_DISPLAY* pantalla;

	//---Funciones privadas---//.
	int posicionado(); //Se determina en cuál ícono se ha posicionado el cursor.
	void imprimir_interfaz(); //Se imprime la interfaz del selector de dificultad.
public:
	//---Contructor---//.
	Dificultad(ALLEGRO_FONT*, ALLEGRO_DISPLAY*); //Constructor con argumentos.

	//---Métodos---//.
	int generar_selector_dificultad(); //Se genera la pantalla del selector de dificultad.
};

//-----Métodos de la clase 'Dificultad'-----//.
//---Funciones privadas---//.
//Se determina en cuál ícono se ha posicionado el cursor.
int Dificultad::posicionado() {
	if (this->x >= 300 && this->x <= 500 && this->y >= 150 && this->y <= 210) return 1;
	else if (this->x >= 290 && this->x <= 510 && this->y >= 280 && this->y <= 340) return 2;
	else if (this->x >= 280 && this->x <= 520 && this->y >= 410 && this->y <= 470) return 3;
	else if (this->x >= 64 && this->x <= 122 && this->y >= 409 && this->y <= 471) return 4;
	else return 5;
}

//Se imprime la interfaz del selector de dificultad.
void Dificultad::imprimir_interfaz() {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(this->letra, al_map_rgb(189, 252, 166), 400, 50, ALLEGRO_ALIGN_CENTRE, "SELECCIONE LA DIFICULTAD");

	al_draw_filled_rectangle(300, 150, 500, 210, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(290, 280, 510, 340, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(280, 410, 520, 470, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(65, 410, 121, 470, al_map_rgb(255, 255, 255));

	al_flip_display();
}

//---Contructor---//.
//Constructor con argumentos.
Dificultad::Dificultad(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana) {
	this->x, this->y = 0;
	this->letra = formato;
	this->pantalla = ventana;
}

//---Métodos---//.
//Se genera la pantalla del selector de dificultad.
int Dificultad::generar_selector_dificultad() {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
	ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
	al_reserve_samples(3);

	bool continuar = false, reanudar, sonido = false;
	int auxiliar = 5, retorno;

	al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());

	this->imprimir_interfaz();
	while (!continuar) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = this->posicionado();

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
					this->imprimir_interfaz();
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