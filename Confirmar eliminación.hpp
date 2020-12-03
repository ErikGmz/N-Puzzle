//-----Compilación de la cabecera-----//.
#ifndef Confirmar_eliminación_hpp
#define Confirmar_eliminación_hpp

//-----Clase 'Confirmar'-----//.
class Confirmar {
private:
	//---Atributos---//.
	int x, y;
	ALLEGRO_FONT* letra;
	ALLEGRO_DISPLAY* pantalla;

	//---Funciones privadas---//.
	int posicionado(); //Se determina en cuál ícono se ha posicionado el cursor.
	void imprimir_interfaz(); //Se imprime la interfaz de la pantalla para confirmar la eliminación del registro.
public:
	//---Contructor---//.
	Confirmar(ALLEGRO_FONT*, ALLEGRO_DISPLAY*); //Constructor con argumentos.

	//---Métodos---//.
	int pantalla_confirmacion(); //Se genera la pantalla para confirmar la eliminación del registro.
};

//-----Métodos de la clase 'Confirmar'-----//.
//---Funciones privadas---//.
//Se determina en cuál ícono se ha posicionado el cursor.
int Confirmar::posicionado() {
    if (this->x >= 270 && this->x <= 530 && this->y >= 200 && this->y <= 260) return 1;
    else if (this->x >= 270 && this->x <= 530 && this->y >= 360 && this->y <= 420) return 2;
    else return 3;
}

//Se imprime la interfaz de la pantalla para confirmar la eliminación del registro.
void Confirmar::imprimir_interfaz() {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(this->letra, al_map_rgb(247, 188, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "CONFIRME LA ELIMINACION");
	al_draw_text(this->letra, al_map_rgb(247, 188, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "DEL REGISTRO");
	al_draw_filled_rectangle(270, 200, 530, 260, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(270, 360, 530, 420, al_map_rgb(255, 255, 255));

	al_flip_display();
}

//---Contructor---//.
//Constructor con argumentos.
Confirmar::Confirmar(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana) {
    this->x, this->y;
    this->letra = formato;
    this->pantalla = ventana;
}

//---Métodos---//.
//Se genera la pantalla para confirmar la eliminación del registro.
int Confirmar::pantalla_confirmacion() {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
	ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
	al_reserve_samples(3);

	bool continuar = false, reanudar, sonido = false;
	int auxiliar = 3, retorno;

	al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());

	this->imprimir_interfaz();
	while (!continuar) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			this->x = evento.mouse.x;
			this->y = evento.mouse.y;
			auxiliar = this->posicionado();

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
					this->imprimir_interfaz();
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