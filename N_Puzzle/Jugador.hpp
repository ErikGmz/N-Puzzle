//-----Compilación de la cabecera-----//.
#ifndef jugador_hpp
#define jugador_hpp

//-----Librerías-----//.
#include "Allegro.hpp"

//-----Clase 'Juego'-----//.
class Jugador {
private:
    //---Atributos---//.
    string nombre;
    int puntaje, x, y;
    string fecha;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;

    //---Funciones privadas---//.
    void imprimir_interfaz_capturaNombre(); //Se imprime la interfaz para la solicitud de nombres.
    int posicionado_menu_nombres(); //Se verifica si el cursor ha sido posicionado en el ícono del retorno.
    char convertir_entrada(ALLEGRO_EVENT); //Cada entrada del teclado se convierte a un caracter.
public:
    //---Constructores---//.
    Jugador(); //Constructor predeterminado.
    Jugador(ALLEGRO_FONT *, ALLEGRO_DISPLAY *); //Constructor con argumentos.

    //---Métodos---//.
    void setNombre(string); //Se define el nombre del jugador.
    void setPuntaje(int); //Se define el puntaje del jugador.
    void setfecha(string); //Se define la fecha de la última partida del jugador.
    inline string getNombre() { return this->nombre; } //Se retorna el nombre del jugador.
    inline int getPuntaje() { return this->puntaje; } //Se retorna el puntaje del jugador.
    inline string getFecha() {return this->fecha; } //Se retorna la fecha de la última partida del jugador.
    void capturaNombre(ALLEGRO_SAMPLE_ID); //Se genera la pantalla para solicitar nombres.
};
#endif