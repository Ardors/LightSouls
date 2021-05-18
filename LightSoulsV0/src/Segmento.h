#pragma once
#include "Vector.h"
#include <freeglut.h>
class Segmento
{
	friend class Interaccion;
	
protected:
	Vector p1, p2;
	
public:
	Segmento() {};
	//constructor (1) con vectores
	Segmento(Vector p1, Vector p2): p1(p1), p2(p2){}
	//constructor (2) con puntos
	Segmento(float p1_x, float p1_y, float p2_x, float p2_y);

	float DistanciaPunto(Vector punto, Vector* direccion = nullptr);
	void dibuja();

};

