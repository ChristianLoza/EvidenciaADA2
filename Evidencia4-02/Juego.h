#ifndef Juego_H
#define Juego_H

#include<iostream>
#include<vector>

/*
 * Juego.h
 *
 *  Created on: 20/11/2015
 *  Author: Christianlp
 */
#include "stdafx.h"
#include "Tabla.h"
#include "Movimiento.h"

enum {X,O,VACIO};

using namespace std;

class Juego{
        int posiciones;
        int jugada;
        int maxJugada;
    public:
        Juego();
        void InitGame();
        void LoadTabla(Tabla &,int);
        void showTabla(Tabla &);
        int movPersona(Tabla &,int);
        int movCPU(Tabla &,int);
        int TfinJuego(Tabla &);
        void VfinJuego(int);
        int ScanVictoria(Tabla &,int);
        int aNegaScout(Tabla &,int,int, int ,int ,int );
        int evaluar(Tabla &);
        int evaluar(Tabla &,int );
};

#endif // JUEGO_H
