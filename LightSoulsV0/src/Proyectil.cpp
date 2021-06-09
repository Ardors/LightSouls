#include "Proyectil.h"

Proyectil::Proyectil(Vector posicion, float ang)
{
	tiempo_creacion = clock();
	t_max = 1.0f;
	pos = posicion;
	ang = ang * 3.14159 / 180;
	vel.x = 1 * cos(ang);
	vel.y = 1 * sin(ang);
}

bool Proyectil::t_excedido()
{
	clock_t t_actual;
	t_actual = clock() - tiempo_creacion; //tiempo transcurrido desde la creacion del proyectil hasta el momento actual      
	t_actual = ((float)t_actual) / CLOCKS_PER_SEC; //conversion a segundos
	return (t_actual >= t_max);
}
