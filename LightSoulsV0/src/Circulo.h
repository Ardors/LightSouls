#pragma once
#include "freeglut.h"
#include "Vector.h"
class Circulo
{
private:
	Vector pos;
	Vector vel; 
	float angulo = 0; //orientación independiente de la velocidad
	float radio;
	friend class Interaccion;
public: 	

	Circulo() {radio = 1; }
	Vector getPos() { return pos; }
	float getRadio() { return radio; }
	void setPos(float x, float y);
	void setVel(float vx, float vy);
	void setAng(float ang) { angulo = ang; }

	void dibuja();
	void mueve(float t);
};

