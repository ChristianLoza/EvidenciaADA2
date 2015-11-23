#include "stdafx.h"
#include "Juego.h"

  Juego::Juego(){
    Tabla tabla;
    int finJuego=0;
    int lado=X;
    LoadTabla(tabla,3);
    showTabla(tabla);
    while(!finJuego){
        if(lado==X){
        	if(movCPU(tabla,lado)){
        		lado^=1;
                tabla.NumMovimientos--;
            }
        }else{
            if(movPersona(tabla,lado)){
            	lado^=1;
                tabla.NumMovimientos--;
            }
        }
        showTabla(tabla);
        int var=TfinJuego(tabla);
        if(var !=-2){
            VfinJuego(var);
            break;
        }
    }
}
int Juego::movPersona(Tabla &tabla,int lado){
    int fila;
    int columna;
    cout<<"\n\nINGRESE UNA POSICIÓN\n";
    cout<<"FILAS ENTRE (1-3): ";
    cin>>fila;
    cout<<"COLUMNAS ENTRE (1-3): ";
    cin>>columna;
    if(fila<1 || fila>3 || fila<1 || fila>3 ){
        cout<<"\nESTA JUGADA ESTA FUERA\n";
        cout<<"\nINGRESE UN NUMERO ENTRE EL 1-3 EN EL TRES EN RAYA\n";
        return 0;
	}
    if(tabla.tabla[fila-1][columna-1] != VACIO){
        cout<<"\nMOVIMIENTO NO VALIDO\n";
        cout<<"\nMOVIMIENTO NO DISPONIBLE\n";
        return 0;
    }
    tabla.tabla[fila-1][columna-1]=lado;
    return 1;

}
int Juego::movCPU(Tabla &tabla,int lado){
    this->jugada=0;
    this->maxJugada=9;
    this->posiciones=0;
     int aX = -100;
     int bX = +100;
     aNegaScout(tabla,lado,9,9,aX,bX);
     cout<<"posiciones :"<<posiciones<<"\n";
     return 1;
}
int Juego::aNegaScout(Tabla &tabla,int lado,int profActual,int profMax,int aX,int bX){
    vector<Movimiento> Movimientos;
    Movimiento mJugada;
    mJugada.columna = -1;
    mJugada.fila = -1;
    Movimiento movTemp;
    int bPunts=-2;
    int n;
    int punts=evaluar(tabla,lado);
    if(profActual==0 || punts !=0)
            return punts;
    posiciones++;
    n=bX;
    //generate move list
    for(int row=0;row<tabla.Size;row++){
        for(int col=0;col<tabla.Size;col++){
            if(tabla.tabla[row][col]==VACIO){
                movTemp.fila=row;
                movTemp.columna=col;
                Movimientos.push_back(movTemp);
            }
        }
    }

    for(unsigned int i=0;i<Movimientos.size();i++){
    	tabla.tabla[Movimientos[i].fila][Movimientos[i].columna]=lado;
        punts=-aNegaScout(tabla,lado^1,profActual-1,profMax,-n,-aX);
        if(punts>bPunts){
            if(n==bX || profActual<=2)
                bPunts=punts;
            else
                bPunts=-aNegaScout(tabla,lado^1,profActual-1,profMax,-bX,-punts);
            mJugada=Movimientos[i];
        }
        if(punts>aX)
           aX = bPunts;

        tabla.tabla[Movimientos[i].fila][Movimientos[i].columna]=VACIO;
        if(aX>=bX)
            return aX;
        n=aX+1;
    }
    if(Movimientos.size()==0)
        bPunts=ScanVictoria(tabla,lado);
    if(profActual !=profMax)
        return bPunts;
    else{

        cout<<"\n"<<mJugada.fila<<" "<<mJugada.columna<<"\n";
        tabla.tabla[mJugada.fila][mJugada.columna]=lado;
        return 1;
    }
    return 0;
}
int Juego::evaluar(Tabla &tabla){
    if(ScanVictoria(tabla,X))
        return -1;
    else if(ScanVictoria(tabla,O))
        return 1;
    else
        return 0;
}
int Juego::evaluar(Tabla &tabla,int lado){
    if(ScanVictoria(tabla,lado))
        return 1;
    if(ScanVictoria(tabla,lado^1))
        return -1;
    return 0;
}
void Juego::LoadTabla(Tabla &tabla,int Size){
    tabla.Size=Size;
    tabla.NumMovimientos=tabla.Size*tabla.Size;
    for(int row=0;row<tabla.Size;row++){
        for(int col=0;col<tabla.Size;col++)
            tabla.tabla[row][col]=VACIO;
    }
}
void Juego::showTabla(Tabla &tabla){
      cout<<"\n~~~~ TRES EN RAYA ~~~~\n\n";
    for(int row=0;row<tabla.Size;row++){
        for(int col=0;col<tabla.Size;col++){
            if(tabla.tabla[row][col]==X)
                cout<<"x ";
            if(tabla.tabla[row][col]==O)
                cout<<"o ";
            if(tabla.tabla[row][col]==VACIO)
                cout<<"_ ";
        }
        cout<<"\n";
    }
}
int Juego::ScanVictoria(Tabla &tabla,int lado){
    int aux;
    /*
     *  AQUI COMPRUEBA LAS FILAS
     */
    for(int row=0;row<tabla.Size;row++){
        aux=0;
        for(int col=0;col<tabla.Size;col++){
            if(tabla.tabla[row][col]==lado)
                aux++;
        }
        if(aux==tabla.Size)
            return 1;
    }

    /*
     *  AQUI COMPRUEBA COLUMNAS
     */

    for(int col=0;col<tabla.Size;col++){
        aux=0;
        for(int row=0;row<tabla.Size;row++){
            if(tabla.tabla[row][col]==lado)
                aux++;
        }
        if(aux==tabla.Size)
            return 1;
    }

    /*
     *  COMPROBACION EN DIAGONAL
     *
     */
    //IZQUIERDA
    aux=0;
    for(int i=0;i<tabla.Size;i++){
        if(tabla.tabla[i][i]==lado){
            aux++;
        }
    }
    if(aux==tabla.Size){
        return 1;
    }
    //DERECHA
    aux=0;
    for(int i=0;i<tabla.Size;i++){
        if(tabla.tabla[i][(tabla.Size-1)-i]==lado)
            aux++;
    }
    if(aux==tabla.Size)
        return 1;
    return 0;
}
void Juego::VfinJuego(int var){
  switch(var){
    case 1:
     cout<<"\n\n------ GANA JUGADOR ------\n";
     break;
    case -1:
     cout<<"\n\n------ GANA CPU------\n";
     break;
    case 0:
     cout<<"\n\n ------ JUEGO EMPATADO ------\n";
     break;
  }
}
int Juego::TfinJuego(Tabla &tabla){
	if(ScanVictoria(tabla,X))
        return -1;
    if(ScanVictoria(tabla,O))
        return 1;
    if(tabla.NumMovimientos==0)
        return 0;
    return -2;
}

