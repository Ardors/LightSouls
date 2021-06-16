#include "Enemigo.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
using namespace std;


Enemigo::Enemigo(float x, float y, int vida, float peso, float maxVel, float distPersonaje, float distEnmigo, float distColiseo)
{
	pos.x = x;
	pos.y = y;
	this->vida = vida;
	this->peso = peso;
	this->maxVel = maxVel;
	this->distPersonaje = distPersonaje;
	this->distEnemigo = distEnmigo;
	this->distColiseo = distColiseo;
	maxAngVel = 0.5f;

	cuerpo = ETSIDI::SpriteSequence{ "imagenes/enemigo.png", 1 };
	piernas = ETSIDI::SpriteSequence{ "imagenes/enemigo2.png", 1, 8, 70};
	cuerpo.setCenter(1, 1.25);
	cuerpo.setSize(2, 2.5);
	piernas.setCenter(1.5, 1.1);
	piernas.setSize(3, 2.2);
}

void Enemigo::atacar(Personaje p)
{
	if ((pos - p.getPos()).modulo() < distPersonaje + 0.3) {
		float difAng = angulo - (180 / M_PI) * (p.getPos()-pos).argumento();
		if (difAng <= -180)
			difAng += 360;
		if (difAng > 180)
			difAng -= 360;
		if (difAng < 5 && difAng > -5) {
			if (ETSIDI::lanzaDado()<0.004)
				arma.atacar(false);
			else if (ETSIDI::lanzaDado() < 0.001)
				arma.atacar(true);
		}
	}
}
