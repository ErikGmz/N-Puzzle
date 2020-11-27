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

//-----Función main-----//.
int main() {
    iniciar_allegro();
    ALLEGRO_DISPLAY* pantalla = al_create_display(800, 550);
    ALLEGRO_FONT* titulo = al_load_font("Fonts/slkscre.ttf", 35, NULL);
    al_set_window_position(pantalla, 200, 100);
    al_set_window_title(pantalla, "N-Puzzle");

    int tiempo = 0, dificultad = 2, tipo_puzzle = 1;
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
    solicitar_puzzle(pantalla, titulo, dificultad + 2, tipo_puzzle);

    al_destroy_display(pantalla);
    al_destroy_font(titulo);
    return 0;
}
#endif