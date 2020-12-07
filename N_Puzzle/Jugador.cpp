#include "Jugador.hpp"

//-------------------------------------Métodos Públicos de Clase---------------------------------//

Jugador::Jugador() {
    this->nombre = "";
    this->puntaje = 0;
    this->fecha = "";
}

Jugador::Jugador(ALLEGRO_FONT *formato, ALLEGRO_DISPLAY *ventana) {
    this->nombre = "";
    this->puntaje = 0;
    this->fecha = "";
    this->letra = formato;
    this->pantalla = ventana;
}

void Jugador::setNombre(string nombre) {
    this->nombre = nombre;
    return;
}

void Jugador::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
    return;
}

void Jugador::setfecha(string fecha) {
    this->fecha = fecha;
    return;
}

void Jugador::capturaNombre() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* tecleado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool finalizado = false, reanudar;
    char aux;

    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    this->imprimir_interfaz_capturaNombre();

    while (!finalizado) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_CHAR:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                if (this->nombre.length() == 0) {
                    al_show_native_message_box(this->pantalla, "Advertencia", "Error de formato", "Texto mal introducido", NULL, ALLEGRO_MESSAGEBOX_WARN);
                }
                else {
                    al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                    al_rest(0.5);
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_flip_display();
                    al_rest(0.5);
                    finalizado = true;
                }
            }
            else {
                aux = this->convertir_entrada(evento);
                if (aux != '+' && this->nombre.length() < 8) {
                    al_play_sample(tecleado, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
                if (aux != '+' && aux != '-' && this->nombre.length() < 8) {
                    nombre.push_back(aux);
                    this->imprimir_interfaz_capturaNombre();
                }
                if (aux == '-' && nombre.length() > 0) {
                    nombre.pop_back();
                    this->imprimir_interfaz_capturaNombre();
                }
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_capturaNombre();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            this->nombre = "-";
            finalizado = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_destroy_sample(avance);
    al_destroy_sample(tecleado);
    return;
}

//-------------------------------------Métodos Privados de Clase---------------------------------//

void Jugador::imprimir_interfaz_capturaNombre() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(255, 255, 139), 400, 50, ALLEGRO_ALIGN_CENTRE, "INGRESE SU NOMBRE");
    al_draw_text(this->letra, al_map_rgb(191, 253, 253), 400, 131, ALLEGRO_ALIGN_CENTRE, this->nombre.c_str());

    al_draw_rectangle(240, 123, 560, 173, al_map_rgb(193, 255, 163), 5);
    al_draw_filled_rectangle(50, 330, 150, 430, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(210, 300, 270, 360, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(330, 390, 390, 450, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(450, 300, 510, 360, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(570, 390, 630, 450, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(690, 300, 750, 360, al_map_rgb(255, 255, 255));
    al_flip_display();
    return;
}

char Jugador::convertir_entrada(ALLEGRO_EVENT evento) {
    char letra;
    switch (evento.keyboard.keycode) {
    case ALLEGRO_KEY_A: letra = 'A'; break; case ALLEGRO_KEY_B: letra = 'B'; break; case ALLEGRO_KEY_C: letra = 'C'; break;
    case ALLEGRO_KEY_D: letra = 'D'; break; case ALLEGRO_KEY_E: letra = 'E'; break; case ALLEGRO_KEY_F: letra = 'F'; break;
    case ALLEGRO_KEY_G: letra = 'G'; break; case ALLEGRO_KEY_H: letra = 'H'; break; case ALLEGRO_KEY_I: letra = 'I'; break;
    case ALLEGRO_KEY_J: letra = 'J'; break; case ALLEGRO_KEY_K: letra = 'K'; break; case ALLEGRO_KEY_L: letra = 'L'; break;
    case ALLEGRO_KEY_M: letra = 'M'; break; case ALLEGRO_KEY_N: letra = 'N'; break; case ALLEGRO_KEY_O: letra = 'O'; break;
    case ALLEGRO_KEY_P: letra = 'P'; break; case ALLEGRO_KEY_Q: letra = 'Q'; break; case ALLEGRO_KEY_R: letra = 'R'; break;
    case ALLEGRO_KEY_S: letra = 'S'; break; case ALLEGRO_KEY_T: letra = 'T'; break; case ALLEGRO_KEY_U: letra = 'U'; break;
    case ALLEGRO_KEY_V: letra = 'V'; break; case ALLEGRO_KEY_W: letra = 'W'; break; case ALLEGRO_KEY_X: letra = 'X'; break;
    case ALLEGRO_KEY_Y: letra = 'Y'; break; case ALLEGRO_KEY_Z: letra = 'Z'; break; case ALLEGRO_KEY_1: letra = '1'; break;
    case ALLEGRO_KEY_2: letra = '2'; break; case ALLEGRO_KEY_3: letra = '3'; break; case ALLEGRO_KEY_4: letra = '4'; break;
    case ALLEGRO_KEY_5: letra = '5'; break; case ALLEGRO_KEY_6: letra = '6'; break; case ALLEGRO_KEY_7: letra = '7'; break;
    case ALLEGRO_KEY_8: letra = '8'; break; case ALLEGRO_KEY_9: letra = '9'; break; case ALLEGRO_KEY_0: letra = '0'; break;
    case ALLEGRO_KEY_BACKSPACE: letra = '-'; break; default: letra = '+'; break;
    }
    return letra;
}