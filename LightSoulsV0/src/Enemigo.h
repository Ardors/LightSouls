#pragma once
#include "Luchador.h"
#include "Personaje.h"

class Enemigo: public Luchador
{
	friend class ListaEnemigos;
private:
	float distPersonaje, distEnemigo, distColiseo;
public:
	Enemigo(float x, float y, int vida, float peso, float maxVel, float distPersonaje, float distEnemigo, float distColiseo);
};

