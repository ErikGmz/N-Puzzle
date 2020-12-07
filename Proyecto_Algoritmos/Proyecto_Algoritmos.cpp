/*
Proyecto Final - Análisis de eficiencia de los algoritmos de ordenación.

Integrantes de equipo:
    - Erik Alejandro Gómez Martánez.
    - Israel Alejandro Mora González.
    - Ángel Gabriel Galindo López.
    - José Emmanuel Rodríguez López.

Fecha de entrega: 18 de diciembre de 2020.

Descripción general: Análisis de eficiencia de los métodos de ordenamiento cerrados. Se realiza un análisis comparativo
entre los distintos métodos de ordenamiento. Las pruebas se realizan sobre un vector que es generado de manera ascendente
(mejor caso), de manera aleatoria (caso intermedio) y de manera descendente (peor caso). El programa muestra un análisis
en tiempos de ejecución y en operaciones realizadas por cada método.

El programa esta contruido bajo el paradigma de programación orientada a objetos. El programa consta de tres clases. 

Programa desarrollado en el IDE Visual Studio 2019.
*/
#include "Sistema.hpp"

int main() {
    Sistema sistema;
    srand(time(0));

    sistema.pantalla_Principal();
    sistema.pantalla_Vectores();
    sistema.pantalla_Ordenacion();
    sistema.pantalla_StatusTiempo();
    sistema.pantalla_StatusCalculos();

    return 0;
}