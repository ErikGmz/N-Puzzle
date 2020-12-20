/*
Proyecto Final - Juego N-Puzzle.

Integrantes de equipo:
    - Erik Alejandro Gómez Martínez.
    - Israel Alejandro Mora González.
    - Ángel Gabriel Galindo López.
    - José Emmanuel Rodríguez López.

Fechas de entrega: 21-23 de diciembre de 2020.

Descripción general: El juego 8-puzzle es una versión reducida del 15-puzzle, un juego conocido en
muchas partes del mundo, aunque no siempre se conoce por ese nombre. El juego está formado por una caja 
cuadrada con 8 piezas móviles, también cuadradas, numeradas entre 1 y 8. El objetivo del juego es ordenar 
las piezas de 1 a 8 realizando el desplazamiento de una pieza a la vez, utilizando el único espacio 
libre disponible. Las piezas no pueden sacarse de la caja así que no es posible ordenarlas de cualquier forma.

El programa esta contruido bajo el paradigma de programación orientada a objetos. El programa consta de cuatro clases.
Programa desarrollado en el IDE Visual Studio 2019 y Allegro 5.2.6.
*/

//-----Compilación del archivo fuente-----//.
#ifndef N_Puzzle_cpp
#define N_Puzzle_cpp

#include "Juego.hpp"

int main() {
    srand(time(NULL));
    iniciar_allegro();
    ALLEGRO_DISPLAY* pantalla = al_create_display(800, 550);
    ALLEGRO_FONT* fuente = al_load_font("Fonts/slkscre.ttf", 35, NULL);
    ALLEGRO_BITMAP* icono = al_load_bitmap("Sources/Fichas/F7.png");
    ALLEGRO_SAMPLE* musica_menus = al_load_sample("Sounds/Super Mario Bros 2 (NES) Music   Character Select.mp3");
    ALLEGRO_SAMPLE* musica_juego = al_load_sample("Sounds/Casino Kid (NES) Music   Casino Theme.mp3");
    ALLEGRO_SAMPLE_ID id1, id2;
    al_reserve_samples(3);

    al_set_window_position(pantalla, 200, 100);
    al_set_window_title(pantalla, "N-Puzzle");
    al_set_display_icon(pantalla, icono);

    bool cancelado = false, repetir, repetir2, repetir3;
    time_t tiempo_local; tm* hora_local;
    Puzzle* inicio, *fin;
    char* auxiliar;

    Juego juego(fuente, pantalla);
    Jugador jugador(fuente, pantalla);

    do {
        juego.setContador(0);
        juego.setParpadeo(true);

        jugador.setPuntaje(0);
        if (juego.pantalla_titulo()) {
            al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
            do {
                repetir3 = false;
                juego.setContador(0);
                juego.setParpadeo(true);
                switch (juego.pantalla_menu()) {
                case 1:
                    do {
                        repetir2 = false;
                        switch (juego.pantalla_menu_Modo(id1)) {
                        case 1:
                            do {
                                repetir = false;
                                juego.setDificultad(juego.pantalla_menu_Dificultad());
                                if (juego.getDificultad() == 4) {
                                    repetir2 = true; //Retorno a menú de modos.
                                }
                                else if (juego.getDificultad() == 5) {
                                    cancelado = true; //Cerrar juego.
                                }
                                else {
                                    jugador.setNombre("");
                                    jugador.capturaNombre(id1);
                                    if (jugador.getNombre() == "-") {
                                        cancelado = true; //Cerrar juego.
                                    }
                                    else if (jugador.getNombre() == "+") {
                                        repetir = true; //Retorno a menú de dificultades.
                                    }
                                    else {
                                        juego.setDificultad(juego.getDificultad() + 2);
                                        juego.setTiempo(0);
                                        juego.modo_manual(jugador);
                                        juego.setContador(0);
                                        juego.setParpadeo(true);

                                        if (jugador.getPuntaje() == -1) {
                                            cancelado = true; //Cerrar juego.
                                        }
                                        else if (jugador.getPuntaje() == -2) {
                                            al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
                                            repetir3 = true; //Retorno a menú principal.
                                        }
                                        else {
                                            tiempo_local = time(NULL);
                                            hora_local = localtime(&tiempo_local);
                                            auxiliar = new char[40];
                                            strftime(auxiliar, 40, "%d/%m/%Y", hora_local);
                                            jugador.setfecha(auxiliar);
                                            delete[] auxiliar;
                                            //Obtener la última fecha de juego.

                                            if (!juego.pantalla_finJuego(jugador)) {
                                                cancelado = true; //Cerrar juego.
                                            }
                                            else {
                                                al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
                                                repetir3 = true; //Retorno a menú principal.
                                            }
                                        }
                                    }                               
                                }
                            } while (repetir && !cancelado);
                            break;
                            case 2:
                                juego.setDificultad(3);
                                al_play_sample(musica_juego, 0.5, 0, 1, ALLEGRO_PLAYMODE_LOOP, &id2);
                                juego.capturar_puzzles(inicio, fin, id2);
                                if (inicio[0][0][0] == "c") {
                                    cancelado = true; //Cerrar juego.
                                }
                                else if (inicio[0][0][0] == "d") {
                                    al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
                                    repetir3 = true; //Retorno a menú principal.
                                }
                                else if (inicio[0][0][0] == "e") {
                                    if (!juego.pantalla_fin_simulacion(3)) {
                                        cancelado = true; //Cerrar juego.
                                    }
                                    else {
                                        al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
                                        repetir3 = true; //Retorno a menú principal.
                                    }
                                }
                                else if (inicio[0][0][0] == "f") {
                                    if (!juego.pantalla_fin_simulacion(2)) {
                                        cancelado = true; //Cerrar juego.
                                    }
                                    else {
                                        al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
                                        repetir3 = true; //Retorno a menú principal.
                                    }
                                }
                                else {
                                    juego.setContador(0);
                                    juego.setParpadeo(true);

                                    if (inicio->resuelve(fin)) {
                                        al_stop_sample(&id2);
                                        ALLEGRO_SAMPLE* ganar = al_load_sample("Sounds/Super Mario Bros 2 (NES) Music   World Clear.mp3");
                                        ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
                                        al_play_sample(ganar, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                                        al_rest(5.0);
                                        al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                                        al_clear_to_color(al_map_rgb(0, 0, 0));
                                        al_flip_display();
                                        al_rest(0.9);
                                    }
                                    if (!juego.pantalla_fin_simulacion(1)) {
                                        cancelado = true; //Cerrar programa.
                                    }
                                    else {
                                        al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
                                        repetir3 = true; //Retorno a menú principal.
                                    }
                                }
                                delete inicio, fin;
                                break;
                            case 3:
                                repetir3 = true;
                                break;
                            case 4:
                                cancelado = true;
                                break;
                            }
                    } while (repetir2 && !cancelado);
                    break;
                case 2:
                    do {
                        repetir = false;

                        switch (juego.pantalla_Records()) {
                        case 1:
                            repetir3 = true; //Retorno a menú principal.
                            break;
                        case 2:
                            switch (juego.pantalla_confirmacion()) {
                            case 1:
                                repetir = true; //Retorno a tabla de récords.
                                break;
                            case 2:
                                juego.setContador(0);
                                juego.setParpadeo(true);

                                if (juego.pantalla_eliminacion()) {
                                    repetir = true; //Retorno a tabla de récords.
                                }
                                else {
                                    cancelado = true; //Cerrar el juego.
                                }
                                break;
                            case 3: default:
                                cancelado = true; //Cerrar el juego.
                                break;
                            }
                            break;
                        case 3: default:
                            cancelado = true; //Cerrar el juego.
                            break;
                        }
                    } while (repetir && !cancelado);
                    break;
                case 3:
                    juego.setContador(0);
                    juego.setParpadeo(true);

                    juego.pantalla_salida();
                    cancelado = true; //Cerrar el juego.
                    break;
                case 4: default:
                    cancelado = true; //Cerrar el juego.
                    break;
                }
            } while (repetir3 && !cancelado);
        }
        else {
            cancelado = true;
        }
    } while (!cancelado);

    al_destroy_display(pantalla);
    al_destroy_font(fuente);
    al_destroy_sample(musica_menus);
    return 0;
}
#endif