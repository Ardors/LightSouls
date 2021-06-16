#include "Coliseo.h"
#include "freeglut.h"

Coliseo::Coliseo()
{
	radio = 2.0f;
}


void Coliseo::dibuja()
{
	
	glPushMatrix();
	for (int i = 0; i<16; i ++) {
		glRotatef(22.5, 0, 0, 1);
		glTranslatef(0, radio, 0);
		sprite.draw();
		glTranslatef(0, -radio, 0);
		
	}
	glPopMatrix();
	suelo.draw();
}

void Coliseo::setRadio(float radio)
{
	this->radio = radio;
	sprite.setCenter(0, 0);
	sprite.setSize(radio * 0.5, radio * 0.28);
	suelo.setSize(radio * 2.4, radio * 2.4);
	suelo.setCenter(radio *1.2, radio*1.2);
}
