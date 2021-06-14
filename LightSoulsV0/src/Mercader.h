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

	Mercader() {cuerpo.setCenter(0.9, 2); cuerpo.setSize(1.8, 2.5);}
	void dibuja();

protected:

	//cargamos los ficheros con los sprites de los mercaderes
	//place holder de luchador, sustituir por mercaderes
	SpriteSequence cuerpo{ "imagenes/personaje.png", 1 };
	

};

