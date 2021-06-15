#include "Menutienda.h"
#include "Menu.h"
#include <stdio.h>
#include <iostream>
#include "ETSIDI.h"
#include "Vector.h"
//using namespace std;


Menutienda::Menutienda()
{
	selec = 0;
	ETSIDI::setFont("fuentes/Bitwise.ttf", 40);
}

Menutienda::~Menutienda()
{
}


void Menutienda::subir()
{
	if (++selec >= n) selec = 0; //hay dos instrucciones a la vez por un lado sma y por otto hace la comprobacion

}

void Menutienda::bajar()
{
	if (--selec < 0) selec = n - 1; //asi puede hacer el bucle de seleccionar todos
	//menudo error se ha solucionao poniendolo delante xd xq queremos q sume y luego baje o suba
	
}

void Menutienda::dibuja(int dinero)
{
	char cuenta[]="Dinero:    "; //array de caracteres con 4 espacios
	//cuenta[] = "dinero: ";
		cuenta[8] = '0'+((dinero % 1000) / 100); //SOLO PARA LAS CENTENAS
		cuenta[9] = '0' + ((dinero % 100) / 10); //SOLO PARA LAS decenas
		cuenta[10] = '0' + (dinero % 10) / 1; //SOLO PARA LAS unicdades
	
		ETSIDI::printxy2(cuenta, 4, 0);


	//SEÑOR TIENDA

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/descargar.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(4, 2);
	glTexCoord2d(1, 1); glVertex2f(8, 2);
	glTexCoord2d(1, 0); glVertex2f(8, 6);
	glTexCoord2d(0, 0); glVertex2f(4, 6);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


	for (int i = 0; i < 4; i++) {
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/descargar.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(-8, 4-2.25*i);
		glTexCoord2d(1, 1); glVertex2f(2, 4 - 2.25 * i);
		glTexCoord2d(1, 0); glVertex2f(2,  6- 2.25 * i);
		glTexCoord2d(0, 0); glVertex2f(-8, 6 - 2.25 * i);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	//rectangulorojo
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-8.2f, 3.9-2.25*selec, 0.0f);
	glVertex3f(-8.2f, 6.1-2.25 * selec, 0.0f);
	glVertex3f(2.2f, 6.1-2.25 * selec, 0.0f);
	glVertex3f(2.2f, 3.9-2.25 * selec, 0.0f);
	glEnd();

	//rectanguloazul
	
		glColor3ub(0, 0, 255);
		glBegin(GL_POLYGON);
		glVertex3f(-8.2f, 3.9 - 2.25 * comprada, 0.0f);
		glVertex3f(-8.2f, 6.1 - 2.25 * comprada, 0.0f);
		glVertex3f(2.2f, 6.1 - 2.25 * comprada, 0.0f);
		glVertex3f(2.2f, 3.9 - 2.25 * comprada, 0.0f);
		glEnd();
	
	ETSIDI::printxy2("hola \n adios", 4, 0);

}

void Menutienda::addFrase(const char cadena[]) //pos indicas cual de las frases quieres meter el valor
{
	if (n < MAXN)
	{
		n++;
		for (int i = 0; i < MAXFRASE; i++)
			items[n - 1][i] = cadena[i];
	}
}
 
void Menutienda::setdesplazamiento(float x, float y)
{
	desplazamiento.x = x;
	desplazamiento.y = y;
}

void Menutienda::comprar(int &dinero)
{
	
	ifstream fuente(items[selec]); //flujo para ficheros de entrada
	if (fuente) {
		std::cout << "cargado" << std::endl;
	}
	else {
		std::cout << "error" << std::endl;
		return;
	}
	int precio;
	fuente >> precio;
	if (dinero > precio-perdinero) {
		dinero = dinero - (precio - perdinero); //perdinero = PERMANECEDINERO
		perdinero = precio;
		comprada = selec;
		std::cout << dinero << std::endl;
	}

}
