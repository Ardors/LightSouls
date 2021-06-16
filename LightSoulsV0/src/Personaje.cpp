#include "Personaje.h"
#include <iostream>
using namespace std;

Personaje::Personaje()
{
	cuerpo = ETSIDI::SpriteSequence{ "imagenes/personaje.png", 1 };
	piernas = ETSIDI::SpriteSequence{ "imagenes/personaje2.png", 1, 8, 70 };
	cuerpo.setCenter(0.9, 1.25);
	cuerpo.setSize(1.8, 2.5);
	piernas.setCenter(1.5, 1.25);
	piernas.setSize(3, 2.5);
	maxAngVel = 15;
	vida = 100;
	cargar("armas/espada.txt");
}

/*bool Personaje::muerto()
{
	if (vida <= 0) {
		//cout << "has muerto";
		return true;
	}
	else
		return false;
}*/
