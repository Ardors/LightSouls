#pragma once
#include "Segmento.h"
#include "Circulo.h"


//clase encargada de las interacciones entre los elementos del juego
class Interaccion
{
public:
	static bool colision(Segmento s, Circulo c);	
	static bool colision(Circulo c1, Circulo c2);
<<<<<<< Updated upstream
=======
	static bool rebote(Luchador& p1, Luchador& p2);
	static bool colision_coliseo(Luchador& p, Coliseo c);
	static bool colision_mercader(Luchador& p, Circulo m);
	static bool tienda(Circulo c1, Circulo c2);
>>>>>>> Stashed changes
};

