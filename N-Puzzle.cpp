//-----Compilación del archivo principal-----//.
#ifndef N_Puzzle_cpp
#define N_Puzzle_cpp

//-----Librerías-----//.
#include "Allegro.hpp"
#include "Inicio.hpp"
#include "Menú.hpp"
#include "Nombres.hpp"
#include <cstdlib>

//-----Función main-----//.
int main(){
    iniciar_allegro();
    ALLEGRO_DISPLAY* pantalla = al_create_display(800, 550);
    ALLEGRO_FONT* titulo = al_load_font("Fonts/slkscre.ttf", 35, NULL);
    al_set_window_position(pantalla, 200, 100);
    al_set_window_title(pantalla, "N-Puzzle");

    imprimir_titulo(pantalla, titulo);
    imprimir_menu(pantalla, titulo);
    solicitar_nombre(pantalla, titulo);

    al_rest(100);
    al_destroy_display(pantalla);
    al_destroy_font(titulo);
}
#endif