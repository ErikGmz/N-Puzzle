//-----Compilación del archivo principal-----//.
#ifndef N_Puzzle_cpp
#define N_Puzzle_cpp

//-----Librerías-----//.
#include "Allegro.hpp"
#include "Inicio.hpp"
#include "Menú.hpp"
#include "Nombres.hpp"
#include "Menú récords.hpp"
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

    Inicio* programa; Menu* principal; Menu_nombres* sistema;
    Dificultad* solicitud; Modo* seleccion; Manual* juego;
    Finalizar* partida; Solicitud* puzzle; Fin* demostracion;
    Menu_records* lista; Confirmar* eliminacion; Eliminar* registro;
    Salir* ejecucion;

    int tiempo, dificultad;
    Datos* jugador;
    bool cancelado = false, repetir, repetir2, repetir3;
    vector<vector<string>>* puzzle_inicio = new vector<vector<string>>;
    vector<vector<string>>* puzzle_meta = new vector<vector<string>>;
    time_t tiempo_local; tm* hora_local;
    char* auxiliar;

    do {
        programa = new Inicio(titulo, pantalla);
        tiempo = 0;
        jugador = new Datos;
        al_play_sample(musica, 1.0, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
        if (programa->pantalla_titulo()) {
            do {
                principal = new Menu(titulo, pantalla);

                repetir3 = false;
                switch (principal->generar_menu()) {
                case 1:
                    do {
                        sistema = new Menu_nombres(titulo, pantalla);

                        repetir = false;
                        jugador->nombre = sistema->generar_solicitud();
                        delete sistema;
                        if (jugador->nombre != "-") {
                            do {
                                solicitud = new Dificultad(titulo, pantalla);

                                repetir2 = false;
                                dificultad = solicitud->generar_selector_dificultad();
                                delete solicitud;

                                if (dificultad == 4) {
                                    repetir = true;
                                }
                                else if (dificultad == 5) {
                                    cancelado = true;
                                }
                                else {
                                    seleccion = new Modo(titulo, pantalla);

                                    switch (seleccion->generar_selector_modo()) {
                                    case 1:
                                        juego = new Manual(pantalla, jugador, dificultad + 2);
                                        juego->generar_partida();

                                        jugador->puntaje = juego->datos_actuales().puntaje;
                                        tiempo = juego->tiempo_ocupado();
                                        delete juego;

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

                                            partida = new Finalizar(titulo, pantalla, jugador, tiempo);

                                            if (!partida->generar_fin_partida()) {
                                                cancelado = true;
                                            }
                                            else {
                                                repetir3 = true;
                                            }
                                            delete partida;
                                        }
                                        break;
                                    case 2:
                                        puzzle = new Solicitud(titulo, pantalla, dificultad + 2, 1);
                                        *puzzle_inicio = puzzle->generar_solicitud();
                                        delete puzzle;

                                        if (puzzle_inicio[0][0][0] == "c") {
                                            cancelado = true;
                                        }
                                        else {
                                            puzzle = new Solicitud(titulo, pantalla, dificultad + 2, 2);
                                            *puzzle_meta = puzzle->generar_solicitud();
                                            delete puzzle;

                                            if (puzzle_meta[0][0][0] == "c") {
                                                cancelado = true;
                                            }
                                            else {
                                                demostracion = new Fin(titulo, pantalla);
                                                demostracion->generar_fin();
                                                repetir3 = true;
                                                delete demostracion;
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
                                    delete seleccion;
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
                        lista = new Menu_records(pantalla);

                        repetir = false;
                        switch (lista->menu_records()) {
                        case 1:
                            repetir3 = true;
                            break;
                        case 2:
                            eliminacion = new Confirmar(titulo, pantalla);

                            switch (eliminacion->pantalla_confirmacion()) {
                            case 1:
                                repetir = true;
                                break;
                            case 2:
                                registro = new Eliminar(titulo, pantalla);

                                if (registro->generar_eliminacion()) {
                                    cancelado = true;
                                }
                                else {
                                    repetir = true;
                                }
                                delete registro;
                                break;
                            case 3: default:
                                cancelado = true;
                                break;
                            }
                            delete eliminacion;
                            break;
                        case 3: default:
                            cancelado = true;
                            break;
                        }
                        delete lista;
                    } while (repetir && !cancelado);
                    break;
                case 3:
                    ejecucion = new Salir(titulo, pantalla);
                    ejecucion->generar_salida();
                    delete ejecucion;
                    cancelado = true;
                    break;
                case 4: default:
                    cancelado = true;
                    break;
                }
                delete principal;
            } while (repetir3 && !cancelado);
        }
        else {
            cancelado = true;
        }
        delete programa;
        delete jugador;
    } while (!cancelado);

    al_destroy_display(pantalla);
    al_destroy_font(titulo);
    return 0;
}
#endif