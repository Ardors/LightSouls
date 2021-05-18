#include "ListaProyectiles.h"

ListaProyectiles::ListaProyectiles()
{
	numero = 0;
	for (int i = 0; i < MAX_PROYECTILES; i++)
		lista[i] = nullptr;                   //inicialmente la lista está vacía
}

bool ListaProyectiles::agregar(Proyectil* p)
{
	if (numero < MAX_PROYECTILES)
		lista[numero++] = p; 
	else
		return false; // lista llena
	return true;
}

void ListaProyectiles::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaProyectiles::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaProyectiles::destruirContenido()
{
	for (int i = 0; i < numero; i++) 
		delete lista[i];
	numero = 0;              // inicialización de la lista

}