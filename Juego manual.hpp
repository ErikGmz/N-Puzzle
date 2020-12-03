//-----Compilación de la cabecera-----//.
#ifndef Juego_manual_hpp
#define Juego_manual_hpp

//-----Clase 'Manual'-----//.
class Manual {
private:
	//---Atributos---//.
	int x, y, dificultad, tiempo;
	ALLEGRO_DISPLAY* pantalla;
	Datos* jugador_actual;
	vector<vector<string>> puzzle_inicio, puzzle_final;

	//---Funciones privadas---//.
	int posicionado(); //Se determina en cuál ícono se ha posicionado el cursor.
	int generar_numero_aleatorio(); //Se genera un valor aleatorio según la dificultad de la partida. 
	vector<vector<string>> generar_inicio(); //Se genera el puzzle inicial de forma aleatoria.
	vector<vector<string>> generar_meta(); //Se genera el puzzle meta de forma aleatoria.
	char numero_a_caracter(int); //Se retorna un dígito en forma de caracter.
	char* formato_tiempo(); //Se convierte una cifra en un formato de tiempo.
	void imprimir_interfaz(); //Se imprime la interfaz de la partida manual.
public:
	//---Contructor---//.
	Manual(ALLEGRO_DISPLAY*, Datos*, int); //Constructor con argumentos.

	//Getters.
	inline Datos datos_actuales() { return *jugador_actual; }
	inline int tiempo_ocupado() { return tiempo; }

	//---Métodos---//.
	void generar_partida(); //Se genera la pantalla de la partida manual.
};

//-----Métodos de la clase 'Manual'-----//.
//---Funciones privadas---//.
//Se verifica si el cursor se ha posicionado sobre alguna ficha a desplazar o algún ícono.
int Manual::posicionado() {
	if (this->x >= 470 && this->x <= 750 && this->y >= 440 && this->y <= 500) return 1;
	return 2;
}

//Se genera un valor aleatorio según la dificultad de la partida.
int Manual::generar_numero_aleatorio() {
	switch (this->dificultad) {
	case 3:
		return (rand() % 9); break;
	case 4:
		return (rand() % 16); break;
	case 5:
		return (rand() % 25); break;
	default:
		return 0; break;
	}
}

//Se genera el puzzle inicial de forma aleatoria.
vector<vector<string>> Manual::generar_inicio() {
	vector<vector<string>> auxiliar(this->dificultad, vector<string>(this->dificultad, ""));
	string* random;
	int contador_y = 0, contador_x = 0;

	do {
		bool valor_repetido = false;
		random = new string;
		*random = to_string(this->generar_numero_aleatorio());

		for (int i = 0; i < this->dificultad; i++) {
			for (int j = 0; j < this->dificultad; j++) {
				if (!(i == contador_x && j == contador_y)) {
					if (*random == auxiliar[i][j]) {
						valor_repetido = true;
					}
				}
				if (valor_repetido) {
					i = 0; j = 0;
					*random = to_string(this->generar_numero_aleatorio());
					valor_repetido = false;
				}
			}
		}

		auxiliar[contador_x][contador_y++] = *random;
		if (contador_y == this->dificultad) {
			contador_y = 0;
			contador_x++;
		}
		delete random;
	} while (contador_y < this->dificultad - 1 && contador_x < this->dificultad - 1);
	return auxiliar;
}

//Se genera el puzzle meta de forma aleatoria.
vector<vector<string>> Manual::generar_meta() {
	vector<vector<string>> auxiliar(this->dificultad, vector<string>(this->dificultad, ""));
	string* random;
	int contador_y = 0, contador_x = 0;

	do {
		do {
			bool valor_repetido = false;
			random = new string;
			*random = to_string(this->generar_numero_aleatorio());

			for (int i = 0; i < this->dificultad; i++) {
				for (int j = 0; j < this->dificultad; j++) {
					if (!(i == contador_x && j == contador_y)) {
						if (*random == auxiliar[i][j]) {
							valor_repetido = true;
						}
					}
					if (valor_repetido) {
						i = 0; j = 0;
						*random = to_string(this->generar_numero_aleatorio());
						valor_repetido = false;
					}
				}
			}

			auxiliar[contador_x][contador_y++] = *random;
			if (contador_y == this->dificultad) {
				contador_y = 0;
				contador_x++;
			}
			delete random;
			valor_repetido = false;
		} while (contador_y < this->dificultad - 1 && contador_x < this->dificultad - 1);
	} while (this->puzzle_inicio == this->puzzle_final);
	return auxiliar;
}

//Se retorna un dígito en forma de caracter.
char Manual::numero_a_caracter(int digito) {
	switch (digito) {
	case 0: return '0'; break;
	case 1: return '1'; break;
	case 2: return '2'; break;
	case 3: return '3'; break;
	case 4: return '4'; break;
	case 5: return '5'; break;
	case 6: return '6'; break;
	case 7: return '7'; break;
	case 8: return '8'; break;
	case 9: return '9'; break;
	default: return 'a'; break;
	}
}

//Se convierte una cifra en un formato de tiempo.
char* Manual::formato_tiempo() {
	string formato;
	int minutos = 0, segundos = 0, horas = 0;
	int auxiliar = this->tiempo;

	while (auxiliar >= 3600) {
		horas++;
		auxiliar -= 3600;
	}
	while (auxiliar >= 60) {
		minutos++;
		auxiliar -= 60;
	}
	if (auxiliar > 0) {
		segundos += auxiliar;
	}
	if (horas < 10) {
		formato.push_back('0');
		formato.push_back(numero_a_caracter(horas));
	}
	else {
		formato.push_back(numero_a_caracter(horas / 10));
		formato.push_back(numero_a_caracter(horas % 10));
	}
	formato.push_back(':');

	if (minutos < 10) {
		formato.push_back('0');
		formato.push_back(numero_a_caracter(minutos));
	}
	else {
		formato.push_back(numero_a_caracter(minutos / 10));
		formato.push_back(numero_a_caracter(minutos % 10));
	}
	formato.push_back(':');

	if (segundos < 10) {
		formato.push_back('0');
		formato.push_back(numero_a_caracter(segundos));
	}
	else {
		formato.push_back(numero_a_caracter(segundos / 10));
		formato.push_back(numero_a_caracter(segundos % 10));
	}

	char* retorno = new char[10];
	strcpy_s(retorno, 10, formato.c_str());
	return retorno;
}

//Se imprime la interfaz de la partida manual.
void Manual::imprimir_interfaz() {
	this->tiempo++;
	string* auxiliar = new string;
	ALLEGRO_FONT* letra = al_load_font("Fonts/slkscre.ttf", 32, NULL);

	switch (this->dificultad) {
	case 3: *auxiliar = "FACIL"; break;
	case 4: *auxiliar = "NORMAL"; break;
	case 5: *auxiliar = "DIFICIL"; break;
	}

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(letra, al_map_rgb(250, 201, 136), 425, 20, ALLEGRO_ALIGN_CENTRE, "DIFICULTAD");
	al_draw_text(letra, al_map_rgb(252, 252, 164), 425, 60, ALLEGRO_ALIGN_CENTRE, auxiliar->c_str());
	al_draw_text(letra, al_map_rgb(179, 189, 250), 150, 20, ALLEGRO_ALIGN_CENTRE, "JUGADOR");
	al_draw_text(letra, al_map_rgb(233, 188, 255), 150, 60, ALLEGRO_ALIGN_CENTRE, this->jugador_actual->nombre.c_str());
	al_draw_text(letra, al_map_rgb(140, 252, 185), 670, 20, ALLEGRO_ALIGN_CENTRE, "TIEMPO");
	al_draw_text(letra, al_map_rgb(197, 255, 180), 670, 60, ALLEGRO_ALIGN_CENTRE, this->formato_tiempo());
	delete auxiliar;

	switch (this->dificultad) {
	case 3: al_draw_filled_rectangle(200, 200, 353, 353, al_map_rgb(255, 255, 255)); break;
	case 4: al_draw_filled_rectangle(200, 200, 403, 403, al_map_rgb(255, 255, 255)); break;
	case 5: al_draw_filled_rectangle(200, 200, 453, 453, al_map_rgb(255, 255, 255)); break;
	}

	al_draw_filled_rectangle(50, 440, 280, 500, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(470, 440, 750, 500, al_map_rgb(255, 255, 255));

	for (int i = 0; i < this->dificultad; i++) {
		for (int j = 0; j < this->dificultad; j++) {
			al_draw_filled_rectangle(200 + i * 50 + 3, 200 + j * 50 + 3, 200 + (i + 1) * 50, 200 + (j + 1) * 50, al_map_rgb(25, 177, 201));
		}
	}
	al_flip_display();
	al_destroy_font(letra);
}

//---Contructor---//.
//Constructor con argumentos.
Manual::Manual(ALLEGRO_DISPLAY* ventana, Datos *jugador, int dificul) {
	this->x = this->y = 0;
	this->tiempo = -1;
	this->dificultad = dificul;
	this->pantalla = ventana;
	this->jugador_actual = jugador;
	this->puzzle_inicio = this->generar_inicio();
	this->puzzle_final = this->generar_meta();
}

//---Métodos---//.
//Se genera la pantalla de la partida manual.
void Manual::generar_partida() {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	ALLEGRO_TIMER* temporizador = al_create_timer(1);
	ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
	ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
	al_reserve_samples(3);

	bool continuar = false, reanudar, sonido = false;
	int auxiliar = 2, veces_ayuda = 0;

	al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());
	al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
	al_start_timer(temporizador);

	this->imprimir_interfaz();
	while (!continuar) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = this->posicionado();

			if (auxiliar == 1) {
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
			if (auxiliar == 1) {
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
					this->imprimir_interfaz();
					reanudar = true;
				}
			}
			break;
		case ALLEGRO_EVENT_TIMER:
			this->imprimir_interfaz();
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			jugador_actual->puntaje = -1;
			return;
			break;
		}
	}
	al_destroy_event_queue(fila_evento);

	switch (dificultad) {
	case 3:
		if (tiempo < 60) {
			jugador_actual->puntaje = 10000 - 50 * veces_ayuda;
		}
		else if (tiempo < 120) {
			jugador_actual->puntaje = 5000 - 50 * veces_ayuda;
		}
		else if (tiempo < 180) {
			jugador_actual->puntaje = 2500 - 50 * veces_ayuda;
		}
		else if (tiempo < 240) {
			jugador_actual->puntaje = 1250 - 50 * veces_ayuda;
		}
		else {
			jugador_actual->puntaje = 0;
		}
		break;
	case 4:
		if (tiempo < 60) {
			jugador_actual->puntaje = 30000 - 50 * veces_ayuda;
		}
		else if (tiempo < 120) {
			jugador_actual->puntaje = 15000 - 50 * veces_ayuda;
		}
		else if (tiempo < 180) {
			jugador_actual->puntaje = 7500 - 50 * veces_ayuda;
		}
		else if (tiempo < 240) {
			jugador_actual->puntaje = 3750 - 50 * veces_ayuda;
		}
		else if (tiempo < 300) {
			jugador_actual->puntaje = 1875 - 50 * veces_ayuda;
		}
		else if (tiempo < 360) {
			jugador_actual->puntaje = 937 - 50 * veces_ayuda;
		}
		else {
			jugador_actual->puntaje = 0;
		}
		break;
	case 5:
		if (tiempo < 60) {
			jugador_actual->puntaje = 60000 - 50 * veces_ayuda;
		}
		else if (tiempo < 120) {
			jugador_actual->puntaje = 40000 - 50 * veces_ayuda;
		}
		else if (tiempo < 180) {
			jugador_actual->puntaje = 30000 - 50 * veces_ayuda;
		}
		else if (tiempo < 240) {
			jugador_actual->puntaje = 10000 - 50 * veces_ayuda;
		}
		else if (tiempo < 300) {
			jugador_actual->puntaje = 8000 - 50 * veces_ayuda;
		}
		else if (tiempo < 360) {
			jugador_actual->puntaje = 4000 - 50 * veces_ayuda;
		}
		else if (tiempo < 420) {
			jugador_actual->puntaje = 2000 - 50 * veces_ayuda;
		}
		else if (tiempo < 480) {
			jugador_actual->puntaje = 1000 - 50 * veces_ayuda;
		}
		else {
			jugador_actual->puntaje = 0;
		}
		break;
	}
	if (jugador_actual->puntaje < 0) jugador_actual->puntaje = 0;
}
#endif