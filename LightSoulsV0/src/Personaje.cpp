#include "Personaje.h"

void Personaje::dibuja()
{
	glColor3ub(255, 0, 0);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angulo, 0, 0, 1);
	glutWireSphere(radio, 10, 10);
	arma.dibuja();
	glPopMatrix();
}

void Personaje::mueve(float t)
{
	pos.x += vel.x * t;
	pos.y += vel.y * t;
	arma.mueve();
}
