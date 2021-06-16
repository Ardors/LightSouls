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

void ListaEnemigos::atacar(Personaje p)
{
	for (int i = 0; i < numero; i++)
		lista[i]->atacar(p);
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
	numero_oleadas = 0;
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
/*
void ListaEnemigos::checkVida()
{
	for (int i = 0; i < numero; i++) {
		if (lista[i]->noVida())
			eliminar(lista[i]);
	}
}*/
bool ListaEnemigos::generar_oleadas() {

	//static int numero_oleadas = 0;

	if (numero == 0) {
		int numero_enemigos = 3 + rand() % (6 - 3);
		int desfase_inicial =  rand() % (361 - 0);
		int desfase_enemigos = 360 / numero_enemigos;
		int i;
		for (i = 0; i < numero_enemigos; i++) {
			//Posición
			int angulo = desfase_inicial + desfase_enemigos * i;
			float posicion_x = 8 * cos(angulo * 3.1415 / 180.0); 
			float posicion_y = 8 * sin(angulo * 3.1415 / 180.0);

			//Vida
			float vida;
			if (numero_oleadas < 4) vida = 100;
			else vida = 200;

			//Peso
			int tipo_enemigo = rand() % (10 - 0);
			float p;
			if (tipo_enemigo == 0 || tipo_enemigo == 1) p = 1.5f; //Garrote
			if (tipo_enemigo == 2) p = 3.0f; //Alabarda
			if (tipo_enemigo > 2 && tipo_enemigo < 5) p = 2.0f; //Lanza 
			if (tipo_enemigo >= 5) p = 2.25f; //Espada

			//Distancia al jugador
			float dist_jugador;
			if (tipo_enemigo > 3 && tipo_enemigo < 7) dist_jugador = 9;
			else dist_jugador = 5;

			//Generación de enemigos
			agregar(new Enemigo(posicion_x, posicion_y, vida, p, 2, dist_jugador, 4, 2));

			//Asignación de armas
			if (tipo_enemigo == 0 || tipo_enemigo == 1) lista[i]->cargar("armas/garrote.txt"); //Garrote
			if (tipo_enemigo == 2) lista[i]->cargar("armas/alabarda.txt"); //Alabarda
			if (tipo_enemigo > 2 && tipo_enemigo < 5) lista[i]->cargar("armas/lanza.txt"); //Lanza 
			if (tipo_enemigo >= 5) lista[i]->cargar("armas/espada.txt"); //Espada
		}
		numero_oleadas++;
	}
	if (numero_oleadas >= 5) return true;
	else return false;
}