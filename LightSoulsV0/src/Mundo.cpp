#include "Mundo.h"
#include "freeglut.h"
#include "iostream"
#include "stdio.h"
#include "Interaccion.h"

void Mundo::dibuja()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluLookAt(0, 0, 20,  // posicion del ojo
		0, 0, -10,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	c.dibuja();
	enemigos.dibuja();
	coliseo.dibuja();
}

void Mundo::mueve()
{
	c.setVel(2*(d - a), 2*(w - s));

	c.mueve(0.025, raton);
	enemigos.mueve(0.025, c, coliseo);
	enemigos.rebote();
	enemigos.rebote(c);
}

void Mundo::inicializa()
{
	coliseo.setRadio(10);

	c.cargar("armas/garrote.txt");

	enemigos.agregar(new Enemigo(1, 1, 500, 2, 2, 5, 4, 2));
	enemigos.agregar(new Enemigo(2, 4, 500, 2, 1, 5, 4, 2));
	enemigos.agregar(new Enemigo(2, 4, 500, 2, 1, 9, 5, 2));

	enemigos[0]->cargar("armas/espada.txt");
	enemigos[1]->cargar("armas/espada.txt");
	enemigos[2]->cargar("armas/espada.txt");
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


