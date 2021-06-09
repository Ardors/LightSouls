#include "ListaProyectiles.h"

ListaProyectiles::ListaProyectiles()
{
	numero = 0;
	for (int i = 0; i < MAX_PROYECTILES; i++)
		lista[i] = nullptr;                   //inicialmente la lista está vacía
}

bool ListaProyectiles::agregar(Proyectil* p)
{
	for (int i = 0; i < numero; i++) {
		if (p == lista[i])
			return false;	//Comprueba que no se agregue el mismo proyectil 2 veces
	}
	
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

void ListaProyectiles::eliminar(int index)
{
	if ((index < 0) || (index >= numero))      //indice no valido
		return;
	delete lista[index];
	numero--;                                  //actualiza el numero de elementos de la lista
	for (int i = index; i < numero; i++)       //ajusta el contenido de la lista
		lista[i] = lista[i + 1];
}

void ListaProyectiles::eliminar(Proyectil* p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == p)
		{
			eliminar(i);
			return;
		}
}

void ListaProyectiles::eliminar_t()
{
	for (int i = 0; i < numero; i++) {
		if (lista[i]->t_excedido()) {
			eliminar(lista[i]);
			return;
		}
	}
}

Proyectil* ListaProyectiles::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}