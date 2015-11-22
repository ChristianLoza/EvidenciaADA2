#include "stdafx.h"
#include "Juego.h"


Juego::Juego(void)
{
}


Juego::~Juego(void)
{
}
void Juego::loadGame(){
	Tabla tabla;
	bool finGame=0;
	Tablero(tabla,3);
	showTabla(tabla);
}
void Juego::Tablero(Tabla &tabla, int size){
	tabla.Size=size;
	tabla.NumMovimientos=tabla.Size*tabla.Size;
	for(int fil=0;fil<tabla.Size;fil++){
		for(int col=0;col<tabla.Size;col++)
			tabla.tabla[fil][col]=VACIO;
	}
}
void Juego::showTabla(Tabla &tabla){
	cout<<"\n TABLA \n"<<endl;
	for(int fil=0;fil<tabla.Size;fil++)
	{
		for(int col=0;col<tabla.Size;fil++)
		{
			if(tabla.tabla[fil][col]==X)
				cout<<" X ";
			if(tabla.tabla[fil][col]==O)
				cout<<" O ";
			if(tabla.tabla[fil][col]==VACIO)
				cout<<" _ ";
		}
		cout<<"\n";
	}
}
int Juego::AlgoNegaScout(Tabla &tabla,int lado,int profActual,int profMax,int aX,int bX){
	vector<Movimiento> movimientos;
	movimientos MejorMov = {-1,-1};
	return 0;
}
