#include "Menu.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Menu::Menu()
{
	selec = 0;
	n = 1; //la clase tiene una n y el construtor otra n.
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
		if(i==selec)
			std::cout <<"> "<< frase[i] << std::endl;
		else
			std::cout << "- " << frase[i] << std::endl;
	}
}

void Menu::setFrase(const char cadena[], int pos) //pos indicas cual de las frases quieres meter el valor
{
	if (pos < n && pos>=0) {
		for (int i = 0; i < MAXFRASE; i++)
			frase[pos][i] = cadena[i];
	}
}

void Menu::setN(int n)
{
	this->n = n;
}



