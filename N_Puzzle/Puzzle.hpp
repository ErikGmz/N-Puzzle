#ifndef PUZZLE_HPP
#define PUZZLE_HPP
#include "Allegro.hpp"
#include "Nodo.hpp"

struct comp { 
    bool operator()(const Nodo* lhs, const Nodo* rhs) const { 
        return (lhs->costo + lhs->nivel) > (rhs->costo + rhs->nivel); 
    } 
};

class Puzzle {
private:
    int tipo_puzzle;
    vector<vector<string>>* puzzle;
    int x, y;
    int contador;
    ALLEGRO_FONT* letra;
    ALLEGRO_DISPLAY* pantalla;
public:
    Puzzle(ALLEGRO_FONT*, ALLEGRO_DISPLAY*, int);
    ~Puzzle();
    void capturaPuzzle(); //Se genera el menú para la solicitud del puzzle.
    void generaPuzzle(); //Se genera el puzzle de forma aleatoria.
    //void imprimePuzzle(); //Se imprime el puzzle en pantalla.
    void resuelve(int,int, vector<vector<string>> &); //Si tiene solución, se resuelve el puzzle por medio del algoritmo branch and bound.
    bool operator==(Puzzle &);
private:
    void imprimir_interfaz_captura(int, int, int); //Se imprime la interfaz para la solicitud.
    char validar_entrada(ALLEGRO_EVENT); //Se verifica que el caracter ingresado sea numérico.
    bool entrada_valida(int, int); //Se verifica si la entrada actual es repetida/válida o no.
	int generar_numero_aleatorio(); //Se genera un valor aleatorio según la dificultad de la partida.
    int calculaCosto(vector<vector<string>> &, vector<vector<string>> &);
    bool esCoordenada(int,int);
    void imprimeRuta(Nodo *);
};

#endif