//-----Compilaci�n del archivo fuente-----//.
#ifndef Allegro_cpp
#define Allegro_cpp

//-----Librer�as-----//.
#include "Allegro.hpp"

//-----Implementaci�n de funciones-----//.
//Inicializaci�n e instalaci�n de m�ltiples componentes de Allegro.
void iniciar_allegro() {
    al_init();
    al_install_audio();
    al_install_keyboard();
    al_install_mouse();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_acodec_addon();
    al_init_primitives_addon();
}
#endif
