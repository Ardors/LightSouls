#pragma once
#include "Circulo.h"
#include "ETSIDI.h"

class Coliseo : public Circulo
{
private:
	ETSIDI::SpriteSequence sprite{ "imagenes/muro.png", 1 };
	ETSIDI::SpriteSequence suelo{ "imagenes/suelo.png", 1 };

public:
	Coliseo();
	void dibuja();
	void setRadio(float radio);
};