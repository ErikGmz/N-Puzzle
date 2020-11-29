//-----Compilación del archivo principal-----//.
#ifndef N_Puzzle_cpp
#define N_Puzzle_cpp

//-----Librerías-----//.
#include "Allegro.hpp"
#include "Inicio.hpp"
#include "Menú.hpp"
#include "Nombres.hpp"
#include "Menú récords.hpp"
#include "Sistema archivos.hpp"
#include "Selector dificultad.hpp"
#include "Selector modo.hpp"
#include "Confirmar eliminación.hpp"
#include "Eliminar registro.hpp"
#include "Salida.hpp"
#include "Fin juego.hpp"
#include "Solicitar puzzle.hpp"
#include "Finalizar demostración.hpp"
#include "Juego manual.hpp"

//-----Función main-----//.
int main() {
    srand(time(NULL));
    iniciar_allegro();
    ALLEGRO_DISPLAY* pantalla = al_create_display(800, 550);
    ALLEGRO_FONT* titulo = al_load_font("Fonts/slkscre.ttf", 35, NULL);
    ALLEGRO_SAMPLE* musica = al_load_sample("Sounds/Fallin' Love   MOTHER.mp3");
    ALLEGRO_SAMPLE_ID id1;
    al_reserve_samples(3);

    al_set_window_position(pantalla, 200, 100);
    al_set_window_title(pantalla, "N-Puzzle");

    int tiempo, dificultad;
    Datos* jugador;
    bool cancelado = false, repetir, repetir2, repetir3;
    vector<vector<string>>* puzzle_inicio = new vector<vector<string>>;
    vector<vector<string>>* puzzle_meta = new vector<vector<string>>;
    time_t tiempo_local; tm* hora_local;
    char* auxiliar;

    do {
        tiempo = 0;
        jugador = new Datos;
        al_play_sample(musica, 1.0, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
        if (imprimir_titulo(pantalla, titulo)) {

            do {
                repetir3 = false;
                switch (imprimir_menu(pantalla, titulo)) {
                case 1:

                    do {
                        repetir = false;
                        jugador->nombre = solicitar_nombre(pantalla, titulo);
                        if (jugador->nombre != "-") {

                            do {
                                repetir2 = false;
                                dificultad = imprimir_selector(pantalla, titulo);

                                if (dificultad == 4) {
                                    repetir = true;
                                }
                                else if (dificultad == 5) {
                                    cancelado = true;
                                }
                                else {
                                    switch (imprimir_modos(pantalla, titulo)) {
                                    case 1:
                                        empezar_juego_manual(pantalla, jugador, dificultad + 2, tiempo);
                                        if (jugador->puntaje == -1) {
                                            cancelado = true;
                                        }
                                        else {
                                            tiempo_local = time(NULL);
                                            hora_local = localtime(&tiempo_local);
                                            auxiliar = new char[40];
                                            strftime(auxiliar, 40, "%d/%m/%Y", hora_local);
                                            jugador->fecha = auxiliar;
                                            delete auxiliar;

                                            if (!imprimir_fin_partida(pantalla, titulo, jugador, tiempo)) {
                                                cancelado = true;
                                            }
                                            else {
                                                repetir3 = true;
                                            }
                                        }
                                        break;
                                    case 2:
                                        *puzzle_inicio = solicitar_puzzle(pantalla, titulo, dificultad + 2, 1);
                                        if (puzzle_inicio[0][0][0] == "c") {
                                            cancelado = true;
                                        }
                                        else {
                                            *puzzle_meta = solicitar_puzzle(pantalla, titulo, dificultad + 2, 2);
                                            if (puzzle_meta[0][0][0] == "c") {
                                                cancelado = true;
                                            }
                                            else {
                                                imprimir_fin_demostracion(pantalla, titulo);
                                                repetir3 = true;
                                            }
                                        }
                                        break;
                                    case 3:
                                        repetir2 = true;
                                        break;
                                    case 4: default:
                                        cancelado = true;
                                        break;
                                    }
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
                        switch (imprimir_records(pantalla)) {
                        case 1:
                            repetir3 = true;
                            break;
                        case 2:
                            switch (imprimir_confirmacion(pantalla, titulo)) {
                            case 1:
                                repetir = true;
                                break;
                            case 2:
                                if (!imprimir_eliminacion(pantalla, titulo)) {
                                    cancelado = true;
                                }
                                else {
                                    repetir = true;
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
                    imprimir_salida(pantalla, titulo);
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
        delete jugador;
    } while (!cancelado);

    al_destroy_display(pantalla);
    al_destroy_font(titulo);
    return 0;
}
#endif