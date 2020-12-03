//-----Compilación de la cabecera-----//.
#ifndef Menú_récords_hpp
#define Menú_récords_hpp
#include "Sistema archivos.hpp"

//-----Clase 'Menú_récords'-----//.
class Menu_records {
private:
	//---Atributos---//.
	int x, y;
	ALLEGRO_DISPLAY* pantalla;

	//---Funciones privadas---//.
	int posicionado(); //Se determina en cuál ícono se ha posicionado el cursor.
	void mostrar_registro(ALLEGRO_FONT*); //Se muestran los datos de cada jugador dentro del ranking.
	void imprimir_interfaz(); //Se imprime la interfaz del menú de récords.
public:
	//---Contructor---//.
	Menu_records(ALLEGRO_DISPLAY*); //Constructor con argumento.

	//---Métodos---//.
	int menu_records(); //Se genera el menú de récords.
};

//-----Métodos de la clase 'Menú_récords'-----//.
//---Funciones privadas---//.
//Se determina en cuál ícono se ha posicionado el cursor.
int Menu_records::posicionado() {
	if (this->x >= 65 && this->x <= 121 && this->y >= 468 && this->y <= 525) return 1;
	else if (this->x >= 360 && this->x <= 710 && this->y >= 468 && this->y <= 525) return 2;
	else return 3;
}

//Se muestran los datos de cada jugador dentro del ranking.
void Menu_records::mostrar_registro(ALLEGRO_FONT* letra) {
	fstream archivo("registro.dat", ios::binary | ios::in);
	ALLEGRO_FONT* menor = al_load_font("Fonts/slkscre.ttf", 23, NULL);
	int contador = 0;

	if (archivo) {
		Datos_Guardar* aux = new Datos_Guardar;

		archivo.read(reinterpret_cast <char*>(aux), sizeof(Datos_Guardar));
		while (!archivo.eof()) {
			if (contador < 7) {
				al_draw_text(menor, al_map_rgb(230, 197, 252), 263, 125 + contador * 45, ALLEGRO_ALIGN_CENTRE, aux->nombre);
				al_draw_text(letra, al_map_rgb(202, 255, 175), 460, 123 + contador * 45, ALLEGRO_ALIGN_CENTRE, to_string(aux->puntaje).c_str());
				al_draw_text(menor, al_map_rgb(255, 197, 168), 657, 127 + contador* 45, ALLEGRO_ALIGN_CENTRE, aux->fecha);
				contador++;
			}
			else {
				break;
			}
			archivo.read(reinterpret_cast <char*>(aux), sizeof(Datos_Guardar));
		}
		delete aux;
	}
	if (contador < 7) {
		for (int i = contador; i < 7; i++) {
			al_draw_text(letra, al_map_rgb(230, 197, 252), 263, 125 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
			al_draw_text(letra, al_map_rgb(202, 255, 175), 460, 123 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
			al_draw_text(letra, al_map_rgb(255, 197, 168), 657, 127 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
		}
	}

	archivo.close();
	al_destroy_font(menor);
}

//Se imprime la interfaz del menú de récords.
void Menu_records::imprimir_interfaz() {
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
	this->mostrar_registro(letra);

	al_draw_filled_rectangle(65, 458, 121, 515, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(360, 458, 710, 515, al_map_rgb(255, 255, 255));
	al_flip_display();

	al_destroy_font(titulo); al_destroy_font(letra);
}

//---Contructor---//.
//Constructor con argumentos.
Menu_records::Menu_records(ALLEGRO_DISPLAY* ventana) {
    this->x, this->y = 0;
    this->pantalla = ventana;
}

//---Métodos---//.
//Se genera el menú principal.
int Menu_records::menu_records() {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
	ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
	al_reserve_samples(3);

	bool continuar = false, reanudar, sonido = false;
	int auxiliar = 3, retorno;

	al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
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