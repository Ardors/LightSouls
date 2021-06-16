#pragma once
#include"Proyectil.h"
#define MAX_PROYECTILES 2
class ListaProyectiles
{
private:
	Proyectil* lista[MAX_PROYECTILES];
	int numero;							//Número de proyectiles que tiene la lista en un momento determinado 
public:
	ListaProyectiles();
	int getNumero() { return numero; }
	bool agregar(Proyectil* p);
	void eliminar(int index);
	void eliminar(Proyectil* p);
	void eliminar_t();                  //elimina disparos por tiempo excedido
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	Proyectil* operator[](int i);
};

