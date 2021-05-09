#pragma once
#include "freeglut.h"
#include "Vector.h"
class Circulo
{

public: 
	Vector pos;
	float radio;
	Circulo() { radio = 1; }
	void dibuja();
};

