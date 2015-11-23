#pragma once
#include <assert.h>
#include <math.h>


const double valCero= 1e-10;
class punto
{
private:
	double pData[2];
	bool iCero(const double);
	bool iIgual(const double, const double);
	bool iNoIgual(const double, const double);

	bool iPuntoCero(const punto &);
	bool iPuntosIguales(const punto &, const punto &);
	bool iPuntosNoIguales(const punto &, const punto &);

	double distanciaPuntos(const punto &, const punto &);
public:
	punto(double x=0.0, double y=0.0);
	~punto(void);
	double *Puntos(void){
		return pData;
	};
	const double *Puntos(void) const{
		return pData;
	};
	double &operator[](unsigned int i){
		assert(i < 2 && i >= 0);
		return pData[i];
	};
	const double operator[](unsigned int i) const {
		assert(i < 2 && i >= 0);
		return pData[i];
	};
};

