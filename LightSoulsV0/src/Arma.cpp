#include "Arma.h"
#include "freeglut.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <sstream> 
using namespace std;

#define MAX_ANIMACION 200 //5 segundos (40fps)

void Arma::cargar(const char* archivo)
{
	ifstream fuente(archivo);

	fuente.ignore(15, '\n'); //ignorar precio

	fuente >> daño1;
	fuente >> daño2;

	char nombreSprite[30];
	float centroX, centroY, dimX, dimY;
	fuente >> nombreSprite;
	fuente >> dimX;
	fuente >> dimY;
	fuente >> centroX;
	fuente >> centroY;

	sprite = *(new SpriteSequence{nombreSprite ,1 });
	sprite.setSize(dimX, dimY);
	sprite.setCenter(centroX, centroY);

	fuente >> dis2;
	fuente >> ang1o;
	fuente >> ang2o;
	fuente >> dis1o;

	ani1.cargar(fuente);
	ani2.cargar(fuente);
}

void Arma::dibuja()
{
	float x1 = dis1 * cos(ang1);
	float y1 = dis1 * sin(ang1);

	if (activa) {
		glColor3ub(255, 0, 0);
		glBegin(GL_POLYGON);
		glVertex3d(x1 * cos(ang1), y1, 0);
		glVertex3d(x1 + dis2 * cos(ang2 + ang1), y1 + dis2 * sin(ang2 + ang1), 0);
		glVertex3d(x1 + dis2 * cos(ang2 + ang1), y1 + dis2 * sin(ang2 + ang1)+0.5f, 0);
		glVertex3d(x1 * cos(ang1), y1+0.5f, 0);
		
		glEnd();
	}
	glColor3ub(0, 255, 0);
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3d(x1, y1, 0);
	glVertex3d(x1+ dis2 * cos(ang2+ang1), y1 + dis2 * sin(ang2+ang1), 0);
	glEnd();
	glTranslatef(x1,y1,0);
	glRotatef((ang2+ang1)*57.3, 0, 0, 1);
	sprite.draw();
	glPopMatrix();
}

void Arma::atacar(bool secundario)
{
	if (!ani1.enProceso() && !ani2.enProceso()) {
		if (!secundario)
			ani1.iniciar();
		else
			ani2.iniciar();
	}
}

void Arma::mueve()
{
	if (ani1.pasarFrame(&ang1, &ang2, &dis1, &activa)) 
	{ 
		atacando = 1;
	}
	else if (ani2.pasarFrame(&ang1, &ang2, &dis1, &activa))
	{  
		atacando = 2;
	}
	else
	{
		atacando = 0;
		ang1 = ang1o;
		ang2 = ang2o;
		dis1 = dis1o;
		activa = 0;
	}
	p1.x = origen->x + dis1 * cos(ang1);
	p1.y = origen->y + dis1 * sin(ang1);
	p2.x = p1.x + dis2 * cos(ang1 + ang2);
	p2.y = p1.y + dis2 * sin(ang1 + ang2);
}
