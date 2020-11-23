//-----Compilaci�n de la cabecera-----//.
#ifndef Allegro_hpp
#define Allegro_hpp

//-----Librer�as-----//.
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <string>

//-----Espacio de nombres-----//.
using namespace std;

//-----Funciones-----//.
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