#include "Circulo.h"

void Circulo::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Circulo::setVel(float vx, float vy)
{
	vel.x = vx;
	vel.y = vy;
}

void Circulo::setAng(float ang)
{
	while (ang > 360)
		ang -= 360;
	while (ang < -360)
		ang += 360;
	angulo = ang;
}

void Circulo::dibuja()
{
	glColor3ub(255, 0, 0);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angulo, 0, 0, 1);
	glutWireSphere(radio, 10, 10);
	glPopMatrix();

}

void Circulo::mueve(float t)
{
	pos.x += vel.x * t;
	pos.y += vel.y * t;
}

