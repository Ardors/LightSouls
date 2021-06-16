#pragma once
#include "Circulo.h"
#include "Arma.h"
#include "Etsidi.h"
using ETSIDI::SpriteSequence;

class Luchador : public Circulo
{
	friend class Interaccion;
protected:

	SpriteSequence cuerpo{ "imagenes/personaje.png", 1 };
	SpriteSequence piernas{ "imagenes/personaje2.png", 1, 8, 70 };
	
	int vida;
	float peso = 100, maxVel;
	float maxAngVel;
	Arma arma;

public:
	Luchador() :arma(&pos, &angulo) { 
		maxVel = 2;
	}
	void dibuja();
	void mueve(float t, Vector obj);
	void atacar(bool secundario) { arma.atacar(secundario);}
	void cargar(const char* fichero) { arma.cargar(fichero); }
	float getVida() { return vida; }
	float setVida(float vida) { this->vida = vida; }
};

