#pragma once
#include "freeglut.h"
#include "Vector.h"
class Circulo
{
	friend class Interaccion;

protected:
	Vector pos;
	Vector vel; 
	float angulo = 0; //orientación independiente de la velocidad
	float radio;
	

public: 	
	Circulo() {radio = 1; }
	Vector getPos() { return pos; }
	float getRadio() { return radio; }
	void setPos(float x, float y);
	void setRadio(float r) { radio = r; }
	void setVel(float vx, float vy);
	void setAng(float ang) { angulo = ang; }
	float getAng() { return angulo; }
	void dibuja();
	void mueve(float t);
};

