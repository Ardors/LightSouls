#include "ListaEnemigos.h"
#include "Interaccion.h"


ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = 0;
}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaEnemigos::mueve(float t, Personaje p, Coliseo c)
{
	for (int i = 0; i < numero; i++) {
		//deriva coliseo
		Vector distColiseo = lista[i]->pos - c.getPos();
		Vector velColiseo;
		if(distColiseo.modulo() > c.getRadio()- lista[i]->distColiseo)
			velColiseo = distColiseo.unitario() * -(c.getRadio() - lista[i]->distColiseo);

		//deriva enemigos
		Vector velEnemigos;
		for (int j = 0; j < numero; j++) {
			Vector distEnemigo = lista[i]->pos - lista[j]->pos;
			if (distEnemigo.modulo() < lista[i]->distEnemigo)
				velEnemigos = velEnemigos + distEnemigo.unitario() * -(distEnemigo.modulo() - lista[i]->distEnemigo);
		}
		
		//deriva personaje
		Vector distPersonaje = lista[i]->pos - p.getPos();
		Vector velPersonaje = distPersonaje.unitario() * -(distPersonaje.modulo() - lista[i]->distPersonaje);
		
		//resultado
		lista[i]->vel = velPersonaje + velEnemigos + velColiseo*0.2f;
		lista[i]->mueve(t, p.getPos());
	}
}

void ListaEnemigos::rebote()
{
	for (int i = 0; i < numero-1; i++)
		for (int j = i+1; i < numero; i++)
		Interaccion::rebote(*lista[j], *lista[i]);
}

void ListaEnemigos::rebote(Personaje p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(p, *lista[i]);
}

bool ListaEnemigos::agregar(Enemigo* e)
{
	if (numero < MAX_ENEMIGOS) {
		for (int i = 0; i < numero; i++)
			if (e == lista[i]) {
				return false;
			}
		lista[numero++] = e;
	}
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaEnemigos::eliminar(Enemigo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}

Enemigo* ListaEnemigos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaEnemigos::colision_coliseo(Coliseo c)
{
	for (int i = 0; i < numero; i++)
		Interaccion::colision_coliseo(*(lista[i]), c);
}