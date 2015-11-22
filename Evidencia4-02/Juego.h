#pragma once
#include <iostream>

#include "Tabla.h"
#include "Movimiento.h"
#include <vector>
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
	void Tablero(Tabla &,int);
	void showTabla(Tabla &);
	int AlgoNegaScout(Tabla &,int,int,int,int,int);
};

