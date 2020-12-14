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
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(100, 50, 700, 170, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(140, 230, 240, 330, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(320, 250, 380, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(460, 250, 520, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(600, 250, 660, 310, al_map_rgb(255, 255, 255));

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
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(200, 60, 600, 120, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(250, 180, 550, 240, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(320, 300, 481, 360, al_map_rgb(255, 255, 255));

    al_draw_filled_rectangle(50, 210, 150, 310, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(650, 210, 750, 310, al_map_rgb(255, 255, 255));

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
    al_flip_display();
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_menu_Dificultad() {
    if (this->x >= 300 && this->x <= 500 && this->y >= 150 && this->y <= 210) return 1;
    else if (this->x >= 290 && this->x <= 510 && this->y >= 280 && this->y <= 340) return 2;
    else if (this->x >= 280 && this->x <= 520 && this->y >= 410 && this->y <= 470) return 3;
    else if (this->x >= 64 && this->x <= 122 && this->y >= 409 && this->y <= 471) return 4;
    else return 5;
}

//Se imprime la interfaz del selector de dificultad.
void Juego::imprimir_interfaz_menu_Dificultad() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(this->letra, al_map_rgb(189, 252, 166), 400, 50, ALLEGRO_ALIGN_CENTRE, "SELECCIONE LA DIFICULTAD");

    al_draw_filled_rectangle(300, 150, 500, 210, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(290, 280, 510, 340, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(280, 410, 520, 470, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(65, 410, 121, 470, al_map_rgb(255, 255, 255));

    al_flip_display();
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_menu_Modo() {
    if (this->x >= 290 && this->x <= 510 && this->y >= 200 && this->y <= 260) return 1;
    else if (this->x >= 270 && this->x <= 530 && this->y >= 360 && this->y <= 420) return 2;
    else if (this->x >= 65 && this->x <= 121 && this->y >= 360 && this->y <= 420) return 3;
    else return 4;
}

//Se imprime la interfaz del selector de modo.
void Juego::imprimir_interfaz_menu_Modo() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(this->letra, al_map_rgb(216, 227, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "SELECCIONE EL MODO");

    al_draw_filled_rectangle(290, 200, 510, 260, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(270, 360, 530, 420, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(65, 360, 121, 420, al_map_rgb(255, 255, 255));

    al_flip_display();
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_Records() {
    if (this->x >= 65 && this->x <= 121 && this->y >= 468 && this->y <= 525) return 1;
    else if (this->x >= 360 && this->x <= 710 && this->y >= 468 && this->y <= 525) return 2;
    else return 3;
}

//Se imprime la interfaz del menú de récords.
void Juego::imprimir_interfaz_Records() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

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

    al_draw_filled_rectangle(65, 458, 121, 515, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(360, 458, 710, 515, al_map_rgb(255, 255, 255));
    al_flip_display();

    al_destroy_font(titulo); al_destroy_font(letra);
}

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_confirmacion() {
    if (this->x >= 270 && this->x <= 530 && this->y >= 200 && this->y <= 260) return 1;
    else if (this->x >= 270 && this->x <= 530 && this->y >= 360 && this->y <= 420) return 2;
    else return 3;
}

//Se imprime la interfaz de la pantalla para confirmar la eliminación del registro.
void Juego::imprimir_interfaz_confirmacion() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_draw_text(this->letra, al_map_rgb(247, 188, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "CONFIRME LA ELIMINACION");
    al_draw_text(this->letra, al_map_rgb(247, 188, 255), 400, 100, ALLEGRO_ALIGN_CENTRE, "DEL REGISTRO");
    al_draw_filled_rectangle(270, 200, 530, 260, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(270, 360, 530, 420, al_map_rgb(255, 255, 255));

    al_flip_display();
}

//Se imprime la intefaz de eliminación.
void Juego::imprimir_interfaz_eliminacion() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(190, 231, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "REGISTRO BORRADO");

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

//Se imprime la interfaz de la pantalla de salida.
void Juego::imprimir_interfaz_salida() {
    this->contador++;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(this->letra, al_map_rgb(164, 255, 255), 400, 50, ALLEGRO_ALIGN_CENTRE, "GRACIAS POR JUGAR :)");

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

//Se determina en cuál ícono se ha posicionado el cursor.
int Juego::posicionado_modo_manual(vector<Par_coordenadas> parametros) {
    for (auto it : parametros) {
        if (this->x >= it.x_inicial && this->x <= it.x_final && this->y >= it.y_inicial && this->y <= it.y_final) {
            return it.posicion;
        }
    }
    if (this->x >= 470 && this->x <= 750 && this->y >= 440 && this->y <= 500) return 6;
    else return 5;
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
    al_draw_filled_rectangle(470, 460, 750, 520, al_map_rgb(255, 255, 255));

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
    delete fichas;
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
                case 3:
                    x_inicial = 108; y_inicial = 200; x_final = 155; y_final = 247; break;
                case 4:
                    x_inicial = 73; y_inicial = 180; x_final = 120; y_final = 227; break;
                case 5:
                    x_inicial = 88; y_inicial = 160; x_final = 135; y_final = 207; break;
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
                al_stop_sample(&id1);
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
    
    Puzzle* tablero_inicial = new Puzzle(this->letra, this->pantalla, this->dificultad);
    tablero_inicial->generaPuzzle();
    Puzzle* tablero_final = new Puzzle(this->letra, this->pantalla, this->dificultad);
    vector<Par_coordenadas>* parametros = new vector<Par_coordenadas>;
    *parametros = this->fichas_a_mover(tablero_inicial);

    do {
        tablero_final->generaPuzzle();
    } while (*tablero_inicial == *tablero_final);

	bool continuar = false, reanudar, sonido = false;
	int auxiliar = 2, veces_ayuda = 0;

    //al_rest(5.0);
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

            if (auxiliar >= 1 && auxiliar <= 4 || auxiliar == 6) {
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
		if (this->tiempo < 60) {
			jugador_actual.setPuntaje(10000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 120) {
			jugador_actual.setPuntaje(5000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 180) {
			jugador_actual.setPuntaje(2500 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 240) {
			jugador_actual.setPuntaje(1250 - 50 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	case 4:
		if (this->tiempo < 60) {
			jugador_actual.setPuntaje(30000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 120) {
			jugador_actual.setPuntaje(15000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 180) {
			jugador_actual.setPuntaje(7500 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 240) {
			jugador_actual.setPuntaje(3750 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 300) {
			jugador_actual.setPuntaje(1875 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 360) {
			jugador_actual.setPuntaje(937 - 50 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	case 5:
		if (this->tiempo < 60) {
			jugador_actual.setPuntaje(60000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 120) {
			jugador_actual.setPuntaje(40000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 180) {
			jugador_actual.setPuntaje(30000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 240) {
			jugador_actual.setPuntaje(10000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 300) {
			jugador_actual.setPuntaje(8000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 360) {
			jugador_actual.setPuntaje(4000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 420) {
			jugador_actual.setPuntaje(2000 - 50 * veces_ayuda);
		}
		else if (this->tiempo < 480) {
			jugador_actual.setPuntaje(1000 - 50 * veces_ayuda);
		}
		else {
			jugador_actual.setPuntaje(0);
		}
		break;
	}
	if (jugador_actual.getPuntaje() < 0) jugador_actual.setPuntaje(0);
    delete tablero_inicial, tablero_final;
}
#endif
