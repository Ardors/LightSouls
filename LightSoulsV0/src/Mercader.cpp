#include "Mercader.h"

void Mercader::dibuja()
{
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angulo, 0, 0, 1);
	cuerpo.draw();
	glPopMatrix();
}

