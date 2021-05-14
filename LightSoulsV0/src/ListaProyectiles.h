#pragma once
#include"Proyectil.h"
#define MAX_PROYECTILES 100
class ListaProyectiles
{
private:
	Proyectil* lista[MAX_PROYECTILES];
	int numero;
public:
	ListaProyectiles();
	bool agregar(Proyectil* p);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
};

