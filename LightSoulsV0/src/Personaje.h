#pragma once
#include "Circulo.h"
#include "Arma.h"

class Personaje : public Circulo
{
	int vida, peso;
	float maxVel;
	Arma arma;

public:
	Personaje():arma(&pos, &angulo){}
	void dibuja();
	void mueve(float t);
	void atacar(bool secundario) { arma.atacar(secundario);}
	void cargar(const char* fichero) { arma.cargar(fichero); }
};

