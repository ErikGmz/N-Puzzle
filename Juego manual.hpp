//-----Compilación de la cabecera-----//.
#ifndef Juego_manual_hpp
#define Juego_manual_hpp

//-----Funciones-----//.
//Se verifica si el cursor se ha posicionado sobre alguna ficha a desplazar.
int posicionado6(int x, int y) {
	if (x >= 470 && x <= 750 && y >= 440 && y <= 500) return 1;
	return 2;
}

//Se imprimen los elementos de la interfaz.
void interfaz_manual(Datos* jugador_actual, int dificultad, int& tiempo, vector<vector<string>> puzzle_inicio, vector<vector<string>> puzzle_meta) {
	string* auxiliar = new string;
	ALLEGRO_FONT* letra = al_load_font("Fonts/slkscre.ttf", 32, NULL);

	switch (dificultad) {
	case 3: *auxiliar = "FACIL"; break;
	case 4: *auxiliar = "NORMAL"; break;
	case 5: *auxiliar = "DIFICIL"; break;
	}

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(letra, al_map_rgb(250, 201, 136), 425, 20, ALLEGRO_ALIGN_CENTRE, "DIFICULTAD");
	al_draw_text(letra, al_map_rgb(252, 252, 164), 425, 60, ALLEGRO_ALIGN_CENTRE, auxiliar->c_str());
	al_draw_text(letra, al_map_rgb(179, 189, 250), 150, 20, ALLEGRO_ALIGN_CENTRE, "JUGADOR");
	al_draw_text(letra, al_map_rgb(233, 188, 255), 150, 60, ALLEGRO_ALIGN_CENTRE, jugador_actual->nombre.c_str());
	al_draw_text(letra, al_map_rgb(140, 252, 185), 670, 20, ALLEGRO_ALIGN_CENTRE, "TIEMPO");
	al_draw_text(letra, al_map_rgb(197, 255, 180), 670, 60, ALLEGRO_ALIGN_CENTRE, formato_tiempo(tiempo));
	delete auxiliar;
	
	switch (dificultad) {
	case 3: al_draw_filled_rectangle(200, 200, 353, 353, al_map_rgb(255, 255, 255)); break;
	case 4: al_draw_filled_rectangle(200, 200, 403, 403, al_map_rgb(255, 255, 255)); break;
	case 5: al_draw_filled_rectangle(200, 200, 453, 453, al_map_rgb(255, 255, 255)); break;
	}

	al_draw_filled_rectangle(50, 440, 280, 500, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(470, 440, 750, 500, al_map_rgb(255, 255, 255));

	for (int i = 0; i < dificultad; i++) {
		for (int j = 0; j < dificultad; j++) {
			al_draw_filled_rectangle(200 + i * 50 + 3, 200 + j * 50 + 3, 200 + (i + 1) * 50, 200 + (j + 1) * 50, al_map_rgb(25, 177, 201));
		}
	}
	al_flip_display();
	al_destroy_font(letra);
}

//Se genera un valor aleatorio según la dificultad de la partida.
int generar_numero_aleatorio(int dificultad) {
	switch (dificultad) {
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
vector<vector<string>> generar_puzzle(int dificultad) {
	vector<vector<string>> auxiliar(dificultad, vector<string>(dificultad, ""));
	string* random;
	int contador_y = 0, contador_x = 0;

	do {
		bool valor_repetido = false;
		random = new string;
		*random = to_string(generar_numero_aleatorio(dificultad));

		for (int i = 0; i < dificultad; i++) {
			for (int j = 0; j < dificultad; j++) {
				if (!(i == contador_x && j == contador_y)) {
					if (*random == auxiliar[i][j]) {
						valor_repetido = true;
					}
				}
				if (valor_repetido) {
					i = 0; j = 0;
					*random = to_string(generar_numero_aleatorio(dificultad));
					valor_repetido = false;
				}
			}
		}

		auxiliar[contador_x][contador_y++] = *random;
		if (contador_y == dificultad) {
			contador_y = 0;
			contador_x++;
		}
		delete random;
	} while (contador_y < dificultad - 1 && contador_x < dificultad - 1);
	return auxiliar;
}

//Se verifica si el puzzle meta es igual que el de inicio.
bool puzzles_iguales(vector<vector<string>> puzzle_inicio, vector<vector<string>> puzzle_meta, int dificultad) {
	for (int i = 0; i < dificultad; i++) {
		for (int j = 0; j < dificultad; j++) {
			if (puzzle_inicio[i][j] != puzzle_meta[i][j]) return false;
		}
	}
	return true;
}

//Se genera el puzzle meta de forma aleatoria.
vector<vector<string>> generar_puzzle_meta(vector<vector<string>> puzzle_inicio, int dificultad) {
	vector<vector<string>> auxiliar(dificultad, vector<string>(dificultad, ""));
	string* random;
	int contador_y = 0, contador_x = 0;

	do {
		do {
			bool valor_repetido = false;
			random = new string;
			*random = to_string(generar_numero_aleatorio(dificultad));

			for (int i = 0; i < dificultad; i++) {
				for (int j = 0; j < dificultad; j++) {
					if (!(i == contador_x && j == contador_y)) {
						if (*random == auxiliar[i][j]) {
							valor_repetido = true;
						}
					}
					if (valor_repetido) {
						i = 0; j = 0;
						*random = to_string(generar_numero_aleatorio(dificultad));
						valor_repetido = false;
					}
				}
			}

			auxiliar[contador_x][contador_y++] = *random;
			if (contador_y == dificultad) {
				contador_y = 0;
				contador_x++;
			}
			delete random;
			valor_repetido = false;
		} while (contador_y < dificultad - 1 && contador_x < dificultad - 1);
	} while (puzzles_iguales(puzzle_inicio, auxiliar, dificultad));
	return auxiliar;
}


//Se efectúa la partida manual.
void empezar_juego_manual(ALLEGRO_DISPLAY* pantalla, Datos* jugador_actual, int dificultad, int &tiempo) {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	ALLEGRO_TIMER* temporizador = al_create_timer(1);
	ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
	ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
	al_reserve_samples(3);

	bool continuar = false, reanudar, sonido = false;
	int x = 0, y = 0, auxiliar = 2, veces_ayuda = 0;

	vector<vector<string>> puzzle_inicio = generar_puzzle(dificultad);
	vector<vector<string>> puzzle_meta = generar_puzzle_meta(puzzle_inicio, dificultad);

	al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());
	al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
	al_start_timer(temporizador);

	interfaz_manual(jugador_actual, dificultad, tiempo, puzzle_inicio, puzzle_meta);
	while (!continuar) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = posicionado6(x, y);

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
					interfaz_manual(jugador_actual, dificultad, tiempo, puzzle_inicio, puzzle_meta);
					reanudar = true;
				}
			}
			break;
		case ALLEGRO_EVENT_TIMER:
			interfaz_manual(jugador_actual, dificultad, ++tiempo, puzzle_inicio, puzzle_meta);
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