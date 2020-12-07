#include "Juego.hpp"

bool ordenamiento_descendente(Jugador a, Jugador b) {
    return (a.getPuntaje() > b.getPuntaje());
}

//-------------------------------------Métodos Públicos de Clase---------------------------------//

Juego::Juego(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana) {
    this->tiempo = 0;
    this->x = 0;
    this->y = 0;
    this->contador = 0;
    this->parpadeo = true;
    this->letra = formato;
    this->pantalla = ventana;
}

bool Juego::pantalla_titulo() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
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
                    this->imprimir_interfaz_titulo();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_titulo();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return false;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    return true;
}

int Juego::pantalla_menu() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int retorno, auxiliar = 4, seleccion = 0;

    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            this->x = evento.mouse.x;
            this->y = evento.mouse.y;
            auxiliar = this->posicionado_menu();

            if (auxiliar >= 1 && auxiliar <= 3) {
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
            if (auxiliar >= 1 && auxiliar <= 3) {
                retorno = auxiliar;
                continuar = true;
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_menu();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_menu();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            retorno = 4;
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    al_destroy_sample(apuntado);
    return retorno;
}

int Juego::pantalla_menu_Dificultad() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int auxiliar = 5, retorno;

    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());

    this->imprimir_interfaz_menu_Dificultad();
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = evento.mouse.x;
            y = evento.mouse.y;
            auxiliar = this->posicionado_menu_Dificultad();

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
                    this->imprimir_interfaz_menu_Dificultad();
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

int Juego::pantalla_menu_Modo() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int auxiliar = 4, retorno;

    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());

    this->imprimir_interfaz_menu_Modo();
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = evento.mouse.x;
            y = evento.mouse.y;
            auxiliar = this->posicionado_menu_Modo();

            if (auxiliar >= 1 && auxiliar <= 3) {
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
            if (auxiliar >= 1 && auxiliar <= 3) {
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
                    this->imprimir_interfaz_menu_Modo();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            retorno = 4;
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_destroy_sample(avance);
    al_destroy_sample(apuntado);
    return retorno;
}

int Juego::pantalla_Records() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int auxiliar = 3, retorno;

    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());

    this->imprimir_interfaz_Records();
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = evento.mouse.x;
            y = evento.mouse.y;
            auxiliar = this->posicionado_Records();

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
                    this->imprimir_interfaz_Records();
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

int Juego::pantalla_confirmacion() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int auxiliar = 3, retorno;

    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());

    this->imprimir_interfaz_confirmacion();
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            this->x = evento.mouse.x;
            this->y = evento.mouse.y;
            auxiliar = this->posicionado_confirmacion();

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
                    this->imprimir_interfaz_confirmacion();
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

bool Juego::pantalla_eliminacion() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    this->eliminar_registro();
    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
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
                    this->imprimir_interfaz_eliminacion();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_eliminacion();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return false;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_stop_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    return true;
}

bool Juego::pantalla_finJuego(Jugador jugador_actual) {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance1 = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    this->actualizar_archivo(jugador_actual);
    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                al_play_sample(avance1, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

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
                    this->imprimir_interfaz_finJuego(jugador_actual);
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_finJuego(jugador_actual);
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return false;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance1);
    return true;
}

void Juego::setTiempo(int tiempo) {
    this->tiempo = tiempo;
    return;
}

void Juego::setDificultad(int dificultad) {
    this->dificultad = dificultad;
    return;
}

void Juego::pantalla_salida() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
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
                    this->imprimir_interfaz_salida();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_salida();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);

}

void Juego::modo_manual(Jugador &jugador_actual) {
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

	this->imprimir_interfaz_modo_manual(jugador_actual);
	while (!continuar) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = this->posicionado_modo_manual();

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
					this->imprimir_interfaz_modo_manual(jugador_actual);
					reanudar = true;
				}
			}
			break;
		case ALLEGRO_EVENT_TIMER:
			this->imprimir_interfaz_modo_manual(jugador_actual);
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			jugador_actual.setPuntaje(-1);
			return;
			break;
		}
	}
	al_destroy_event_queue(fila_evento);

	switch (dificultad) {
	case 3:
		if (this->tiempo < 60) {
			jugador_actual.setPuntaje(10000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 120) {
			jugador_actual.setPuntaje(5000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 180) {
			jugador_actual.setPuntaje(2500 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 240) {
			jugador_actual.setPuntaje(1250 - 50 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	case 4:
		if (this->tiempo < 60) {
			jugador_actual.setPuntaje(30000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 120) {
			jugador_actual.setPuntaje(15000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 180) {
			jugador_actual.setPuntaje(7500 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 240) {
			jugador_actual.setPuntaje(3750 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 300) {
			jugador_actual.setPuntaje(1875 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 360) {
			jugador_actual.setPuntaje(937 - 50 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	case 5:
		if (this->tiempo < 60) {
			jugador_actual.setPuntaje(60000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 120) {
			jugador_actual.setPuntaje(40000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 180) {
			jugador_actual.setPuntaje(30000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 240) {
			jugador_actual.setPuntaje(10000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 300) {
			jugador_actual.setPuntaje(8000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 360) {
			jugador_actual.setPuntaje(4000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 420) {
			jugador_actual.setPuntaje(2000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 480) {
			jugador_actual.setPuntaje(1000 - 50 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	}
	if (jugador_actual.getPuntaje() < 0) jugador_actual.setPuntaje(0);
}

//-------------------------------------Métodos Privados de Clase---------------------------------//

void Juego::imprimir_interfaz_titulo() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(100, 50, 700, 170, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(140, 230, 240, 330, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(320, 250, 380, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(460, 250, 520, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(600, 250, 660, 310, al_map_rgb(255, 255, 255));

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
}

int Juego::posicionado_menu() {
    if (this->x >= 200 && this->x <= 600 && this->y >= 60 && this->y <= 120) return 1;
    else if (this->x >= 250 && this->x <= 550 && this->y >= 180 && this->y <= 240) return 2;
    else if (this->x >= 320 && this->x <= 481 && this->y >= 300 && this->y <= 360) return 3;
    else return 4;
}

void Juego::imprimir_interfaz_menu() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(200, 60, 600, 120, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(250, 180, 550, 240, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(320, 300, 481, 360, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(50, 210, 150, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(650, 210, 750, 310, al_map_rgb(255, 255, 255));

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(220, 220, 220), 400, 430, ALLEGRO_ALIGN_CENTRE, "SELECCIONE UNA OPCION");
    al_flip_display();

}

int Juego::posicionado_Records() {
    if (this->x >= 65 && this->x <= 121 && this->y >= 468 && this->y <= 525) return 1;
    else if (this->x >= 360 && this->x <= 710 && this->y >= 468 && this->y <= 525) return 2;
    else return 3;
}

void Juego::mostrar_registro() {
    fstream archivo("registro.dat", ios::binary | ios::in);
    ALLEGRO_FONT* menor = al_load_font("Fonts/slkscre.ttf", 23, NULL);
    int contador = 0;

    if (archivo) {
        Datos_Guardar* aux = new Datos_Guardar;

        archivo.read(reinterpret_cast <char*>(aux), sizeof(Datos_Guardar));
        while (!archivo.eof()) {
            if (contador < 7) {
                al_draw_text(menor, al_map_rgb(230, 197, 252), 263, 125 + contador * 45, ALLEGRO_ALIGN_CENTRE, aux->nombre);
                al_draw_text(this->letra, al_map_rgb(202, 255, 175), 460, 123 + contador * 45, ALLEGRO_ALIGN_CENTRE, to_string(aux->puntaje).c_str());
                al_draw_text(menor, al_map_rgb(255, 197, 168), 657, 127 + contador * 45, ALLEGRO_ALIGN_CENTRE, aux->fecha);
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
            al_draw_text(this->letra, al_map_rgb(230, 197, 252), 263, 125 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
            al_draw_text(this->letra, al_map_rgb(202, 255, 175), 460, 123 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
            al_draw_text(this->letra, al_map_rgb(255, 197, 168), 657, 127 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
        }
    }

    archivo.close();
    al_destroy_font(menor);
}

void Juego::imprimir_interfaz_Records() {
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
    this->mostrar_registro();

    al_draw_filled_rectangle(65, 458, 121, 515, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(360, 458, 710, 515, al_map_rgb(255, 255, 255));
    al_flip_display();

    al_destroy_font(titulo); al_destroy_font(letra);
}

int Juego::posicionado_menu_Dificultad() {
    if (this->x >= 300 && this->x <= 500 && this->y >= 150 && this->y <= 210) return 1;
    else if (this->x >= 290 && this->x <= 510 && this->y >= 280 && this->y <= 340) return 2;
    else if (this->x >= 280 && this->x <= 520 && this->y >= 410 && this->y <= 470) return 3;
    else if (this->x >= 64 && this->x <= 122 && this->y >= 409 && this->y <= 471) return 4;
    else return 5;
}

void Juego::imprimir_interfaz_menu_Dificultad() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(this->letra, al_map_rgb(189, 252, 166), 400, 50, ALLEGRO_ALIGN_CENTRE, "SELECCIONE LA DIFICULTAD");

    al_draw_filled_rectangle(300, 150, 500, 210, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(290, 280, 510, 340, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(280, 410, 520, 470, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(65, 410, 121, 470, al_map_rgb(255, 255, 255));

    al_flip_display();
}

int Juego::posicionado_menu_Modo() {
    if (this->x >= 290 && this->x <= 510 && this->y >= 200 && this->y <= 260) return 1;
    else if (this->x >= 270 && this->x <= 530 && this->y >= 360 && this->y <= 420) return 2;
    else if (this->x >= 65 && this->x <= 121 && this->y >= 360 && this->y <= 420) return 3;
    else return 4;
}

void Juego::imprimir_interfaz_menu_Modo() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(this->letra, al_map_rgb(216, 227, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "SELECCIONE EL MODO");

    al_draw_filled_rectangle(290, 200, 510, 260, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(270, 360, 530, 420, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(65, 360, 121, 420, al_map_rgb(255, 255, 255));

    al_flip_display();
}

int Juego::posicionado_confirmacion() {
    if (this->x >= 270 && this->x <= 530 && this->y >= 200 && this->y <= 260) return 1;
    else if (this->x >= 270 && this->x <= 530 && this->y >= 360 && this->y <= 420) return 2;
    else return 3;
}

void Juego::imprimir_interfaz_confirmacion() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(this->letra, al_map_rgb(247, 188, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "CONFIRME LA ELIMINACION");
    al_draw_text(this->letra, al_map_rgb(247, 188, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "DEL REGISTRO");
    al_draw_filled_rectangle(270, 200, 530, 260, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(270, 360, 530, 420, al_map_rgb(255, 255, 255));

    al_flip_display();
}

void Juego::eliminar_registro() {
    fstream archivo("registro.dat", ios::in);
    if (archivo) {
        archivo.close();
        remove("registro.dat");
    }
    else {
        archivo.close();
    }
}

void Juego::imprimir_interfaz_eliminacion() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(190, 231, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "REGISTRO BORRADO");

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
}

void Juego::imprimir_interfaz_salida() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(164, 255, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "GRACIAS POR JUGAR :)");

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
}

void Juego::actualizar_archivo(Jugador jugador_actual) {
    fstream archivo("registro.dat", ios::binary | ios::in);
    if (!archivo) {
        archivo.close();
        archivo.open("registro.dat", ios::binary | ios::out);
        archivo.close();
        fstream archivo("registro.dat", ios::binary | ios::in);
    }
    Jugador* aux1 = new Jugador;
    Datos_Guardar* aux2 = new Datos_Guardar;
    list<Jugador>* ordenamiento = new list<Jugador>;
    bool encontrado = false;

    archivo.read(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    while (!archivo.eof()) {
        aux1->setNombre(aux2->nombre);
        if (aux1->getNombre() == jugador_actual.getNombre()) {
            encontrado = true;
            aux1->setPuntaje(jugador_actual.getPuntaje());
            aux1->setfecha(jugador_actual.getFecha());
        }
        else {
            aux1->setPuntaje(aux2->puntaje);
            aux1->setfecha(aux2->fecha);
        }
        ordenamiento->push_back(*aux1);
        archivo.read(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    }
    if (!encontrado) {
        aux1->setNombre(jugador_actual.getNombre());
        aux1->setPuntaje(jugador_actual.getPuntaje());
        aux1->setfecha(jugador_actual.getFecha());
        ordenamiento->push_back(*aux1);
    }
    ordenamiento->sort(ordenamiento_descendente);

    archivo.clear(); archivo.close();
    remove("registro.dat");
    archivo.open("registro.dat", ios::binary | ios::out);

    for (auto it = ordenamiento->begin(); it != ordenamiento->end(); ++it) {
        strcpy_s(aux2->nombre, 40, it->getNombre().c_str());
        aux2->puntaje = it->getPuntaje();
        strcpy_s(aux2->fecha, 40, it->getFecha().c_str());
        archivo.write(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    }
    archivo.clear(); archivo.close();
    delete aux1, aux2, ordenamiento;
}

char Juego::numero_a_caracter(int digito) {
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

char* Juego::formato_tiempo() {
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

void Juego::imprimir_interfaz_finJuego(Jugador jugador_actual) {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(255, 192, 201), 400, 50, ALLEGRO_ALIGN_CENTRE, "PARTIDA FINALIZADA");
    al_draw_text(this->letra, al_map_rgb(255, 204, 102), 400, 130, ALLEGRO_ALIGN_CENTRE, "EL PUNTAJE DEL JUGADOR");
    al_draw_text(this->letra, al_map_rgb(255, 204, 102), 400, 180, ALLEGRO_ALIGN_CENTRE, ((jugador_actual.getNombre() + " FUE " + to_string(jugador_actual.getPuntaje())).c_str()));

    al_draw_text(this->letra, al_map_rgb(229, 229, 255), 400, 260, ALLEGRO_ALIGN_CENTRE, "EL TIEMPO UTILIZADO FUE");
    al_draw_text(this->letra, al_map_rgb(229, 229, 255), 400, 310, ALLEGRO_ALIGN_CENTRE, this->formato_tiempo());

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
}

int Juego::posicionado_modo_manual() {
	if (this->x >= 470 && this->x <= 750 && this->y >= 440 && this->y <= 500) return 1;
	return 2;
}

void Juego::imprimir_interfaz_modo_manual(Jugador jugador_actual) {
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
	al_draw_text(letra, al_map_rgb(233, 188, 255), 150, 60, ALLEGRO_ALIGN_CENTRE, jugador_actual.getNombre().c_str());
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
