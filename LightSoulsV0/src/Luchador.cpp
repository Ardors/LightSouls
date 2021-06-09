#include "Luchador.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Luchador::dibuja()
{

	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angulo, 0, 0, 1);
	cuerpo.draw();
	glPopMatrix();

	glColor3ub(255, 0, 0);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(angulo, 0, 0, 1);
	glutWireSphere(radio, 10, 10);
	arma.dibuja();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(vel.argumento() * 57.3, 0, 0, 1);
	piernas.setCenter(vel.modulo()*0.9 , 1.25);
	piernas.setSize(vel.modulo() * 1.8, 2.5);
	piernas.draw();
	glPopMatrix();
	piernas.loop();
}

void Luchador::mueve(float t, Vector obj)
{
	if (arma.atacando == 0) {
		if (vel.modulo() > maxVel)
			vel = vel.unitario() * maxVel;
		pos.x += vel.x * t;
		pos.y += vel.y * t;

		setAng((180 / M_PI) * (obj - getPos()).argumento());
	}
	arma.mueve();
}
