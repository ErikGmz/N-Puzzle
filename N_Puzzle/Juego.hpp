#ifndef JUEGO_HPP
#define JUEGO_HPP
#include "Allegro.hpp"
#include "Jugador.hpp"
#include "Puzzle.hpp"

struct Datos_Guardar {
    char nombre[50];
    int puntaje;
    char fecha[40];
};

bool ordenamiento_descendente(Jugador, Jugador);

class Juego {
//---------------Atributos de clase--------------
private:
    int dificultad;
    int tiempo;
    int x, y;
    int contador;
    bool parpadeo;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;
//---------------Métodos de clase--------------
public:
    Juego(ALLEGRO_FONT*, ALLEGRO_DISPLAY*);
    bool pantalla_titulo(); //Se genera la pantalla de título.
    int pantalla_menu(); //Se genera el menú principal.
    int pantalla_menu_Dificultad(); //Se genera la pantalla del selector de dificultad.
    int pantalla_menu_Modo(); //Se genera la pantalla del selector de modo.
    int pantalla_Records(); //Se genera el menú de récords.
    int pantalla_confirmacion(); //Se genera la pantalla para confirmar la eliminación del registro.
    bool pantalla_eliminacion(); //Se genera la pantalla de eliminación.
    bool pantalla_finJuego(Jugador); //Se genera el menú de finalización.
    void pantalla_salida(); //Se genera la pantalla de salida.
    void setTiempo(int);
    int getTiempo() { return this->tiempo; }
    void setDificultad(int);
    int getDificultad() { return this->dificultad; }

    void modo_manual(Jugador &);
private:
    void imprimir_interfaz_titulo(); //Se imprime la interfaz de la pantalla de título.
    int posicionado_menu(); //Se determina en cuál ícono se ha posicionado el cursor.
    void imprimir_interfaz_menu(); //Se imprime la interfaz del menú principal.
    int posicionado_menu_Dificultad(); //Se determina en cuál ícono se ha posicionado el cursor.
    void imprimir_interfaz_menu_Dificultad(); //Se imprime la interfaz del selector de dificultad.
    int posicionado_menu_Modo(); //Se determina en cuál ícono se ha posicionado el cursor.
    void imprimir_interfaz_menu_Modo(); //Se imprime la interfaz del selector de modo.
    int posicionado_Records(); //Se determina en cuál ícono se ha posicionado el cursor.
    void imprimir_interfaz_Records(); //Se imprime la interfaz del menú de récords.
    int posicionado_confirmacion(); //Se determina en cuál ícono se ha posicionado el cursor.
    void imprimir_interfaz_confirmacion(); //Se imprime la interfaz de la pantalla para confirmar la eliminación del registro.
    void imprimir_interfaz_eliminacion(); //Se imprime la intefaz de eliminación.
    void imprimir_interfaz_salida(); //Se imprime la interfaz de la pantalla de salida.
    void imprimir_interfaz_finJuego(Jugador); //Se imprime la interfaz del menú de finalización.

    int posicionado_modo_manual(); //Se determina en cuál ícono se ha posicionado el cursor.
    void imprimir_interfaz_modo_manual(Jugador); //Se imprime la interfaz de la partida manual.

    void mostrar_registro(); //Se muestran los datos de cada jugador dentro del ranking.
    void actualizar_archivo(Jugador); //Se actualiza el contenido del registro.
    void eliminar_registro(); //Se elimina el fichero, en caso de existir.

    char numero_a_caracter(int); //Se retorna un dígito en forma de caracter.
    char* formato_tiempo(); //Se convierte una cifra en un formato de tiempo.
};

#endif