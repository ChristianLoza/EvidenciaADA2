#pragma once
#include <iostream>

#include "Tabla.h"
#include "Movimiento.h"
using namespace std;

enum{
	VACIO,
	X,
	O
};

class Juego
{
private:
	int posicion;
	int jugada;
	int maxjugada;
public:
	Juego(void);
	~Juego(void);
	void loadGame();
	void Tablero(Tabla &tabla, int size);
	void showTabla(Tabla &tabla);
};

