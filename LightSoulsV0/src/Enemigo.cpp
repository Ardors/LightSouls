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
}