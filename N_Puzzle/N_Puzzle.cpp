#include "Juego.hpp"

int main() {
    srand(time(NULL));
    iniciar_allegro();
    ALLEGRO_DISPLAY* pantalla = al_create_display(800, 550);
    ALLEGRO_FONT* fuente = al_load_font("Fonts/slkscre.ttf", 35, NULL);
    ALLEGRO_SAMPLE* musica = al_load_sample("Sounds/Fallin' Love   MOTHER.mp3");
    ALLEGRO_SAMPLE_ID id1;
    al_reserve_samples(3);

    al_set_window_position(pantalla, 200, 100);
    al_set_window_title(pantalla, "N-Puzzle");

    bool cancelado = false, repetir, repetir2, repetir3;
    vector<vector<string>>* puzzle_inicio = new vector<vector<string>>;
    vector<vector<string>>* puzzle_meta = new vector<vector<string>>;
    time_t tiempo_local; tm* hora_local;
    char* auxiliar;

    Juego juego(fuente, pantalla);
    Jugador jugador(fuente, pantalla);

    do {
        al_play_sample(musica, 1.0, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
        juego.setContador(0);
        juego.setParpadeo(true);

        jugador.setPuntaje(0);
        if (juego.pantalla_titulo()) {
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

                                    switch (juego.pantalla_menu_Modo()) {
                                    case 1:
                                        juego.setTiempo(-1);
                                        juego.modo_manual(jugador);
                                        if (jugador.getPuntaje() == -1) {
                                            cancelado = true;
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
    return 0;
}