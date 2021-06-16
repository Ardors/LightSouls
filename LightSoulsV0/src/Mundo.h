#pragma once

#include "Vector.h"
#include "Segmento.h"
#include "Personaje.h"
#include "ListaEnemigos.h"
#include "ListaProyectiles.h"
#include "Coliseo.h"
#include <stdio.h>
#include <iostream>

//ancho y alto de la ventana
#define ANCHO 1500
#define ALTO 1050
#define RELACION 50

class Mundo
{
	friend class Maquina_Estados;
public: 
	
	~Mundo();
	void tecla(unsigned char key);
	void teclaSuelta(unsigned char key);
	void mouse(int x, int y);
	void inicializa();
	void mueve();
	void dibuja();

protected:
	Vector camara;
	Vector raton;
	bool w, a, s, d;

	Personaje c;
	ListaEnemigos enemigos;
	Coliseo coliseo;
	ListaProyectiles proyectiles;
};
