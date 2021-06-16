#pragma once
#include "Luchador.h"


class Personaje: public Luchador
{
	friend class Interaccion;
	
public:
	Personaje();
	void setVida(int a) { vida = a; }
	//bool muerto();
};

