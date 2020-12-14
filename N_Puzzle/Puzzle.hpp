//-----Compilación de la cabecera-----//.
#ifndef Puzzle_hpp
#define Puzzle_hpp

//-----Librerías-----//.
#include "Allegro.hpp"
#include "Nodo.hpp"

//-----Estructuras-----//.
struct comp { 
    //Se verifica cuál nodo tiene un mayor costo y tiempo de procesamiento.
    bool operator()(const Nodo* lhs, const Nodo* rhs) const { 
        return (lhs->costo + lhs->nivel) > (rhs->costo + rhs->nivel); 
    } 
};

//-----Clase 'Puzzle'-----//.
class Puzzle {
private:
    //---Atributos---//.
    int tipo_puzzle;
    vector<vector<string>>* puzzle;
    int x, y;
    int contador;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;

    //---Funciones privadas---//.
    void imprimir_interfaz_captura(int, int, int); //Se imprime la interfaz para la solicitud.
    char validar_entrada(ALLEGRO_EVENT); //Se verifica que el caracter ingresado sea numérico.
    bool entrada_valida(int, int); //Se verifica si la entrada actual es repetida/válida o no.
    int calculaCosto(vector<vector<string>>&, vector<vector<string>>&); //Se calcula el costo que requiere resolver un puzzle inicial a uno meta.
    bool esCoordenada(int, int); //Se verifica si dos elementos, según el tamaño del puzzle.
    void imprimeRuta(Nodo*); //Se imprime la ruta más optima para resolver el puzzle.
public:
    //---Constructor y destructor---//.
    Puzzle(ALLEGRO_FONT*, ALLEGRO_DISPLAY*, int); //Constructor con argumentos.
    ~Puzzle(); //Destructor.

    //---Métodos---//.
    void capturaPuzzle(); //Se genera el menú para la solicitud del puzzle.
    void generaPuzzle(); //Se genera el puzzle de forma aleatoria.
    //void imprimePuzzle(); //Se imprime el puzzle en pantalla.
    void resuelve(int, int, vector<vector<string>> &); //Si tiene solución, se resuelve el puzzle por medio del algoritmo branch and bound.
    bool operator==(Puzzle &); //Se compara si ambos puzzles son exactamente iguales.
    vector<string> &operator[](int); //Se retorna un vector relacionado con el tablero.
    void swap(int); //Se intercambian dos valores dentro del tablero.
};
#endif