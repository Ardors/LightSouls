#include "Inicio.h"



void Inicio::dibuja()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluLookAt(0, 0, 20, //posicion del ojo
		0, 0, -10,		//hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0);

	c.dibuja();
	merc_armas.dibuja();
	merc_escudos.dibuja();
	merc_pociones.dibuja();
	puerta.dibuja();
	foro.dibuja();

}

int Inicio::triggers()
{
	if (Interaccion::tienda(c, merc_armas)) return 1;
	else if (Interaccion::tienda(c, merc_escudos)) return 2;
		else if (Interaccion::tienda(c, merc_pociones)) return 3;
			else if (Interaccion::tienda(c, puerta)) return 4;
			else return 0;
}

void Inicio::mueve()
{
	c.setVel(2 * (d - a), 2 * (w - s));
	c.mueve(0.025, raton);
	Interaccion::colision_coliseo(c, foro);
	//revisar colisiones
	Interaccion::colision_mercader(c, merc_armas);
	Interaccion::colision_mercader(c, merc_escudos);
	Interaccion::colision_mercader(c, merc_pociones);
	Interaccion::colision_mercader(c, puerta);

	Interaccion::tienda(c, merc_armas);
	Interaccion::tienda(c, merc_escudos);
	Interaccion::tienda(c, merc_pociones);
	Interaccion::tienda(c, puerta);
	
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

	merc_armas.setSprite("imagenes/herrero2.png");
	merc_armas.setSize(1.8, 2.5);
	merc_armas.setPos(7.5, 0.0);
	merc_armas.setAng(180);

	merc_escudos.setSprite("imagenes/mago2.png");
	merc_escudos.setSize(1.8, 2.5);
	merc_escudos.setPos(0.0, 7.5);
	merc_escudos.setAng(-90.0);

	merc_pociones.setSprite("imagenes/bruja2.png");
	merc_pociones.setSize(1.8, 2.5);
	merc_pociones.setPos(-7.5, 0.0);
	merc_pociones.setAng(0.0);

	puerta.setSprite("imagenes/personaje.png");
	puerta.setSize(1.8, 2.5);
	puerta.setPos(0.0, -4.5);
	puerta.setAng(90.0);
}

void Inicio::mouse(int x, int y)
{
	raton.x = x;
	raton.y = -y;
	Vector ventana(ANCHO, -ALTO);
	raton = (raton + camara - ventana * 0.5f) * 0.02;
}
