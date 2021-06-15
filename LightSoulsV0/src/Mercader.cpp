#include "Mercader.h"

void Mercader::dibuja()
{
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angulo, 0, 0, 1);
	cuerpo.draw();
	glPopMatrix();
}

void Mercader::setSprite(const char* nombreSprite)
{
	cuerpo = *(new SpriteSequence{ nombreSprite ,1 });
}

void Mercader::setSize(float size_x, float size_y)
{
	cuerpo.setCenter(size_x / 2, size_y / 2); 
	cuerpo.setSize(size_x, size_y);
}




