#include "Inicio.h"



void Inicio::dibuja()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluLookAt(0, 0, 20, //posicion del ojo
		0, 0, -10,		//hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0);

	c.dibuja();
	foro.dibuja();

}

void Inicio::mueve()
{
	c.setVel(2 * (d - a), 2 * (w - s));
	c.mueve(0.025, raton);
}

void Inicio::tecla(unsigned char key)
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
	}
}

void Inicio::teclaSuelta(unsigned char key)
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

void Inicio::inicializa()
{
	foro.setRadio(10);
	c.cargar("armas/espada.txt");
}

void Inicio::mouse(int x, int y)
{
	raton.x = x;
	raton.y = -y;
	Vector ventana(ANCHO, -ALTO);
	raton = (raton + camara - ventana * 0.5f) * 0.02;
}
