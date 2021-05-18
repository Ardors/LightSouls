#include "Mundo.h"
#include "freeglut.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Circulo.h"
#include "iostream"
#include "stdio.h"

void Mundo::dibuja()
{
	gluLookAt(0, 0, 20,  // posicion del ojo
		0, 0, -10,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	c.dibuja();
}

void Mundo::mueve()
{
	c.mueve(0.025);
}

void Mundo::inicializa()
{
	c.cargar("armas/espada.txt");
	
}

void Mundo::tecla(unsigned char key)
{
	switch (key) {
	case 'a':
		c.setVel(-2,0);
		break;
	case 'd':
		c.setVel(2, 0);
		break;
	case 'w':
		c.setVel(0, 2);
		break;
	case 's':
		c.setVel(0, -2);
		break;
	case 'c':
		c.setVel(0, 0);
		break;
	case 'q':
		c.atacar(false);
		break;
	case 'e':
		c.atacar(true);
		break;
	}
}

void Mundo::mouse(int x, int y) 
{
	//convertir coordenas del mouse con respecto a ventana a respecto escena
	Vector posRaton(x, -y);
	Vector ventana(ANCHO, -ALTO);
	posRaton = posRaton + camara - ventana*0.5f;
	//calculo de la orientacion del personaje
	c.setAng((180/M_PI)*(posRaton - c.getPos()*50).argumento()); 

}


