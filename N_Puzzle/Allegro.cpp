//-----Compilación del archivo fuente-----//.
#ifndef Allegro_cpp
#define Allegro_cpp

//-----Librerías-----//.
#include "Allegro.hpp"

//-----Implementación de funciones-----//.
//Inicialización e instalación de múltiples componentes de Allegro.
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
