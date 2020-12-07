#ifndef JUGADOR_HPP
#define JUGADOR_HPP
#include "Allegro.hpp"

class Jugador {
private:
    string nombre;
    int puntaje;
    string fecha;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;
public:
    Jugador();
    Jugador(ALLEGRO_FONT *, ALLEGRO_DISPLAY *);
    void setNombre(string);
    void setPuntaje(int);
    void setfecha(string);
    inline string getNombre() { return this->nombre; }
    inline int getPuntaje() { return this->puntaje; }
    inline string getFecha() {return this->fecha; }
    void capturaNombre(); //Se genera la pantalla para solicitar nombres.
private:
    void imprimir_interfaz_capturaNombre(); //Se imprime la interfaz para la solicitud de nombres.
    char convertir_entrada(ALLEGRO_EVENT); //Cada entrada del teclado se convierte a un caracter.
};

#endif