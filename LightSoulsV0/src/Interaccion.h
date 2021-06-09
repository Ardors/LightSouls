#pragma once
#include "Segmento.h"
#include "Circulo.h"
#include "Vector.h"
#include "Luchador.h"


//clase encargada de las interacciones entre los elementos del juego
class Interaccion
{
public:
	static bool colision(Segmento s, Circulo c);	
	static bool colision(Circulo c1, Circulo c2);
	static bool rebote(Luchador& p1, Luchador& p2);
};

