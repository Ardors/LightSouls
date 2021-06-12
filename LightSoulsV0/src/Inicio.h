#pragma once
#include "Vector.h"
#include "Personaje.h"
#include "Coliseo.h"
#include "Interaccion.h"
#include "freeglut.h"

#define ANCHO 1500
#define ALTO 1050
#define REACCION 50

class Inicio
{
public:
	void tecla(unsigned char key);
	void teclaSuelta(unsigned char key);
	void mouse(int x, int y);
	void inicializa();
	void mueve();
	void dibuja();

protected:
	Coliseo foro;
	Personaje c;
	Vector raton;
	Vector camara;
	bool w, a, s, d;
};

