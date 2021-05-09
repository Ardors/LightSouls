#include "Mundo.h"
#include "freeglut.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Circulo.h"
#include "iostream"


void Mundo::dibuja()
{
	gluLookAt(camara.x, camara.y, 20,  // posicion del ojo
			camara.x, camara.y, -10,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
			
	//aqui es donde hay que poner el codigo de dibujo


	c.dibuja();
}

void Mundo::mueve()
{
	c.mueve(0.025);
}

void Mundo::inicializa()
{

	
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
	case 'c':
		c.setVel(0, 0);
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


