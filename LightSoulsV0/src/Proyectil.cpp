#include "Proyectil.h"

Proyectil::Proyectil(Vector posicion, float ang, float r, int damage, float p)
{
	tiempo_creacion = clock();
	t_max = 1.0f;
	pos = posicion;
	ang = ang * 3.14159 / 180;
	vel.x = 4 * cos(ang);
	vel.y = 4 * sin(ang);
	radio = r;
	dano = damage;
	peso = p;

}



bool Proyectil::t_excedido()
{
	clock_t t_actual;
	t_actual = clock() - tiempo_creacion; //tiempo transcurrido desde la creacion del proyectil hasta el momento actual      
	t_actual = ((float)t_actual) / CLOCKS_PER_SEC; //conversion a segundos
	return (t_actual >= t_max);
}
