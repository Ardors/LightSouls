#pragma once
#include "Segmento.h"
#include "Circulo.h"


//clase encargada de las interacciones entre los elementos del juego
class Interaccion
{
public:
	static bool colision(Segmento s, Circulo c);	
	static bool colision(Circulo c1, Circulo c2);
};

