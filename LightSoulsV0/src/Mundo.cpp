#include "Mundo.h"
#include "freeglut.h"
#include "iostream"
#include "stdio.h"
#include "Interaccion.h"

Mundo::~Mundo()
{
	proyectiles.destruirContenido();
	enemigos.destruirContenido();

}

void Mundo::dibuja()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluLookAt(0, 0, 20,  // posicion del ojo
		0, 0, -10,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-14.5f, 9.0f, 0.0f);
	glVertex3f(-14.5f, 9.8f, 0.0f);
	glVertex3f(-14.5f + c.getVida() * 12.5 / 1000, 9.8f, 0.0f);
	glVertex3f(-14.5f + c.getVida() * 12.5 / 1000, 9.0f, 0.0f);
	glEnd();

	glColor3ub(235, 235, 235);
	glBegin(GL_POLYGON);
	glVertex3f(-14.5f, 9.0f, 0.0f);
	glVertex3f(-14.5f, 9.8f, 0.0f);
	glVertex3f(-2.0f, 9.8f, 0.0f);
	glVertex3f(-2.0f, 9.0f, 0.0f);
	glEnd();



	//el de fuera
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-14.6f, 8.9f, 0.0f);
	glVertex3f(-14.6f, 9.9f, 0.0f);
	glVertex3f(-1.9f, 9.9f, 0.0f);
	glVertex3f(-1.9f, 8.9f, 0.0f);
	glEnd();


	c.dibuja();
	enemigos.dibuja();
	coliseo.dibuja();
	proyectiles.dibuja();
}

void Mundo::mueve()
{
	c.setVel(2*(d - a), 2*(w - s));

	c.mueve(0.025, raton);
	enemigos.mueve(0.025, c, coliseo);
	enemigos.rebote();
	enemigos.rebote(c);
	enemigos.colision_coliseo(coliseo);
	enemigos.generar_oleadas();
	Interaccion :: colision_coliseo(c, coliseo);
	enemigos.atacar(c);

	proyectiles.mueve(0.025);
	proyectiles.eliminar_t();

	for (int i = 0; i < enemigos.getNumero(); i++) {
		Interaccion::ataque(c, *(enemigos[i]));
		Interaccion::ataque(*(enemigos[i]), c);
		if (enemigos[i]->muerto())
			enemigos.eliminar(i);

		//enemigos.checkVida();
	}

	Interaccion::colision(proyectiles, enemigos);
	//enemigos.checkVida();
	c.muerto();

}

void Mundo::inicializa()
{
	enemigos.destruirContenido();
	coliseo.setRadio(10);
	c.setVida(1000);

	//c.cargar("armas/espada.txt");
/*
	enemigos.agregar(new Enemigo(1, 1, 500, 2, 2, 5, 4, 2));
	enemigos.agregar(new Enemigo(2, 4, 500, 2, 1, 5, 4, 2));
	enemigos.agregar(new Enemigo(2, 4, 500, 2, 1, 9, 5, 2));

	enemigos[0]->cargar("armas/espada.txt");
	enemigos[1]->cargar("armas/espada.txt");
	enemigos[2]->cargar("armas/espada.txt");
	*/

}

void Mundo::tecla(unsigned char key)
{
	switch (key) {
	case 'a':
		a = true;
		break;
	case 'd':
		d = true;
		break;
	case 'w':
		w = true;
		break;
	case 's':
		s = true;
		break;
	case 'q':
		c.atacar(false);
		break;
	case 'e':
		c.atacar(true);
		break;
	case ' ':
		proyectiles.agregar(new Proyectil(c.getPos(), c.getAng()));
		break;
	}
}

void Mundo::teclaSuelta(unsigned char key)
{
	switch (key) {
	case 'a':
		a = false;
		break;
	case 'd':
		d = false;
		break;
	case 'w':
		w = false;
		break;
	case 's':
		s = false;
		break;
	}
}

void Mundo::mouse(int x, int y) 
{
	//convertir coordenas del mouse con respecto a ventana a respecto escena
	raton.x = x;
	raton.y = -y;
	Vector ventana(ANCHO, -ALTO);
	raton = (raton + camara - ventana*0.5f)*0.02;
}


