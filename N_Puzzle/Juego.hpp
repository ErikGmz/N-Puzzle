//-----Compilación de la cabecera-----//.
#ifndef Juego_hpp
#define Juego_hpp

//-----Librerías-----//.
#include "Allegro.hpp"
#include "Jugador.hpp"
#include "Puzzle.hpp"

//-----Enumeraciones-----//.
enum valores {
    v1 = 0, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13,
    v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24 
}; //Se establecen los valores numéricos de las fichas.

enum direcciones {
    up = 1, down, leftt, rightt
}; //Direcciones para el movimiento de las fichas.

//-----Estructuras-----//.
struct Datos_Guardar {
    char nombre[50];
    int puntaje;
    char fecha[40];
}; //Datos del jugador.

struct Par_coordenadas {
    int x_inicial, y_inicial, x_final, y_final;
    direcciones posicion;
}; //Datos para verificar el cálculo de coordenadas.

struct Coordenadas {
    int x_inicial, y_inicial, x_final, y_final;
    int posicion;
};  //Datos verificar posiciones.

//-----Prototipos de funciones-----//.
//Se genera el ordenamiento descendente para ordenar jugadores.
bool ordenamiento_descendente(Jugador, Jugador);

//-----Clase 'Juego'-----//.
class Juego {
private:
    //---Atributos---//.
    int dificultad;
    int tiempo;
    int x, y;
    int contador;
    bool parpadeo;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;

    //---Funciones privadas---//.
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
    void imprimir_interfaz_finJuego(Jugador); //Se imprime la interfaz del menú de finalización
    void imprimir_fin_simulacion(int); //Se imprime la interfaz del menú para el fin de la simulación.

    int posicionado_modo_manual(vector<Par_coordenadas>); //Se determina en cuál ícono se ha posicionado el cursor.
    void imprimir_interfaz_modo_manual(Jugador, Puzzle *, Puzzle *); //Se imprime la interfaz de la partida manual.
    void imprimir_interfaz_captura(int, int, Puzzle *, Puzzle *); //Se imprime la interfaz para la solicitud.
    vector<Coordenadas> lugares_disponibles(Puzzle*, int); //Se retorna un vector con las coordenadas de espacios restantes de un tablero.
    int definir_posicion(int, int); //Se define a qué valor corresponde un par fila/columna.
    int posicionado(vector<Coordenadas>); //Se determina en cuál espacio está posicionado el cursor.

    void mostrar_registro(); //Se muestran los datos de cada jugador dentro del ranking.
    void actualizar_archivo(Jugador); //Se actualiza el contenido del registro.
    void eliminar_registro(); //Se elimina el fichero, en caso de existir.

    char numero_a_caracter(int); //Se retorna un dígito en forma de caracter.
    char* formato_tiempo(); //Se convierte una cifra en un formato de tiempo.
    valores convertir_string(string); //Se convierte un string a una enumeración.  
    vector<Par_coordenadas> fichas_a_mover(Puzzle *); //Se retorna un vector con las coordenadas de los elementos que se pueden desplazar.
public:
    //---Constructor---//.
    Juego(ALLEGRO_FONT*, ALLEGRO_DISPLAY*);

    //---Métodos---//.
    bool pantalla_titulo(); //Se genera la pantalla de título.
    int pantalla_menu(); //Se genera el menú principal.
    int pantalla_menu_Dificultad(); //Se genera la pantalla del selector de dificultad.
    int pantalla_menu_Modo(ALLEGRO_SAMPLE_ID); //Se genera la pantalla del selector de modo.
    int pantalla_Records(); //Se genera el menú de récords.
    int pantalla_confirmacion(); //Se genera la pantalla para confirmar la eliminación del registro.
    bool pantalla_eliminacion(); //Se genera la pantalla de eliminación.
    bool pantalla_finJuego(Jugador); //Se genera el menú de finalización.
    bool pantalla_fin_simulacion(int); //Se genera la pantalla para el fin de la simulación.
    void pantalla_salida(); //Se genera la pantalla de salida.

    void setTiempo(int); //Se establece el tiempo del juego manual.
    inline int getTiempo() { return this->tiempo; } //Se obtiene el tiempo del juego actual.
    void setDificultad(int); //Se establece la dificultad del juego actual.
    inline int getDificultad() { return this->dificultad; } //Se obtiene la dificultad del juego actual.
    inline void setParpadeo(bool parametro) { parpadeo = parametro; } //Se establece el parámetro para el parpadeo de íconos.
    inline void setContador(int parametro) { contador = parametro; } //Se establece el contador para controlar parpadeos.
    void modo_manual(Jugador&); //Se gestiona el modo manual del juego.
    void capturar_puzzles(Puzzle *&, Puzzle *&, ALLEGRO_SAMPLE_ID); //Se genera el menú para la solicitar los puzzles.
};
#endif