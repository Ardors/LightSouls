#include "Menu.h"
#include <stdio.h>
#include <iostream>
#include "ETSIDI.h"
//using namespace std;


Menu::Menu()
{
	selec = 0;
	//n = 0; //la clase tiene una n y el construtor otra n.
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
}

Menu::~Menu()
{
}



void Menu::subir()
{
	if (++selec >= n) selec = 0; //hay dos instrucciones a la vez por un lado sma y por otto hace la comprobacion
}

void Menu::bajar()
{
	if (--selec < 0) selec = n-1; //asi puede hacer el bucle de seleccionar todos
	//menudo error se ha solucionao poniendolo delante xd xq queremos q sume y luego baje o suba
}

void Menu::dibuja()
{
	
	for (int i = 0; i < n; i++) {
		if (i == selec)ETSIDI::setTextColor(1, 1, 1);
		else ETSIDI::setTextColor(0.5f, 0.5f, 0.5f);
		ETSIDI::printxy2(frase[i], desplazamiento.x, desplazamiento.y-(float)i*1.2);
		
	}

}

void Menu::addFrase(const char cadena[]) //pos indicas cual de las frases quieres meter el valor
{
	
	if (n <MAXN) {
		n++;
		for (int i = 0; i < MAXFRASE; i++)
			frase[n - 1][i] = cadena[i];
	}
	
}

void Menu::setdesplazamiento(float x, float y)
{
	desplazamiento.x = x;
	desplazamiento.y = y;
}



