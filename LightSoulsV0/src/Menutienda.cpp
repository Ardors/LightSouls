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
	char cuenta[] = "Dinero:    "; //array de caracteres con 4 espacios
	//cuenta[] = "dinero: ";
	cuenta[8] = '0' + ((dinero % 1000) / 100); //SOLO PARA LAS CENTENAS
	cuenta[9] = '0' + ((dinero % 100) / 10); //SOLO PARA LAS decenas
	cuenta[10] = '0' + (dinero % 10) / 1; //SOLO PARA LAS unicdades

	glColor3ub(170, 149, 139);
	glBegin(GL_POLYGON);
	glVertex3f(3.8f, -4.0f, 0.0f);
	glVertex3f(3.8f, -1.0f, 0.0f);
	glVertex3f(12.2f, -1.0f, 0.0f);
	glVertex3f(12.2f, -4.0f, 0.0f);
	glEnd();

	//el de fuera
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(3.7f, -4.1f, 0.0f);
	glVertex3f(3.7f, -0.9f, 0.0f);
	glVertex3f(12.3f, -0.9f, 0.0f);
	glVertex3f(12.3f, -4.1f, 0.0f);
	glEnd();
	ETSIDI::setTextColor(0, 0, 0);
	ETSIDI::printxy2(cuenta, 4, -3);
	ETSIDI::setTextColor(1, 1, 1);


	//mercader
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(dibujotienda).id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(4, 1);
	glTexCoord2d(1, 1); glVertex2f(12, 1);
	glTexCoord2d(1, 0); glVertex2f(12, 7);
	glTexCoord2d(0, 0); glVertex2f(4, 7);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//cada estus
	for (int i = 0; i < 4; i++) {

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(imagenes[i]).id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1); glVertex2f(-12.5f, 4.6f - 3.25 * i); //5ANCHO=LARGO
		glTexCoord2d(1, 1); glVertex2f(0.5f, 4.6f - 3.25 * i); //se llevan 2.4
		glTexCoord2d(1, 0); glVertex2f(0.5f, 7 - 3.25 * i);
		glTexCoord2d(0, 0); glVertex2f(-12.5f, 7 - 3.25 * i);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}


	//rectangulorojo
	glColor3ub(255, 255, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-12.6f, 4.5 - 3.25 * selec, 0.0f);
	glVertex3f(-12.6f, 7.1 - 3.25 * selec, 0.0f);
	glVertex3f(0.6f, 7.1 - 3.25 * selec, 0.0f);
	glVertex3f(0.6f, 4.5 - 3.25 * selec, 0.0f);
	glEnd();

	//rectanguloazul
	glColor3ub(236, 124, 38);
	glBegin(GL_POLYGON);
	glVertex3f(-12.6f, 4.5 - 3.25 * comprada, 0.0f);
	glVertex3f(-12.6f, 7.1 - 3.25 * comprada, 0.0f);
	glVertex3f(0.6f, 7.1 - 3.25 * comprada, 0.0f);
	glVertex3f(0.6f, 4.5 - 3.25 * comprada, 0.0f);
	glEnd();


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

char* Menutienda::comprar(int& dinero)
{

	ifstream fuente(items[selec]); //flujo para ficheros de entrada
	if (fuente) {
		std::cout << "cargado" << std::endl;
	}
	else {
		std::cout << "error" << std::endl;
		return 0;
	}
	int precio;
	fuente >> precio;
	if (dinero > precio - perdinero) {
		dinero = dinero - (precio - perdinero); //perdinero = PERMANECEDINERO
		perdinero = precio;
		comprada = selec;
		std::cout << dinero << std::endl;
		return items[selec];
	}

}

void Menutienda::cargardibujo()
{
	for (int i = 0; i < n; i++) {
		ifstream fuente(items[i]); //flujo para ficheros de entrada
		fuente.ignore(30, '\n');
		fuente >> imagenes[i];
	}
}
