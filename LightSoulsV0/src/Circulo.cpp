#include "Circulo.h"

void Circulo::dibuja()
{
	glColor3ub(255, 0, 0);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

}
