#pragma once
#include "Enemigo.h"
#include "Coliseo.h"
#define MAX_ENEMIGOS 20

class ListaEnemigos
{
public:
	ListaEnemigos();
	//virtual ~ListaEnemigos();
	bool agregar(Enemigo* e);
	void dibuja();
	void mueve(float t, Personaje p, Coliseo c);
	void rebote();
	void rebote(Personaje p);
	void atacar(Personaje p);
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Enemigo* e);
	Enemigo* operator [](int i);
	int getNumero() { return numero; }
	void colision_coliseo(Coliseo c);
	//void checkVida();          //recorre la lista verificando si han matado a algun enemigo y lo elimina
	bool generar_oleadas();

private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;
	int numero_oleadas = 0;
};

