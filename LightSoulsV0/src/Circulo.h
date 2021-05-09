#pragma once
#include "freeglut.h"
#include "Vector.h"
class Circulo
{
private:
	Vector pos;
	Vector vel; 
	float angulo = 0; //orientación independiente de la velocidad

public: 	
	float radio;
	Circulo() {radio = 1; }
	Vector getPos() { return pos; }
	void setPos(float x, float y);
	void setVel(float vx, float vy);
	void setAng(float ang) { angulo = ang; }

	void dibuja();
	void mueve(float t);
};

