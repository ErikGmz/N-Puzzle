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
    ALLEGRO_SAMPLE_ID id1;
    al_reserve_samples(3);

    al_set_window_position(pantalla, 200, 100);
    al_set_window_title(pantalla, "N-Puzzle");
    al_set_display_icon(pantalla, icono);

    bool cancelado = false, repetir, repetir2, repetir3;
    vector<vector<string>>* puzzle_inicio = new vector<vector<string>>;
    time_t tiempo_local; tm* hora_local;
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
                        repetir = false;
                        jugador.setNombre("");
                        jugador.capturaNombre();
                        if (jugador.getNombre() != "-") {
                            do {
                                repetir2 = false;
                                juego.setDificultad(juego.pantalla_menu_Dificultad());
                                if (juego.getDificultad() == 4) {
                                    repetir = true;
                                }
                                else if (juego.getDificultad() == 5) {
                                    cancelado = true;
                                }
                                else {
                                    //Puzzle *puzzle_inicio = new Puzzle(fuente,pantalla,dificultad + 2);
                                    juego.setDificultad(juego.getDificultad() + 2);

                                    switch (juego.pantalla_menu_Modo(id1)) {
                                    case 1:
                                        juego.setTiempo(0);
                                        juego.modo_manual(jugador);
                                        juego.setContador(0);
                                        juego.setParpadeo(true);

                                        if (jugador.getPuntaje() == -1) {
                                            cancelado = true;
                                        }
                                        else if (jugador.getPuntaje() == -2) {
                                            al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
                                            repetir3 = true;
                                        }
                                        else {
                                            tiempo_local = time(NULL);
                                            hora_local = localtime(&tiempo_local);
                                            auxiliar = new char[40];
                                            strftime(auxiliar, 40, "%d/%m/%Y", hora_local);
                                            jugador.setfecha(auxiliar);
                                            delete auxiliar;
                                            if (!juego.pantalla_finJuego(jugador)) {
                                                cancelado = true;
                                            }
                                            else {
                                                al_play_sample(musica_menus, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
                                                repetir3 = true;
                                            }
                                        }
                                        break;
                                    case 2:
                                        /*
                                        puzzle_inicio.capturaPuzzle();
                                        if (puzzle_inicio[0][0][0] == "c") {
                                            cancelado = true;
                                        }
                                        else {
                                            
                                            puzzle = new Solicitud(fuente, pantalla, dificultad + 2, 2);
                                            *puzzle_meta = puzzle->generar_solicitud();
                                            delete puzzle;

                                            if (puzzle_meta[0][0][0] == "c") {
                                                cancelado = true;
                                            }
                                            else {
                                                demostracion = new Fin(fuente, pantalla);
                                                demostracion->generar_fin();
                                                repetir3 = true;
                                                delete demostracion;
                                            }
                                        }
                                        */
                                        break;
                                    case 3:
                                        repetir2 = true;
                                        break;
                                    case 4: default:
                                        cancelado = true;
                                        break;
                                    }
                                    //delete puzzle_inicio;
                                }
                            } while (repetir2 && !cancelado);
                        }
                        else {
                            cancelado = true;
                        }
                    } while (repetir && !cancelado);
                    break;
                case 2:
                    do {
                        repetir = false;

                        switch (juego.pantalla_Records()) {
                        case 1:
                            repetir3 = true;
                            break;
                        case 2:
                            switch (juego.pantalla_confirmacion()) {
                            case 1:
                                repetir = true;
                                break;
                            case 2:
                                juego.setContador(0);
                                juego.setParpadeo(true);

                                if (juego.pantalla_eliminacion()) {
                                    repetir = true;
                                }
                                else {
                                    cancelado = true;
                                }
                                break;
                            case 3: default:
                                cancelado = true;
                                break;
                            }
                            break;
                        case 3: default:
                            cancelado = true;
                            break;
                        }
                    } while (repetir && !cancelado);
                    break;
                case 3:
                    juego.setContador(0);
                    juego.setParpadeo(true);

                    juego.pantalla_salida();
                    cancelado = true;
                    break;
                case 4: default:
                    cancelado = true;
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