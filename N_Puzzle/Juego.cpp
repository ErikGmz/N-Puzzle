//-----Compilación del archivo fuente-----//.
#ifndef Juego_cpp
#define Juego_cpp

//-----Librerías-----//.
#include "Juego.hpp"

//-----Implementación de funciones-----//.
bool ordenamiento_descendente(Jugador a, Jugador b) {
    return (a.getPuntaje() > b.getPuntaje());
}

//-----Métodos de la clase 'Juego'-----//.
//---Funciones privadas---//.
//Se imprime la interfaz de la pantalla de título.
void Juego::imprimir_interfaz_titulo() {
    this->contador++;
    ALLEGRO_BITMAP* icono_titulo = al_load_bitmap("Sources/titulo.png");
    ALLEGRO_BITMAP* cubo1 = al_load_bitmap("Sources/Cubo chico 1.png");
    ALLEGRO_BITMAP* cubo2 = al_load_bitmap("Sources/Cubo chico 2.png");
    ALLEGRO_BITMAP* cubo3 = al_load_bitmap("Sources/Cubo chico 3.png");
    ALLEGRO_BITMAP* cubo4 = al_load_bitmap("Sources/Cubo grande.png");

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(icono_titulo, 100, 50, NULL); 

    al_draw_bitmap(cubo4, 140, 230, NULL); 
    al_draw_bitmap(cubo1, 320, 250, NULL);
    al_draw_bitmap(cubo2, 460, 250, NULL);
    al_draw_bitmap(cubo3, 600, 250, NULL);

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
    al_destroy_bitmap(icono_titulo);
    al_destroy_bitmap(cubo1);  al_destroy_bitmap(cubo2);
    al_destroy_bitmap(cubo3);  al_destroy_bitmap(cubo4);
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_menu() {
    if (this->x >= 200 && this->x <= 600 && this->y >= 60 && this->y <= 120) return 1;
    else if (this->x >= 250 && this->x <= 550 && this->y >= 180 && this->y <= 240) return 2;
    else if (this->x >= 320 && this->x <= 481 && this->y >= 300 && this->y <= 360) return 3;
    else return 4;
}

//Se imprime la interfaz del menú principal.
void Juego::imprimir_interfaz_menu() {
    this->contador++;
    ALLEGRO_BITMAP* iniciar_juego = al_load_bitmap("Sources/iniciarjuego.png");
    ALLEGRO_BITMAP* records = al_load_bitmap("Sources/Records.png");
    ALLEGRO_BITMAP* salir = al_load_bitmap("Sources/salir.png");
    ALLEGRO_BITMAP* cubo = al_load_bitmap("Sources/Cubo grande.png");

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(iniciar_juego, 200, 60, NULL);
    al_draw_bitmap(records, 250, 180, NULL);
    al_draw_bitmap(salir, 320, 300, NULL);

    al_draw_bitmap(cubo, 50, 210, NULL);
    al_draw_bitmap(cubo, 650, 210, NULL);

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(220, 220, 220), 400, 430, ALLEGRO_ALIGN_CENTRE, "SELECCIONE UNA OPCION");
    al_destroy_bitmap(iniciar_juego);  al_destroy_bitmap(records);
    al_destroy_bitmap(salir);  al_destroy_bitmap(cubo);
    al_flip_display();
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_menu_Dificultad() {
    if (this->x >= 330 && this->x <= 479 && this->y >= 150 && this->y <= 210) return 1;
    else if (this->x >= 325 && this->x <= 478 && this->y >= 280 && this->y <= 340) return 2;
    else if (this->x >= 320 && this->x <= 486 && this->y >= 410 && this->y <= 470) return 3;
    else if (this->x >= 64 && this->x <= 122 && this->y >= 410 && this->y <= 466) return 4;
    else return 5;
}

//Se imprime la interfaz del selector de dificultad.
void Juego::imprimir_interfaz_menu_Dificultad() {
    ALLEGRO_BITMAP* regresar = al_load_bitmap("Sources/iconoregresar.png");
    ALLEGRO_BITMAP* facil = al_load_bitmap("Sources/iconofacil.png");
    ALLEGRO_BITMAP* medio = al_load_bitmap("Sources/icono media.png");
    ALLEGRO_BITMAP* dificil = al_load_bitmap("Sources/icono dificil.png");
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(this->letra, al_map_rgb(189, 252, 166), 400, 50, ALLEGRO_ALIGN_CENTRE, "SELECCIONE LA DIFICULTAD");

    al_draw_bitmap(facil, 330, 150, NULL);
    al_draw_bitmap(medio, 325, 280, NULL);
    al_draw_bitmap(dificil, 320, 410, NULL);
    al_draw_bitmap(regresar, 65, 410, NULL);

    al_flip_display();
    al_destroy_bitmap(regresar); al_destroy_bitmap(facil);
    al_destroy_bitmap(medio); al_destroy_bitmap(dificil);
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_menu_Modo() {
    if (this->x >= 298 && this->x <= 502 && this->y >= 200 && this->y <= 260) return 1;
    else if (this->x >= 250 && this->x <= 555 && this->y >= 360 && this->y <= 420) return 2;
    else if (this->x >= 55 && this->x <= 111 && this->y >= 365 && this->y <= 421) return 3;
    else return 4;
}

//Se imprime la interfaz del selector de modo.
void Juego::imprimir_interfaz_menu_Modo() {
    ALLEGRO_BITMAP* regresar = al_load_bitmap("Sources/iconoregresar.png");
    ALLEGRO_BITMAP* automatico = al_load_bitmap("Sources/Automatico.png");
    ALLEGRO_BITMAP* manual = al_load_bitmap("Sources/icono manual.png");

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(216, 227, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "SELECCIONE EL MODO");

    al_draw_bitmap(manual, 298, 200, NULL);
    al_draw_bitmap(automatico, 250, 360, NULL);
    al_draw_bitmap(regresar, 55, 365, NULL);

    al_flip_display();
    al_destroy_bitmap(regresar); al_destroy_bitmap(manual);
    al_destroy_bitmap(automatico);
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_Records() {
    if (this->x >= 65 && this->x <= 121 && this->y >= 458 && this->y <= 515) return 1;
    else if (this->x >= 400 && this->x <= 750 && this->y >= 458 && this->y <= 515) return 2;
    else return 3;
}

//Se imprime la interfaz del menú de récords.
void Juego::imprimir_interfaz_Records() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    ALLEGRO_BITMAP* regresar1 = al_load_bitmap("Sources/iconoregresar.png");
    ALLEGRO_BITMAP* eliminar1 = al_load_bitmap("Sources/Borrar registro.png");
    ALLEGRO_FONT* titulo = al_load_font("Fonts/slkscre.ttf", 35, NULL);
    ALLEGRO_FONT* letra = al_load_font("Fonts/slkscre.ttf", 25, NULL);

    al_draw_text(titulo, al_map_rgb(255, 163, 1), 400, 30, ALLEGRO_ALIGN_CENTRE, "RECORDS");
    al_draw_text(letra, al_map_rgb(253, 198, 104), 400, 80, ALLEGRO_ALIGN_CENTRE, "Lugar    Nombre    Puntaje     Fecha    ");
    al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 125, ALLEGRO_ALIGN_CENTRE, "1.-");
    al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 170, ALLEGRO_ALIGN_CENTRE, "2.-");
    al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 215, ALLEGRO_ALIGN_CENTRE, "3.-");
    al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 260, ALLEGRO_ALIGN_CENTRE, "4.-");
    al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 305, ALLEGRO_ALIGN_CENTRE, "5.-");
    al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 350, ALLEGRO_ALIGN_CENTRE, "6.-");
    al_draw_text(letra, al_map_rgb(204, 255, 255), 86, 395, ALLEGRO_ALIGN_CENTRE, "7.-");
    this->mostrar_registro();

    al_draw_bitmap(regresar1, 65, 458, NULL);
    al_draw_bitmap(eliminar1, 400, 458, NULL);
    al_flip_display();

    al_destroy_font(titulo); al_destroy_font(letra);
    al_destroy_bitmap(regresar1); al_destroy_bitmap(eliminar1);
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_confirmacion() {
    if (this->x >= 270 && this->x <= 530 && this->y >= 200 && this->y <= 260) return 1;
    else if (this->x >= 285 && this->x <= 518 && this->y >= 360 && this->y <= 420) return 2;
    else return 3;
}

//Se imprime la interfaz de la pantalla para confirmar la eliminación del registro.
void Juego::imprimir_interfaz_confirmacion() {
    ALLEGRO_BITMAP* regresar = al_load_bitmap("Sources/icono regresar.png");
    ALLEGRO_BITMAP* eliminar = al_load_bitmap("Sources/icono eliminar.png");
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(this->letra, al_map_rgb(247, 188, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "CONFIRME LA ELIMINACION");
    al_draw_text(this->letra, al_map_rgb(247, 188, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "DEL REGISTRO");
    al_draw_bitmap(regresar, 270, 200, NULL);
    al_draw_bitmap(eliminar, 285, 360, NULL);

    al_flip_display();
    al_destroy_bitmap(regresar); al_destroy_bitmap(eliminar);
}

//Se imprime la intefaz de eliminación.
void Juego::imprimir_interfaz_eliminacion() {
    this->contador++;
    ALLEGRO_BITMAP* cubo1 = al_load_bitmap("Sources/Cubo chico 1.png");
    ALLEGRO_BITMAP* cubo2 = al_load_bitmap("Sources/Cubo chico 2.png");
    ALLEGRO_BITMAP* cubo3 = al_load_bitmap("Sources/Cubo chico 3.png");
    ALLEGRO_BITMAP* cubo4 = al_load_bitmap("Sources/Cubo grande.png");

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(190, 231, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "REGISTRO BORRADO");

    al_draw_bitmap(cubo4, 50, 200, NULL);
    al_draw_bitmap(cubo1, 210, 170, NULL);
    al_draw_bitmap(cubo2, 330, 260, NULL);
    al_draw_bitmap(cubo3, 450, 170, NULL);
    al_draw_bitmap(cubo1, 570, 260, NULL);
    al_draw_bitmap(cubo2, 690, 170, NULL);

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
    al_destroy_bitmap(cubo1); al_destroy_bitmap(cubo2);
    al_destroy_bitmap(cubo3); al_destroy_bitmap(cubo4);
}

//Se imprime la interfaz de la pantalla de salida.
void Juego::imprimir_interfaz_salida() {
    this->contador++;
    ALLEGRO_BITMAP* cubo1 = al_load_bitmap("Sources/Cubo chico 1.png");
    ALLEGRO_BITMAP* cubo2 = al_load_bitmap("Sources/Cubo chico 2.png");
    ALLEGRO_BITMAP* cubo3 = al_load_bitmap("Sources/Cubo chico 3.png");
    ALLEGRO_BITMAP* cubo4 = al_load_bitmap("Sources/Cubo grande.png");

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(164, 255, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "GRACIAS POR JUGAR :)");

    al_draw_bitmap(cubo4, 50, 200, NULL);
    al_draw_bitmap(cubo1, 210, 170, NULL);
    al_draw_bitmap(cubo2, 330, 260, NULL);
    al_draw_bitmap(cubo3, 450, 170, NULL);
    al_draw_bitmap(cubo1, 570, 260, NULL);
    al_draw_bitmap(cubo2, 690, 170, NULL);

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
    al_destroy_bitmap(cubo1); al_destroy_bitmap(cubo2);
    al_destroy_bitmap(cubo3); al_destroy_bitmap(cubo4);
}

//Se imprime la interfaz del menú de finalización.
void Juego::imprimir_interfaz_finJuego(Jugador jugador_actual) {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(255, 192, 201), 400, 50, ALLEGRO_ALIGN_CENTRE, "PARTIDA FINALIZADA");
    al_draw_text(this->letra, al_map_rgb(255, 204, 102), 400, 130, ALLEGRO_ALIGN_CENTRE, "EL PUNTAJE DEL JUGADOR");
    al_draw_text(this->letra, al_map_rgb(255, 204, 102), 400, 180, ALLEGRO_ALIGN_CENTRE, ((jugador_actual.getNombre() + " FUE " + to_string(jugador_actual.getPuntaje())).c_str()));

    al_draw_text(this->letra, al_map_rgb(229, 229, 255), 400, 260, ALLEGRO_ALIGN_CENTRE, "EL TIEMPO UTILIZADO FUE");
    al_draw_text(this->letra, al_map_rgb(229, 229, 255), 400, 310, ALLEGRO_ALIGN_CENTRE, this->formato_tiempo());

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
}

//Se imprime la interfaz del menú para el fin de la simulación.
void Juego::imprimir_fin_simulacion(int parametro) {
    this->contador++;
    ALLEGRO_BITMAP* cubo1 = al_load_bitmap("Sources/Cubo chico 1.png");
    ALLEGRO_BITMAP* cubo2 = al_load_bitmap("Sources/Cubo chico 2.png");
    ALLEGRO_BITMAP* cubo3 = al_load_bitmap("Sources/Cubo chico 3.png");
    ALLEGRO_BITMAP* cubo4 = al_load_bitmap("Sources/Cubo grande.png");
    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (parametro == 1) {
        al_draw_text(this->letra, al_map_rgb(190, 231, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "SIMULACION TERMINADA");
    }
    else if (parametro == 2){
        al_draw_text(this->letra, al_map_rgb(190, 231, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "SISTEMA SIN SOLUCION");
    }
    else {
        al_draw_text(this->letra, al_map_rgb(190, 231, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "PUZZLES IGUALES");
    }

    al_draw_bitmap(cubo4, 50, 200, NULL);
    al_draw_bitmap(cubo1, 210, 170, NULL);
    al_draw_bitmap(cubo2, 330, 260, NULL);
    al_draw_bitmap(cubo3, 450, 170, NULL);
    al_draw_bitmap(cubo1, 570, 260, NULL);
    al_draw_bitmap(cubo2, 690, 170, NULL);

    if (this->contador == 55) {
        if (this->parpadeo) {
            this->parpadeo = false;
        }
        else {
            this->parpadeo = true;
        }
        this->contador = 0;
    }
    if (this->parpadeo) al_draw_text(this->letra, al_map_rgb(228, 255, 152), 403, 400, ALLEGRO_ALIGN_CENTRE, "PRESIONE ENTER");
    al_flip_display();
    al_destroy_bitmap(cubo1); al_destroy_bitmap(cubo2);
    al_destroy_bitmap(cubo3); al_destroy_bitmap(cubo4);
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_modo_manual(vector<Par_coordenadas> parametros) {
    for (auto it : parametros) {
        if (this->x >= it.x_inicial && this->x <= it.x_final && this->y >= it.y_inicial && this->y <= it.y_final) {
            return it.posicion;
        }
    }
    if (this->x >= 50 && this->x <= 280 && this->y >= 460 && this->y <= 520) return 5;
    else if (this->x >= 480 && this->x <= 741 && this->y >= 460 && this->y <= 520) return 6;
    else return 7;
}

//Se imprime la interfaz de la partida manual.
void Juego::imprimir_interfaz_modo_manual(Jugador jugador_actual, Puzzle* tablero_inicial, Puzzle* tablero_final) {
    string* auxiliar = new string;
    ALLEGRO_FONT* letra = al_load_font("Fonts/slkscre.ttf", 32, NULL);
    ALLEGRO_FONT* letra1 = al_load_font("Fonts/slkscre.ttf", 30, NULL);
    ALLEGRO_FONT* letra2 = al_load_font("Fonts/slkscre.ttf", 26, NULL);
    ALLEGRO_BITMAP* puzzle_3x3 = al_load_bitmap("Sources/TableroFacil3x3.png");
    ALLEGRO_BITMAP* puzzle_4x4 = al_load_bitmap("Sources/TableroMedio4x4.png");
    ALLEGRO_BITMAP* puzzle_5x5 = al_load_bitmap("Sources/TableroDificil5x5.png");
    ALLEGRO_BITMAP* regresar = al_load_bitmap("Sources/icono regresar.png");

    vector<ALLEGRO_BITMAP*>* fichas = new vector<ALLEGRO_BITMAP*>;
    for (int i = 1; i < 25; i++) {
        string aux = "Sources/Fichas/F";
        ALLEGRO_BITMAP* elemento = al_load_bitmap((aux + to_string(i) + ".png").c_str());
        fichas->push_back(elemento);
    }

    switch (this->getDificultad()) {
    case 3: *auxiliar = "FACIL"; break;
    case 4: *auxiliar = "NORMAL"; break;
    case 5: *auxiliar = "DIFICIL"; break;
    }

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(letra, al_map_rgb(250, 201, 136), 425, 20, ALLEGRO_ALIGN_CENTRE, "DIFICULTAD");
    al_draw_text(letra, al_map_rgb(252, 252, 164), 425, 60, ALLEGRO_ALIGN_CENTRE, auxiliar->c_str());
    al_draw_text(letra, al_map_rgb(179, 189, 250), 150, 20, ALLEGRO_ALIGN_CENTRE, "JUGADOR");
    al_draw_text(letra, al_map_rgb(233, 188, 255), 150, 60, ALLEGRO_ALIGN_CENTRE, jugador_actual.getNombre().c_str());
    al_draw_text(letra, al_map_rgb(140, 252, 185), 670, 20, ALLEGRO_ALIGN_CENTRE, "TIEMPO");
    al_draw_text(letra, al_map_rgb(197, 255, 180), 670, 60, ALLEGRO_ALIGN_CENTRE, this->formato_tiempo());
    delete auxiliar;

    switch (this->getDificultad()) {
    case 3: 
        al_draw_text(letra1, al_map_rgb(253, 230, 183), 189, 155, ALLEGRO_ALIGN_CENTRE, "INICIO");
        al_draw_bitmap(puzzle_3x3, 108, 200, NULL);
        al_draw_text(letra1, al_map_rgb(253, 230, 183), 609, 155, ALLEGRO_ALIGN_CENTRE, "META");
        al_draw_bitmap(puzzle_3x3, 528, 200, NULL);
        break;
    case 4: 
        al_draw_text(letra1, al_map_rgb(252, 204, 143), 181, 135, ALLEGRO_ALIGN_CENTRE, "INICIO");
        al_draw_bitmap(puzzle_4x4, 73, 180, NULL);
        al_draw_text(letra1, al_map_rgb(252, 204, 143), 619, 135, ALLEGRO_ALIGN_CENTRE, "META");
        al_draw_bitmap(puzzle_4x4, 511, 180, NULL);
        break;
    case 5: 
        al_draw_text(letra2, al_map_rgb(252, 143, 143), 222, 124, ALLEGRO_ALIGN_CENTRE, "INICIO");
        al_draw_bitmap(puzzle_5x5, 88, 160, NULL);
        al_draw_text(letra2, al_map_rgb(252, 143, 143), 578, 124, ALLEGRO_ALIGN_CENTRE, "META");
        al_draw_bitmap(puzzle_5x5, 444, 160, NULL);
        break;
    }

    al_draw_filled_rectangle(50, 460, 280, 520, al_map_rgb(255, 255, 255));
    al_draw_bitmap(regresar, 480, 460, NULL);

    for (int i = 0; i < this->getDificultad(); i++) {
        for (int j = 0; j < this->getDificultad(); j++) {
            if (tablero_inicial[0][i][j] != "0") {
                valores auxiliar2 = this->convertir_string(tablero_inicial[0][i][j]);

                switch (this->dificultad) {
                case 3: al_draw_bitmap(fichas[0][auxiliar2], 108 + j * 53 + 3, 200 + i * 53 + 3, NULL); break;
                case 4: al_draw_bitmap(fichas[0][auxiliar2], 73 + j * 53 + 3, 180 + i * 53 + 3, NULL); break;
                case 5: al_draw_bitmap(fichas[0][auxiliar2], 88 + j * 53 + 3, 160 + i * 53 + 3, NULL); break;
                }
            }
        }
    }

    for (int i = 0; i < this->getDificultad(); i++) {
        for (int j = 0; j < this->getDificultad(); j++) {
            if (tablero_final[0][i][j] != "0") {
                valores auxiliar3 = this->convertir_string(tablero_final[0][i][j]);

                switch (this->dificultad) {
                case 3: al_draw_bitmap(fichas[0][auxiliar3], 528 + j * 53 + 3, 200 + i * 53 + 3, NULL); break;
                case 4: al_draw_bitmap(fichas[0][auxiliar3], 511 + j * 53 + 3, 180 + i * 53 + 3, NULL); break;
                case 5: al_draw_bitmap(fichas[0][auxiliar3], 444 + j * 53 + 3, 160 + i * 53 + 3, NULL); break;
                }
            }
        }
    }

    al_flip_display();
    al_destroy_font(letra); al_destroy_font(letra1); al_destroy_font(letra2);
    al_destroy_bitmap(puzzle_3x3); al_destroy_bitmap(puzzle_4x4); al_destroy_bitmap(puzzle_5x5);
    al_destroy_bitmap(regresar);
    delete fichas;
}

//Se imprime la interfaz para la solicitud.
void Juego::imprimir_interfaz_captura(int conteo, int tipo_puzzle, Puzzle *inicio, Puzzle *fin) {
    ALLEGRO_FONT* letra = al_load_font("Fonts/slkscre.ttf", 32, NULL);
    ALLEGRO_FONT* letra1 = al_load_font("Fonts/slkscre.ttf", 30, NULL);
    ALLEGRO_FONT* letra2 = al_load_font("Fonts/slkscre.ttf", 26, NULL);
    ALLEGRO_BITMAP* puzzle_3x3 = al_load_bitmap("Sources/TableroFacil3x3.png");
    ALLEGRO_BITMAP* puzzle_4x4 = al_load_bitmap("Sources/TableroMedio4x4.png");
    ALLEGRO_BITMAP* puzzle_5x5 = al_load_bitmap("Sources/TableroDificil5x5.png");
    ALLEGRO_BITMAP* regresar = al_load_bitmap("Sources/icono regresar.png");

    vector<ALLEGRO_BITMAP*>* fichas = new vector<ALLEGRO_BITMAP*>;
    for (int i = 1; i < 25; i++) {
        string aux = "Sources/Fichas/F";
        ALLEGRO_BITMAP* elemento = al_load_bitmap((aux + to_string(i) + ".png").c_str());
        fichas->push_back(elemento);
    }

    al_clear_to_color(al_map_rgb(0, 0, 0));

    if (tipo_puzzle == 1) al_draw_text(this->letra, al_map_rgb(255, 195, 243), 400, 20, ALLEGRO_ALIGN_CENTRE, "PUZZLE INICIAL");
    else al_draw_text(this->letra, al_map_rgb(166, 226, 255), 400, 20, ALLEGRO_ALIGN_CENTRE, "PUZZLE META");
    string* auxiliar = new string;
    *auxiliar = "POSICIONE LA FICHA NO. ";

    switch (conteo) {     
    case 1: *auxiliar += "1"; break;    case 16: *auxiliar += "16"; break;
    case 2: *auxiliar += "2"; break;    case 17: *auxiliar += "17"; break;
    case 3: *auxiliar += "3"; break;    case 18: *auxiliar += "18"; break;
    case 4: *auxiliar += "4"; break;    case 19: *auxiliar += "19"; break;
    case 5: *auxiliar += "5"; break;    case 20: *auxiliar += "20"; break;
    case 6: *auxiliar += "6"; break;    case 21: *auxiliar += "21"; break;
    case 7: *auxiliar += "7"; break;    case 22: *auxiliar += "22"; break;
    case 8: *auxiliar += "8"; break;    case 23: *auxiliar += "23"; break;
    case 9: *auxiliar += "9"; break;    case 24: *auxiliar += "24"; break;
    case 10: *auxiliar += "10"; break;
    case 11: *auxiliar += "11"; break;
    case 12: *auxiliar += "12"; break;
    case 13: *auxiliar += "13"; break;
    case 14: *auxiliar += "14"; break;
    case 15: *auxiliar += "15"; break;
    }
    al_draw_text(this->letra, al_map_rgb(189, 249, 201), 400, 70, ALLEGRO_ALIGN_CENTRE, auxiliar->c_str());

    switch (this->getDificultad()) {
    case 3:
        al_draw_text(letra1, al_map_rgb(253, 230, 183), 189, 160, ALLEGRO_ALIGN_CENTRE, "INICIO");
        al_draw_bitmap(puzzle_3x3, 108, 200, NULL);
        al_draw_text(letra1, al_map_rgb(253, 230, 183), 609, 160, ALLEGRO_ALIGN_CENTRE, "META");
        al_draw_bitmap(puzzle_3x3, 528, 200, NULL);
        break;
    case 4:
        al_draw_text(letra1, al_map_rgb(252, 204, 143), 181, 140, ALLEGRO_ALIGN_CENTRE, "INICIO");
        al_draw_bitmap(puzzle_4x4, 73, 180, NULL);
        al_draw_text(letra1, al_map_rgb(252, 204, 143), 619, 140, ALLEGRO_ALIGN_CENTRE, "META");
        al_draw_bitmap(puzzle_4x4, 511, 180, NULL);
        break;
    case 5:
        al_draw_text(letra2, al_map_rgb(252, 143, 143), 222, 129, ALLEGRO_ALIGN_CENTRE, "INICIO");
        al_draw_bitmap(puzzle_5x5, 88, 160, NULL);
        al_draw_text(letra2, al_map_rgb(252, 143, 143), 578, 129, ALLEGRO_ALIGN_CENTRE, "META");
        al_draw_bitmap(puzzle_5x5, 444, 160, NULL);
        break;
    }
    al_draw_bitmap(regresar, 270, 460, NULL);

    for (int i = 0; i < this->getDificultad(); i++) {
        for (int j = 0; j < this->getDificultad(); j++) {
            if (inicio[0][i][j] != "0") {
                valores auxiliar2 = this->convertir_string(inicio[0][i][j]);

                switch (this->dificultad) {
                case 3: al_draw_bitmap(fichas[0][auxiliar2], 108 + j * 53 + 3, 200 + i * 53 + 3, NULL); break;
                case 4: al_draw_bitmap(fichas[0][auxiliar2], 73 + j * 53 + 3, 180 + i * 53 + 3, NULL); break;
                case 5: al_draw_bitmap(fichas[0][auxiliar2], 88 + j * 53 + 3, 160 + i * 53 + 3, NULL); break;
                }
            }
        }
    }

    for (int i = 0; i < this->getDificultad(); i++) {
        for (int j = 0; j < this->getDificultad(); j++) {
            if (fin[0][i][j] != "0") {
                valores auxiliar3 = this->convertir_string(fin[0][i][j]);

                switch (this->dificultad) {
                case 3: al_draw_bitmap(fichas[0][auxiliar3], 528 + j * 53 + 3, 200 + i * 53 + 3, NULL); break;
                case 4: al_draw_bitmap(fichas[0][auxiliar3], 511 + j * 53 + 3, 180 + i * 53 + 3, NULL); break;
                case 5: al_draw_bitmap(fichas[0][auxiliar3], 444 + j * 53 + 3, 160 + i * 53 + 3, NULL); break;
                }
            }
        }
    }

    al_flip_display();
    al_destroy_font(letra); al_destroy_font(letra1); al_destroy_font(letra2);
    al_destroy_bitmap(puzzle_3x3); al_destroy_bitmap(puzzle_4x4); al_destroy_bitmap(puzzle_5x5);
    al_destroy_bitmap(regresar);
    delete auxiliar;
}

//Se retorna un vector con las coordenadas de espacios restantes de un tablero.
vector<Coordenadas> Juego::lugares_disponibles(Puzzle* tablero, int tipo_tablero) {
    vector<Coordenadas> lista_espacios;
    int x_inicial, y_inicial;

    switch (this->dificultad) {
    case 3: 
        if (tipo_tablero == 1) {
            x_inicial = 108; y_inicial = 200; 
        }
        else {
            x_inicial = 528; y_inicial = 200;
        }
        break;
    case 4: 
        if (tipo_tablero == 1) {
            x_inicial = 73; y_inicial = 180; 
        }
        else {
            x_inicial = 511; y_inicial = 180; 
        }
        break;
    case 5: 
        if (tipo_tablero == 1) {
            x_inicial = 88; y_inicial = 160;
        }
        else {
            x_inicial = 444; y_inicial = 160;
        }
        break;
    }
    
    for (int i = 0; i < this->dificultad; i++) {
        for (int j = 0; j < this->dificultad; j++) {
            if (tablero[0][i][j] == "0") {
                Coordenadas auxiliar;
                auxiliar.x_inicial = x_inicial + j * 53 + 3;        
                auxiliar.y_inicial = y_inicial + i * 53 + 3;
                auxiliar.x_final = x_inicial + (j + 1) * 53 + 3;
                auxiliar.y_final = y_inicial + (i + 1) * 53 + 3;
                auxiliar.posicion = this->definir_posicion(i, j);
                lista_espacios.push_back(auxiliar);
            }
        }
    }
    return lista_espacios;
}

//Se define a qué valor corresponde un par fila/columna.
int Juego::definir_posicion(int i, int j) {
    switch (i) {
    case 0:
        switch (j) {
        case 0: return 1; break;
        case 1: return 2; break;
        case 2: return 3; break;
        case 3: return 4; break;
        case 4: return 5; break;
        }
        break;
    case 1:
        switch (j) {
        case 0: return 6; break;
        case 1: return 7; break;
        case 2: return 8; break;
        case 3: return 9; break;
        case 4: return 10; break;
        }
        break;
    case 2:
        switch (j) {
        case 0: return 11; break;
        case 1: return 12; break;
        case 2: return 13; break;
        case 3: return 14; break;
        case 4: return 15; break;
        }
        break;
    case 3:
        switch (j) {
        case 0: return 16; break;
        case 1: return 17; break;
        case 2: return 18; break;
        case 3: return 19; break;
        case 4: return 20; break;
        }
        break;
    case 4:
        switch (j) {
        case 0: return 21; break;
        case 1: return 22; break;
        case 2: return 23; break;
        case 3: return 24; break;
        case 4: return 25; break;
        }
        break;
    }
    return 0;
}

//Se determina en cuál espacio está posicionado el cursor.
int Juego::posicionado(vector<Coordenadas> lista_espacios) {
    for (auto it : lista_espacios) {
        if (this->x >= it.x_inicial && this->x <= it.x_final && this->y >= it.y_inicial && this->y <= it.y_final) {
            return it.posicion;
        }
    }
    if (this->x >= 260 && this->x <= 540 && this->y >= 460 && this->y <= 520) return 26;
    else return 27;
}

//Se muestran los datos de cada jugador dentro del ranking.
void Juego::mostrar_registro() {
    fstream archivo("registro.dat", ios::binary | ios::in);
    ALLEGRO_FONT* menor = al_load_font("Fonts/slkscre.ttf", 23, NULL);
    ALLEGRO_FONT* menor2 = al_load_font("Fonts/slkscre.ttf", 25, NULL);
    int contador = 0;

    if (archivo) {
        Datos_Guardar* aux = new Datos_Guardar;

        archivo.read(reinterpret_cast <char*>(aux), sizeof(Datos_Guardar));
        while (!archivo.eof()) {
            if (contador < 7) {
                al_draw_text(menor, al_map_rgb(230, 197, 252), 263, 125 + contador * 45, ALLEGRO_ALIGN_CENTRE, aux->nombre);
                al_draw_text(menor2, al_map_rgb(202, 255, 175), 460, 123 + contador * 45, ALLEGRO_ALIGN_CENTRE, to_string(aux->puntaje).c_str());
                al_draw_text(menor, al_map_rgb(255, 197, 168), 657, 127 + contador * 45, ALLEGRO_ALIGN_CENTRE, aux->fecha);
                contador++;
            }
            else {
                break;
            }
            archivo.read(reinterpret_cast <char*>(aux), sizeof(Datos_Guardar));
        }
        delete aux;
    }
    if (contador < 7) {
        for (int i = contador; i < 7; i++) {
            al_draw_text(this->letra, al_map_rgb(230, 197, 252), 263, 125 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
            al_draw_text(this->letra, al_map_rgb(202, 255, 175), 460, 123 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
            al_draw_text(this->letra, al_map_rgb(255, 197, 168), 657, 127 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
        }
    }

    archivo.close();
    al_destroy_font(menor);
}

//Se actualiza el contenido del registro.
void Juego::actualizar_archivo(Jugador jugador_actual) {
    fstream archivo("registro.dat", ios::binary | ios::in);
    if (!archivo) {
        archivo.close();
        archivo.open("registro.dat", ios::binary | ios::out);
        archivo.close();
        fstream archivo("registro.dat", ios::binary | ios::in);
    }
    Jugador* aux1 = new Jugador;
    Datos_Guardar* aux2 = new Datos_Guardar;
    list<Jugador>* ordenamiento = new list<Jugador>;
    bool encontrado = false;

    archivo.read(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    while (!archivo.eof()) {
        aux1->setNombre(aux2->nombre);
        if (aux1->getNombre() == jugador_actual.getNombre()) {
            encontrado = true;
            aux1->setPuntaje(jugador_actual.getPuntaje());
            aux1->setfecha(jugador_actual.getFecha());
        }
        else {
            aux1->setPuntaje(aux2->puntaje);
            aux1->setfecha(aux2->fecha);
        }
        ordenamiento->push_back(*aux1);
        archivo.read(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    }
    if (!encontrado) {
        aux1->setNombre(jugador_actual.getNombre());
        aux1->setPuntaje(jugador_actual.getPuntaje());
        aux1->setfecha(jugador_actual.getFecha());
        ordenamiento->push_back(*aux1);
    }
    ordenamiento->sort(ordenamiento_descendente);

    archivo.clear(); archivo.close();
    remove("registro.dat");
    archivo.open("registro.dat", ios::binary | ios::out);

    for (auto it = ordenamiento->begin(); it != ordenamiento->end(); ++it) {
        strcpy_s(aux2->nombre, 40, it->getNombre().c_str());
        aux2->puntaje = it->getPuntaje();
        strcpy_s(aux2->fecha, 40, it->getFecha().c_str());
        archivo.write(reinterpret_cast <char*>(aux2), sizeof(Datos_Guardar));
    }
    archivo.clear(); archivo.close();
    delete aux1, aux2, ordenamiento;
}

//Se elimina el fichero, en caso de existir.
void Juego::eliminar_registro() {
    fstream archivo("registro.dat", ios::in);
    if (archivo) {
        archivo.close();
        remove("registro.dat");
    }
    else {
        archivo.close();
    }
}

//Se retorna un dígito en forma de caracter.
char Juego::numero_a_caracter(int digito) {
    switch (digito) {
    case 0: return '0'; break;
    case 1: return '1'; break;
    case 2: return '2'; break;
    case 3: return '3'; break;
    case 4: return '4'; break;
    case 5: return '5'; break;
    case 6: return '6'; break;
    case 7: return '7'; break;
    case 8: return '8'; break;
    case 9: return '9'; break;
    default: return 'a'; break;
    }
}

//Se convierte una cifra en un formato de tiempo.
char* Juego::formato_tiempo() {
    string formato;
    int minutos = 0, segundos = 0, horas = 0;
    int auxiliar = this->tiempo;

    while (auxiliar >= 3600) {
        horas++;
        auxiliar -= 3600;
    }
    while (auxiliar >= 60) {
        minutos++;
        auxiliar -= 60;
    }
    if (auxiliar > 0) {
        segundos += auxiliar;
    }
    if (horas < 10) {
        formato.push_back('0');
        formato.push_back(numero_a_caracter(horas));
    }
    else {
        formato.push_back(numero_a_caracter(horas / 10));
        formato.push_back(numero_a_caracter(horas % 10));
    }
    formato.push_back(':');

    if (minutos < 10) {
        formato.push_back('0');
        formato.push_back(numero_a_caracter(minutos));
    }
    else {
        formato.push_back(numero_a_caracter(minutos / 10));
        formato.push_back(numero_a_caracter(minutos % 10));
    }
    formato.push_back(':');

    if (segundos < 10) {
        formato.push_back('0');
        formato.push_back(numero_a_caracter(segundos));
    }
    else {
        formato.push_back(numero_a_caracter(segundos / 10));
        formato.push_back(numero_a_caracter(segundos % 10));
    }

    char* retorno = new char[10];
    strcpy_s(retorno, 10, formato.c_str());
    return retorno;
}

//Se convierte un string a una enumeración.  
valores Juego::convertir_string(string valor) {
    if (valor == "1") return v1;         else if (valor == "2") return v2;    else if (valor == "3") return v3;
    else if (valor == "4") return v4;    else if (valor == "5") return v5;    else if (valor == "6") return v6;
    else if (valor == "7") return v7;    else if (valor == "8") return v8;    else if (valor == "9") return v9;
    else if (valor == "10") return v10;  else if (valor == "11") return v11;  else if (valor == "12") return v12;
    else if (valor == "13") return v13;  else if (valor == "14") return v14;  else if (valor == "15") return v15;
    else if (valor == "16") return v16;  else if (valor == "17") return v17;  else if (valor == "18") return v18;
    else if (valor == "19") return v19;  else if (valor == "20") return v20;  else if (valor == "21") return v21;
    else if (valor == "22") return v22;  else if (valor == "23") return v23;  else if (valor == "24") return v24;
    else return v1;
}

//Se retorna un vector con las coordenadas de los elementos que se pueden desplazar.
vector<Par_coordenadas> Juego::fichas_a_mover(Puzzle *tablero) {
    vector<Par_coordenadas> lista_fichas;
    Par_coordenadas arriba, abajo, izquierda, derecha;
    int x_inicial, y_inicial, x_final, y_final;
    bool definido = false;

    for (int i = 0; i < this->dificultad; i++) {
        for (int j = 0; j < this->dificultad; j++) {
            if (tablero[0][i][j] == "0") {

                switch (this->dificultad) {
                case 3: x_inicial = 108; y_inicial = 200; x_final = 155; y_final = 247; break;
                case 4: x_inicial = 73; y_inicial = 180; x_final = 120; y_final = 227; break;
                case 5: x_inicial = 88; y_inicial = 160; x_final = 135; y_final = 207; break;
                }

                if (i + 1 < this->dificultad && i - 1 >= 0 && j + 1 < this->dificultad && j - 1 >= 0) { //Posición central del espacio.
                    arriba.x_inicial = x_inicial + j * 53 + 3;        arriba.y_inicial = y_inicial + (i - 1) * 53 + 3;
                    arriba.x_final = x_final + j * 53 + 3;            arriba.y_final = y_final + (i - 1) * 53 + 3;
                    arriba.posicion = up;
                    lista_fichas.push_back(arriba);

                    abajo.x_inicial = x_inicial + j * 53 + 3;         abajo.y_inicial = y_inicial + (i + 1) * 53 + 3;
                    abajo.x_final = x_final + j * 53 + 3;             abajo.y_final = y_final + (i + 1) * 53 + 3;
                    abajo.posicion = down;
                    lista_fichas.push_back(abajo);

                    izquierda.x_inicial = x_inicial + (j - 1) * 53 + 3;   izquierda.y_inicial = y_inicial + i * 53 + 3;
                    izquierda.x_final = x_final + (j - 1) * 53 + 3;       izquierda.y_final = y_final + i * 53 + 3;
                    izquierda.posicion = leftt;
                    lista_fichas.push_back(izquierda);

                    derecha.x_inicial = x_inicial + (j + 1) * 53 + 3;     derecha.y_inicial = y_inicial + i * 53 + 3;
                    derecha.x_final = x_final + (j + 1) * 53 + 3;         derecha.y_final = y_final + i * 53 + 3;
                    derecha.posicion = rightt;
                    lista_fichas.push_back(derecha);
                    definido = true;
                    break;
                }
                if (i + 1 >= this->dificultad && j + 1 < this->dificultad && j - 1 >= 0) { //Espacio en el extremo inferior.
                    arriba.x_inicial = x_inicial + j * 53 + 3;        arriba.y_inicial = y_inicial + (i - 1) * 53 + 3;
                    arriba.x_final = x_final + j * 53 + 3;            arriba.y_final = y_final + (i - 1) * 53 + 3;
                    arriba.posicion = up;
                    lista_fichas.push_back(arriba);

                    izquierda.x_inicial = x_inicial + (j - 1) * 53 + 3;   izquierda.y_inicial = y_inicial + i * 53 + 3;
                    izquierda.x_final = x_final + (j - 1) * 53 + 3;       izquierda.y_final = y_final + i * 53 + 3;
                    izquierda.posicion = leftt;
                    lista_fichas.push_back(izquierda);

                    derecha.x_inicial = x_inicial + (j + 1) * 53 + 3;   derecha.y_inicial = y_inicial + i * 53 + 3;
                    derecha.x_final = x_final + (j + 1) * 53 + 3;       derecha.y_final = y_final + i * 53 + 3;
                    derecha.posicion = rightt;
                    lista_fichas.push_back(derecha);
                    definido = true;
                    break;
                }
                if (i - 1 < 0 && j + 1 < this->dificultad && j - 1 >= 0) { //Espacio en el extremo superior.
                    abajo.x_inicial = x_inicial + j * 53 + 3;         abajo.y_inicial = y_inicial + (i + 1) * 53 + 3;
                    abajo.x_final = x_final + j * 53 + 3;             abajo.y_final = y_final + (i + 1) * 53 + 3;
                    abajo.posicion = down;
                    lista_fichas.push_back(abajo);

                    izquierda.x_inicial = x_inicial + (j - 1) * 53 + 3;   izquierda.y_inicial = y_inicial + i * 53 + 3;
                    izquierda.x_final = x_final + (j - 1) * 53 + 3;       izquierda.y_final = y_final + i * 53 + 3;
                    izquierda.posicion = leftt;
                    lista_fichas.push_back(izquierda);

                    derecha.x_inicial = x_inicial + (j + 1) * 53 + 3;   derecha.y_inicial = y_inicial + i * 53 + 3;
                    derecha.x_final = x_final + (j + 1) * 53 + 3;       derecha.y_final = y_final + i * 53 + 3;
                    derecha.posicion = rightt;
                    lista_fichas.push_back(derecha);
                    definido = true;
                    break;
                }
                if (i + 1 < this->dificultad && i - 1 >= 0 && j - 1 < 0) { //Espacio en el extremo de la izquierda.
                    arriba.x_inicial = x_inicial + j * 53 + 3;        arriba.y_inicial = y_inicial + (i - 1) * 53 + 3;
                    arriba.x_final = x_final + j * 53 + 3;            arriba.y_final = y_final + (i - 1) * 53 + 3;
                    arriba.posicion = up;
                    lista_fichas.push_back(arriba);

                    abajo.x_inicial = x_inicial + j * 53 + 3;         abajo.y_inicial = y_inicial + (i + 1) * 53 + 3;
                    abajo.x_final = x_final + j * 53 + 3;             abajo.y_final = y_final + (i + 1) * 53 + 3;
                    abajo.posicion = down;
                    lista_fichas.push_back(abajo);

                    derecha.x_inicial = x_inicial + (j + 1) * 53 + 3;   derecha.y_inicial = y_inicial + i * 53 + 3;
                    derecha.x_final = x_final + (j + 1) * 53 + 3;       derecha.y_final = y_final + i * 53 + 3;
                    derecha.posicion = rightt;
                    lista_fichas.push_back(derecha);
                    definido = true;
                    break;
                }
                if (i + 1 < this->dificultad && i - 1 >= 0 && j + 1 >= this->dificultad) { //Espacio en el extremo de la derecha.
                    arriba.x_inicial = x_inicial + j * 53 + 3;        arriba.y_inicial = y_inicial + (i - 1) * 53 + 3;
                    arriba.x_final = x_final + j * 53 + 3;            arriba.y_final = y_final + (i - 1) * 53 + 3;
                    arriba.posicion = up;
                    lista_fichas.push_back(arriba);

                    abajo.x_inicial = x_inicial + j * 53 + 3;         abajo.y_inicial = y_inicial + (i + 1) * 53 + 3;
                    abajo.x_final = x_final + j * 53 + 3;             abajo.y_final = y_final + (i + 1) * 53 + 3;
                    abajo.posicion = down;
                    lista_fichas.push_back(abajo);

                    izquierda.x_inicial = x_inicial + (j - 1) * 53 + 3;   izquierda.y_inicial = y_inicial + i * 53 + 3;
                    izquierda.x_final = x_final + (j - 1) * 53 + 3;       izquierda.y_final = y_final + i * 53 + 3;
                    izquierda.posicion = leftt;
                    lista_fichas.push_back(izquierda);
                    definido = true;
                    break;
                }
                if (i + 1 >= this->dificultad && j - 1 < 0) { //Espacio en la esquina inferior izquierda.
                    arriba.x_inicial = x_inicial + j * 53 + 3;        arriba.y_inicial = y_inicial + (i - 1) * 53 + 3;
                    arriba.x_final = x_final + j * 53 + 3;            arriba.y_final = y_final + (i - 1) * 53 + 3;
                    arriba.posicion = up;
                    lista_fichas.push_back(arriba);

                    derecha.x_inicial = x_inicial + (j + 1) * 53 + 3;   derecha.y_inicial = y_inicial + i * 53 + 3;
                    derecha.x_final = x_final + (j + 1) * 53 + 3;       derecha.y_final = y_final + i * 53 + 3;
                    derecha.posicion = rightt;
                    lista_fichas.push_back(derecha);
                    definido = true;
                    break;
                }
                if (i + 1 >= this->dificultad && j + 1 >= this->dificultad) { //Espacio en la esquina inferior derecha.
                    arriba.x_inicial = x_inicial + j * 53 + 3;        arriba.y_inicial = y_inicial + (i - 1) * 53 + 3;
                    arriba.x_final = x_final + j * 53 + 3;            arriba.y_final = y_final + (i - 1) * 53 + 3;
                    arriba.posicion = up;
                    lista_fichas.push_back(arriba);

                    izquierda.x_inicial = x_inicial + (j - 1) * 53 + 3;   izquierda.y_inicial = y_inicial + i * 53 + 3;
                    izquierda.x_final = x_final + (j - 1) * 53 + 3;       izquierda.y_final = y_final + i * 53 + 3;
                    izquierda.posicion = leftt;
                    lista_fichas.push_back(izquierda);
                    definido = true;
                    break;
                }
                if (i - 1 < 0 && j - 1 < 0) { //Espacio en la esquina superior izquierda.
                    abajo.x_inicial = x_inicial + j * 53 + 3;         abajo.y_inicial = y_inicial + (i + 1) * 53 + 3;
                    abajo.x_final = x_final + j * 53 + 3;             abajo.y_final = y_final + (i + 1) * 53 + 3;
                    abajo.posicion = down;
                    lista_fichas.push_back(abajo);

                    derecha.x_inicial = x_inicial + (j + 1) * 53 + 3;   derecha.y_inicial = y_inicial + i * 53 + 3;
                    derecha.x_final = x_final + (j + 1) * 53 + 3;       derecha.y_final = y_final + i * 53 + 3;
                    derecha.posicion = rightt;
                    lista_fichas.push_back(derecha);
                    definido = true;
                    break;
                }
                if (i - 1 < 0 && j + 1 >= this->dificultad) { //Espacio en la esquina superior derecha.
                    abajo.x_inicial = x_inicial + j * 53 + 3;         abajo.y_inicial = y_inicial + (i + 1) * 53 + 3;
                    abajo.x_final = x_final + j * 53 + 3;             abajo.y_final = y_final + (i + 1) * 53 + 3;
                    abajo.posicion = down;
                    lista_fichas.push_back(abajo);

                    izquierda.x_inicial = x_inicial + (j - 1) * 53 + 3;   izquierda.y_inicial = y_inicial + i * 53 + 3;
                    izquierda.x_final = x_final + (j - 1) * 53 + 3;       izquierda.y_final = y_final + i * 53 + 3;
                    izquierda.posicion = leftt;
                    lista_fichas.push_back(izquierda);
                    definido = true;
                    break;
                }
            }
        }
        if (definido) break;
    }
    return lista_fichas;
}

//---Constructor---//.
Juego::Juego(ALLEGRO_FONT* formato, ALLEGRO_DISPLAY* ventana) {
    this->tiempo = 0;
    this->x = 0;
    this->y = 0;
    this->contador = 0;
    this->parpadeo = true;
    this->letra = formato;
    this->pantalla = ventana;
}

//---Métodos---//.
//Se genera la pantalla de título.
bool Juego::pantalla_titulo() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    ALLEGRO_SAMPLE* musica_titulo = al_load_sample("Sounds/Super Mario Bros 2 (NES) Music   Title Theme.mp3");
    ALLEGRO_SAMPLE_ID id1;
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    al_play_sample(musica_titulo, 0.5, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id1);
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                al_rest(0.5);
                al_stop_sample(&id1);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_titulo();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_titulo();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return false;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_stop_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    al_destroy_sample(musica_titulo);
    return true;
}

//Se genera el menú principal.
int Juego::pantalla_menu() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int retorno, auxiliar = 4, seleccion = 0;

    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            this->x = evento.mouse.x;
            this->y = evento.mouse.y;
            auxiliar = this->posicionado_menu();

            if (auxiliar >= 1 && auxiliar <= 3) {
                if (!sonido) {
                    sonido = true;
                    al_play_sample(apuntado, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
            }
            else {
                sonido = false;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (auxiliar >= 1 && auxiliar <= 3) {
                retorno = auxiliar;
                continuar = true;
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_menu();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_menu();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            retorno = 4;
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    al_destroy_sample(apuntado);
    return retorno;
}

//Se genera la pantalla del selector de dificultad.
int Juego::pantalla_menu_Dificultad() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int auxiliar = 5, retorno;

    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());

    this->imprimir_interfaz_menu_Dificultad();
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = evento.mouse.x;
            y = evento.mouse.y;
            auxiliar = this->posicionado_menu_Dificultad();

            if (auxiliar >= 1 && auxiliar <= 4) {
                if (!sonido) {
                    sonido = true;
                    al_play_sample(apuntado, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
            }
            else {
                sonido = false;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (auxiliar >= 1 && auxiliar <= 4) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
                retorno = auxiliar;
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_menu_Dificultad();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            retorno = 5;
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_destroy_sample(avance);
    al_destroy_sample(apuntado);
    return retorno;
}

//Se genera la pantalla del selector de modo.
int Juego::pantalla_menu_Modo(ALLEGRO_SAMPLE_ID id1) {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int auxiliar = 4, retorno;

    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());

    this->imprimir_interfaz_menu_Modo();
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = evento.mouse.x;
            y = evento.mouse.y;
            auxiliar = this->posicionado_menu_Modo();

            if (auxiliar >= 1 && auxiliar <= 3) {
                if (!sonido) {
                    sonido = true;
                    al_play_sample(apuntado, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
            }
            else {
                sonido = false;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (auxiliar >= 1 && auxiliar <= 3) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                if (auxiliar != 3) al_stop_sample(&id1);

                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();

                if (auxiliar != 3) al_rest(0.9);
                else al_rest(0.5);

                retorno = auxiliar;
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_menu_Modo();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            retorno = 4;
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_destroy_sample(avance);
    al_destroy_sample(apuntado);
    return retorno;
}

//Se genera el menú de récords.
int Juego::pantalla_Records() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int auxiliar = 3, retorno;

    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());

    this->imprimir_interfaz_Records();
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            x = evento.mouse.x;
            y = evento.mouse.y;
            auxiliar = this->posicionado_Records();

            if (auxiliar >= 1 && auxiliar <= 2) {
                if (!sonido) {
                    sonido = true;
                    al_play_sample(apuntado, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
            }
            else {
                sonido = false;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (auxiliar >= 1 && auxiliar <= 2) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
                retorno = auxiliar;
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_Records();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            retorno = 3;
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_destroy_sample(avance);
    al_destroy_sample(apuntado);
    return retorno;
}

//Se genera la pantalla para confirmar la eliminación del registro.
int Juego::pantalla_confirmacion() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(3);

    bool continuar = false, reanudar, sonido = false;
    int auxiliar = 3, retorno;

    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_mouse_event_source());

    this->imprimir_interfaz_confirmacion();
    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_MOUSE_AXES:
            this->x = evento.mouse.x;
            this->y = evento.mouse.y;
            auxiliar = this->posicionado_confirmacion();

            if (auxiliar >= 1 && auxiliar <= 2) {
                if (!sonido) {
                    sonido = true;
                    al_play_sample(apuntado, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
            }
            else {
                sonido = false;
            }
            break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (auxiliar >= 1 && auxiliar <= 2) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
                retorno = auxiliar;
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_confirmacion();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            retorno = 3;
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_destroy_sample(avance);
    al_destroy_sample(apuntado);
    return retorno;
}

//Se genera la pantalla de eliminación.
bool Juego::pantalla_eliminacion() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    this->eliminar_registro();
    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_eliminacion();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_eliminacion();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return false;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_stop_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    return true;
}

//Se genera el menú de finalización.
bool Juego::pantalla_finJuego(Jugador jugador_actual) {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance1 = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    this->actualizar_archivo(jugador_actual);
    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                al_play_sample(avance1, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_finJuego(jugador_actual);
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_finJuego(jugador_actual);
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return false;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance1);
    return true;
}

//Se genera la pantalla para el fin de la simulación.
bool Juego::pantalla_fin_simulacion(int parametro) {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.9);
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_fin_simulacion(parametro);
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_fin_simulacion(parametro);
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            return false;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_stop_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    return true;
}

//Se establece la dificultad del juego.
void Juego::pantalla_salida() {
    ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
    ALLEGRO_TIMER* temporizador = al_create_timer(1.0 / 60);
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    al_reserve_samples(5);

    bool continuar = false, reanudar;

    al_register_event_source(fila_evento, al_get_keyboard_event_source());
    al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
    al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
    al_start_timer(temporizador);

    while (!continuar) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_evento, &evento);

        switch (evento.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.5);
                continuar = true;
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            reanudar = false;
            while (!reanudar) {
                ALLEGRO_EVENT evento2;
                al_wait_for_event(fila_evento, &evento2);

                if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                    this->imprimir_interfaz_salida();
                    reanudar = true;
                }
            }
            break;
        case ALLEGRO_EVENT_TIMER:
            this->imprimir_interfaz_salida();
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            continuar = true;
            break;
        }
    }
    al_destroy_event_queue(fila_evento);
    al_start_timer(temporizador);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
}

//Se establece el tiempo del juego manual.
void Juego::setTiempo(int tiempo) {
    this->tiempo = tiempo;
    return;
}

//Se establece la dificultad del juego actual.
void Juego::setDificultad(int dificultad) {
    this->dificultad = dificultad;
    return;
}

//Se gestiona el modo manual del juego.
void Juego::modo_manual(Jugador &jugador_actual) {
	ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
	ALLEGRO_TIMER* temporizador = al_create_timer(1);
	ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* deslizar = al_load_sample("Sounds/smw_fireball.wav");
	ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    ALLEGRO_SAMPLE* musica_juego = al_load_sample("Sounds/Casino Kid (NES) Music   Casino Theme.mp3");
    ALLEGRO_SAMPLE_ID id1;
	al_reserve_samples(3);
    Puzzle* tablero_final, *tablero_inicial;

    if (this->dificultad == 3) {
        tablero_final = new Puzzle_facil(this->letra, this->pantalla, 3);
        tablero_inicial = new Puzzle_facil(this->letra, this->pantalla, 3);
    }
    else if (this->dificultad == 4) {
        tablero_final = new Puzzle_medio(this->letra, this->pantalla, this->dificultad);
        tablero_inicial = new Puzzle_medio(this->letra, this->pantalla, this->dificultad);
    }
    else {
        tablero_final = new Puzzle_dificil(this->letra, this->pantalla, this->dificultad);
        tablero_inicial = new Puzzle_dificil(this->letra, this->pantalla, this->dificultad);
    }

    int contador = 1;
    for (int i = 0; i < this->dificultad; i++) {
        for (int j = 0; j < this->dificultad; j++) {
            if (contador == this->dificultad * this->dificultad) {
                tablero_final[0][i][j] = "0";
            }
            else {
                tablero_final[0][i][j] = to_string(contador++);
            }
        }
    }

    do {
        tablero_inicial->generaPuzzle();
    } while (*tablero_inicial == *tablero_final || !tablero_inicial->resolvible_manual());

    vector<Par_coordenadas>* parametros = new vector<Par_coordenadas>;
    *parametros = this->fichas_a_mover(tablero_inicial);

	bool continuar = false, reanudar, sonido = false;
	int auxiliar = 2, veces_ayuda = 0;

    al_play_sample(musica_juego, 0.5, 0, 1, ALLEGRO_PLAYMODE_LOOP, &id1);

	al_register_event_source(fila_evento, al_get_display_event_source(this->pantalla));
	al_register_event_source(fila_evento, al_get_mouse_event_source());
	al_register_event_source(fila_evento, al_get_timer_event_source(temporizador));
	al_start_timer(temporizador);

	this->imprimir_interfaz_modo_manual(jugador_actual, tablero_inicial, tablero_final);
	while (!continuar && !(*tablero_inicial == *tablero_final)) {
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_evento, &evento);

		switch (evento.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
			x = evento.mouse.x;
			y = evento.mouse.y;
			auxiliar = this->posicionado_modo_manual(*parametros);

            if (auxiliar >= 1 && auxiliar <= 6) {
                if (!sonido) {
                    sonido = true;
                    al_play_sample(apuntado, 4.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                }
            }
            else {
                sonido = false;
            }
            break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (auxiliar >= 1 && auxiliar <= 4) {
                tablero_inicial->swap(auxiliar);
                this->imprimir_interfaz_modo_manual(jugador_actual, tablero_inicial, tablero_final);

                delete parametros;
                parametros = new vector<Par_coordenadas>;
                *parametros = this->fichas_a_mover(tablero_inicial);

                al_play_sample(deslizar, 2.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
            }
            else if (auxiliar == 5) {
                //tablero_inicial->sugerir_movimiento();
                //veces_ayuda++;
            }
            else if (auxiliar == 6) {
                al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

                al_rest(0.5);
                al_stop_sample(&id1);
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_flip_display();
                al_rest(0.9);
                continuar = true;
                jugador_actual.setPuntaje(-2);
                return;
            }
			break;
		case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
			reanudar = false;
			while (!reanudar) {
				ALLEGRO_EVENT evento2;
				al_wait_for_event(fila_evento, &evento2);

				if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
					this->imprimir_interfaz_modo_manual(jugador_actual, tablero_inicial, tablero_final);
					reanudar = true;
				}
			}
			break;
		case ALLEGRO_EVENT_TIMER:
            this->tiempo++;
			this->imprimir_interfaz_modo_manual(jugador_actual, tablero_inicial, tablero_final);
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			jugador_actual.setPuntaje(-1);
			return;
			break;
		}
        if (*tablero_inicial == *tablero_final) {
            al_stop_sample(&id1);
            ALLEGRO_SAMPLE* ganar = al_load_sample("Sounds/Super Mario Bros 2 (NES) Music   World Clear.mp3");
            al_play_sample(ganar, 0.6, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);

            al_rest(5.0);
            al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_flip_display();
            al_rest(0.9);

            al_destroy_sample(ganar);
        }
	}
	al_destroy_event_queue(fila_evento);
    al_destroy_timer(temporizador);
    al_destroy_sample(avance);
    al_destroy_sample(deslizar);
    al_destroy_sample(apuntado);
    al_destroy_sample(musica_juego);

	switch (dificultad) {
	case 3:
		if (this->tiempo < 300) {
			jugador_actual.setPuntaje(10000 - 5 * veces_ayuda);
		}
		else if (this->tiempo < 600) {
			jugador_actual.setPuntaje(5000 - 5 * veces_ayuda);
		}
		else if (this->tiempo < 900) {
			jugador_actual.setPuntaje(2500 - 5 * veces_ayuda);
		}
		else if (this->tiempo < 1200) {
			jugador_actual.setPuntaje(1250 - 5 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	case 4:
		if (this->tiempo < 420) {
			jugador_actual.setPuntaje(30000 - 3 * veces_ayuda);
		}
		else if (this->tiempo < 840) {
			jugador_actual.setPuntaje(15000 - 3 * veces_ayuda);
		}
		else if (this->tiempo < 1260) {
			jugador_actual.setPuntaje(7500 - 3 * veces_ayuda);
		}
		else if (this->tiempo < 1680) {
			jugador_actual.setPuntaje(3750 - 3 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	case 5:
		if (this->tiempo < 540) {
			jugador_actual.setPuntaje(60000 - 2 * veces_ayuda);
		}
		else if (this->tiempo < 1080) {
			jugador_actual.setPuntaje(40000 - 2 * veces_ayuda);
		}
		else if (this->tiempo < 1620) {
			jugador_actual.setPuntaje(30000 - 2 * veces_ayuda);
		}
		else if (this->tiempo < 2160) {
			jugador_actual.setPuntaje(10000 - 2 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	}
	if (jugador_actual.getPuntaje() < 0) jugador_actual.setPuntaje(0);
    delete tablero_inicial, tablero_final;
    al_destroy_sample(apuntado);
    al_destroy_sample(musica_juego);
    al_destroy_sample(avance);
    al_destroy_sample(deslizar);
}

//Se genera el menú para la solicitar los puzzles.
void Juego::capturar_puzzles(Puzzle*& inicio, Puzzle*& meta, ALLEGRO_SAMPLE_ID id) {
    ALLEGRO_SAMPLE* apuntado = al_load_sample("Sounds/smw_map_move_to_spot.wav");
    ALLEGRO_SAMPLE* deslizar = al_load_sample("Sounds/smw_fireball.wav");
    ALLEGRO_SAMPLE* avance = al_load_sample("Sounds/smw_message_block.wav");
    bool cancelar = false; Puzzle* manejador;
    vector<Coordenadas> *lista_espacios = new vector<Coordenadas>;

    if (this->dificultad == 3) {
        inicio = new Puzzle_facil(this->letra, this->pantalla, 3);
        meta = new Puzzle_facil(this->letra, this->pantalla, 3);
    }
    else if (this->dificultad == 4) {
        inicio = new Puzzle_medio(this->letra, this->pantalla, this->dificultad);
        meta = new Puzzle_medio(this->letra, this->pantalla, this->dificultad);
    }
    else {
        inicio = new Puzzle_dificil(this->letra, this->pantalla, this->dificultad);
        meta = new Puzzle_dificil(this->letra, this->pantalla, this->dificultad);
    }

    for (int i = 0; i < this->dificultad; i++) {
        for (int j = 0; j < this->dificultad; j++) {
            inicio[0][i][j] = "0";
        }
    }

    for (int i = 0; i < this->dificultad; i++) {
        for (int j = 0; j < this->dificultad; j++) {
            meta[0][i][j] = "0";
        }
    }
    int limite = pow(this->dificultad, 2) - 1, puzzle;
    int conteo = 1, auxiliar;

    while (conteo <= pow(this->dificultad, 2) * 2 - 2 && !cancelar) {
        int aux;

        if (conteo <= limite) {
            aux = conteo;
            puzzle = 1;
            *lista_espacios = this->lugares_disponibles(inicio, 1);
        }
        else {
            aux = conteo - limite;
            puzzle = 2;
            *lista_espacios = this->lugares_disponibles(meta, 2);
        }

        ALLEGRO_EVENT_QUEUE* fila_evento = al_create_event_queue();
        bool continuar = false, reanudar, sonido = false;

        al_register_event_source(fila_evento, al_get_display_event_source(pantalla));
        al_register_event_source(fila_evento, al_get_mouse_event_source());

        this->imprimir_interfaz_captura(aux, puzzle, inicio, meta);
        while (!continuar) {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_evento, &evento);

            switch (evento.type) {
            case ALLEGRO_EVENT_MOUSE_AXES:
                this->x = evento.mouse.x;
                this->y = evento.mouse.y;
                auxiliar = this->posicionado(*lista_espacios);
         
                if (auxiliar >= 1 && auxiliar <= 26) {
                    if (!sonido) {
                        sonido = true;
                        al_play_sample(apuntado, 4.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                    }
                }
                else {
                    sonido = false;
                }
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                if (auxiliar >= 1 && auxiliar <= 25) {
                    if (puzzle == 1) {
                        manejador = inicio;
                    }
                    else {
                        manejador = meta;
                    }

                    switch (auxiliar) {
                    case 1:  manejador[0][0][0] = to_string(aux); break;  case 14:  manejador[0][2][3] = to_string(aux); break;
                    case 2:  manejador[0][0][1] = to_string(aux); break;  case 15:  manejador[0][2][4] = to_string(aux); break;
                    case 3:  manejador[0][0][2] = to_string(aux); break;  case 16:  manejador[0][3][0] = to_string(aux); break;
                    case 4:  manejador[0][0][3] = to_string(aux); break;  case 17:  manejador[0][3][1] = to_string(aux); break;
                    case 5:  manejador[0][0][4] = to_string(aux); break;  case 18:  manejador[0][3][2] = to_string(aux); break;
                    case 6:  manejador[0][1][0] = to_string(aux); break;  case 19:  manejador[0][3][3] = to_string(aux); break;
                    case 7:  manejador[0][1][1] = to_string(aux); break;  case 20:  manejador[0][3][4] = to_string(aux); break;
                    case 8:  manejador[0][1][2] = to_string(aux); break;  case 21:  manejador[0][4][0] = to_string(aux); break;
                    case 9:  manejador[0][1][3] = to_string(aux); break;  case 22:  manejador[0][4][1] = to_string(aux); break;
                    case 10: manejador[0][1][4] = to_string(aux); break;  case 23:  manejador[0][4][2] = to_string(aux); break;
                    case 11: manejador[0][2][0] = to_string(aux); break;  case 24:  manejador[0][4][3] = to_string(aux); break;
                    case 12: manejador[0][2][1] = to_string(aux); break;  case 25:  manejador[0][4][4] = to_string(aux); break;
                    case 13: manejador[0][2][2] = to_string(aux); break;
                    }
                    conteo++;
                    this->imprimir_interfaz_captura(aux, puzzle, inicio, meta);

                    if (conteo <= pow(this->dificultad, 2) * 2 - 2) {
                        al_play_sample(deslizar, 2.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                    }
                    else {
                        al_play_sample(avance, 4.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                        al_rest(0.5);
                        if (*inicio == *meta) {
                            al_stop_sample(&id);
                            inicio[0][0][0] = "e";
                        }
                        else if (inicio->resolvible_manual() != meta->resolvible_manual()) {
                            inicio[0][0][0] = "f";
                            al_stop_sample(&id);
                        }
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_flip_display();
                        al_rest(0.5);
                        continuar = true;
                        delete lista_espacios;
                        return;
                    }

                    delete lista_espacios;
                    lista_espacios = new vector<Coordenadas>;
                    continuar = true;
                }
                else if (auxiliar == 26) {
                    al_play_sample(avance, 5.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
                    inicio[0][0][0] = "d";

                    al_rest(0.5);
                    al_stop_sample(&id);
                    al_clear_to_color(al_map_rgb(0, 0, 0));
                    al_flip_display();
                    al_rest(0.9);
                    continuar = true;
                    return;
                }
                break;
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
                reanudar = false;
                while (!reanudar) {
                    ALLEGRO_EVENT evento2;
                    al_wait_for_event(fila_evento, &evento2);

                    if (evento2.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
                        this->imprimir_interfaz_captura(aux, puzzle, inicio, meta);
                        reanudar = true;
                    }
                }
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                inicio[0][0][0] = "c";
                return;
            }
        }
        al_destroy_event_queue(fila_evento);
    }
    al_destroy_sample(apuntado);
    al_destroy_sample(avance);
    al_destroy_sample(deslizar);
    delete lista_espacios;

    al_rest(0.5);
    al_stop_sample(&id);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_rest(0.9);
    return;
}
#endif
