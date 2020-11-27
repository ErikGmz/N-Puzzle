//-----Compilación de la cabecera-----//.
#ifndef Sistema_archivos_hpp
#define Sistema_archivos_hpp

//-----Funciones-----//.
//Se muestran los datos de cada jugador dentro del ranking.
void mostrar_registro(ALLEGRO_FONT* letra) {
	fstream archivo("registro.dat", ios::binary | ios::in);
	ALLEGRO_FONT* menor = al_load_font("Fonts/slkscre.ttf", 23, NULL);
	int contador = 0;

	if (archivo) {
		Datos_Guardar* aux = new Datos_Guardar;

		archivo.read(reinterpret_cast <char*>(aux), sizeof(Datos_Guardar));
		while (!archivo.eof()) {
			if (contador < 7) {
				al_draw_text(menor, al_map_rgb(230, 197, 252), 263, 146 + contador * 45, ALLEGRO_ALIGN_CENTRE, aux->nombre);
				al_draw_text(letra, al_map_rgb(202, 255, 175), 460, 144 + contador * 45, ALLEGRO_ALIGN_CENTRE, to_string(aux->puntaje).c_str());
				al_draw_text(menor, al_map_rgb(255, 197, 168), 657, 148 + contador * 45, ALLEGRO_ALIGN_CENTRE, aux->fecha);
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
			al_draw_text(letra, al_map_rgb(230, 197, 252), 263, 146 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
			al_draw_text(letra, al_map_rgb(202, 255, 175), 460, 144 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
			al_draw_text(letra, al_map_rgb(255, 197, 168), 657, 148 + i * 45, ALLEGRO_ALIGN_CENTRE, "-----");
		}
	}

	archivo.close();
	al_destroy_font(menor);
}
#endif