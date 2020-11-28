//-----Compilaci�n del archivo principal-----//.
#ifndef N_Puzzle_cpp
#define N_Puzzle_cpp

//-----Librer�as-----//.
#include "Allegro.hpp"
#include "Inicio.hpp"
#include "Men�.hpp"
#include "Nombres.hpp"
#include "Men� r�cords.hpp"
#include "Sistema archivos.hpp"
#include "Selector dificultad.hpp"
#include "Selector modo.hpp"
#include "Confirmar eliminaci�n.hpp"
#include "Eliminar registro.hpp"
#include "Salida.hpp"
#include "Fin juego.hpp"
#include "Solicitar puzzle.hpp"
#include "Finalizar demostraci�n.hpp"
#include "Juego manual.hpp"

//-----Funci�n main-----//.
int main() {
    srand(time(NULL));
    iniciar_allegro();
    ALLEGRO_DISPLAY* pantalla = al_create_display(800, 550);
    ALLEGRO_FONT* titulo = al_load_font("Fonts/slkscre.ttf", 35, NULL);
    al_set_window_position(pantalla, 200, 100);
    al_set_window_title(pantalla, "N-Puzzle");

    int tiempo = 0, dificultad = 1, tipo_puzzle = 1;
    Datos* jugador = new Datos;

    jugador->nombre = "Erik";
    jugador->puntaje = 100;
    jugador->fecha = "26/11/2020";

    //imprimir_fin_partida(pantalla, titulo, jugador, tiempo);
    //imprimir_records(pantalla);
    //imprimir_salida(pantalla, titulo);
    //imprimir_confirmacion(pantalla, titulo);
    //imprimir_eliminacion(pantalla, titulo);
    //imprimir_records(pantalla);
    //imprimir_selector(pantalla, titulo);
    //imprimir_titulo(pantalla, titulo);
    //imprimir_menu(pantalla, titulo);
    //solicitar_nombre(pantalla, titulo);
    //imprimir_modos(pantalla, titulo);
    //solicitar_puzzle(pantalla, titulo, dificultad + 2, tipo_puzzle);
    //imprimir_fin_demostracion(pantalla, titulo);
    empezar_juego_manual(pantalla, jugador, dificultad + 2, tiempo);

    al_destroy_display(pantalla);
    al_destroy_font(titulo);
    return 0;
}
#endif