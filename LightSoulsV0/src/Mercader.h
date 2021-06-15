#pragma once
#include "Circulo.h"
#include "Arma.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Mercader : public Circulo
{
	friend class Interaccion;
	float radio_acc = 1.0;
public:

	void dibuja();
	void setSprite(const char* nombreSprite);
	void setSize(float size_x, float size_y);
protected:
	char nombreSprite[30];
	//cargamos los ficheros con los sprites de los mercaderes
	//place holder de luchador, sustituir por mercaderes
	SpriteSequence cuerpo{ "imagenes/personaje.png", 1 };

};

