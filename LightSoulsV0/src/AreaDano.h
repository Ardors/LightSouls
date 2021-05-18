#pragma once
#include "Circulo.h"

class AreaDano : public Circulo
{

private:
	float dano;
	friend class Interaccion;

public:
	
	AreaDano();
	virtual ~AreaDano();
	
	void setDano(float d) { dano = d; }
	float getDano() { return dano;}
};

