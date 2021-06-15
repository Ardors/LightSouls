#pragma once
#include "Vector.h"
#include "Animacion.h"
#include "Segmento.h"

class Arma: public Segmento
{
<<<<<<< Updated upstream
	int daño = 0;
	float ang1 = -1.57, ang2 = 1.57, dis1 = 1;
	float ang1o = -1.57, ang2o = 1.57, dis1o = 1, dis2 = 3;
=======
	friend class Luchador;
	friend class Enemigo;
	friend class Personaje;
protected:
	SpriteSequence sprite{"imagenes/espada.png",1};
	int daño1 = 0;
	int daño2 = 0;
	bool activa = 0;
	float ang1o = 0, ang2o = 0, dis1o = 0, dis2= 0;
	float ang1 = 0, ang2 = 0, dis1 = 0;
	float dist = 0;
>>>>>>> Stashed changes
	Vector* origen;
	float* angulo;
	int atacando = 0; //0 no, 1 primario, 2 secundario
	Animacion ani1;
	Animacion ani2;

public:
	Arma(Vector* origen, float* angulo) :origen(origen), angulo(angulo) {};
	void cargar(const char* archivo);
	void dibuja();
	void atacar(bool secundario);
	void mueve();
};

