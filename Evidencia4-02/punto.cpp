#include "stdafx.h"
#include "punto.h"


punto::punto(double x, double y)
{
	this->pData[0]=x;
	this->pData[0]=y;
}
punto::~punto(void)
{
}

// Evalua si es cero
bool punto::iCero(const double x){
	return (fabs(x) < valCero);
}

// Evalua si las entradas sin iguales
bool punto::iIgual(const double x, const double y){
	if(iCero(x-y))
		return true;
	else{
		double denomin = (x>y?x:y);
		double er = (x-y)/denomin;
		return iCero(er);
	}
}
bool punto::iNoIgual(const double x, const double y){
	return (!iIgual(x,y));
}
bool punto::iPuntoCero(const punto &p){
	if(iCero(p.Puntos()[0]) && iCero(p.Puntos()[1]))
		return true;
	else
		return false;
}
bool punto::iPuntosIguales(const punto &p, const punto &q){
	double DistanciaX = p.Puntos()[0] - q.Puntos()[0];
	double DistanciaY = p.Puntos()[1] - q.Puntos()[1];
	if(iCero(DistanciaX)&& iCero(DistanciaY))
		return true;
	else
		return false;
}
bool punto::iPuntosNoIguales(const punto &p, const punto &q)
{
	return (!iPuntosIguales(p,q));
}
double punto::distanciaPuntos(const punto &p, const punto &q){
	double x=0;
	double y=0;
	double distancia=0;
	x= p.Puntos()[0]-q.Puntos()[0];
	y= p.Puntos()[0]-q.Puntos()[0];
	distancia = sqrt(pow(x,2)+pow(y,2));
	return distancia;
}