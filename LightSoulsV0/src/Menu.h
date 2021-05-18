#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXFRASE 20
#define MAXN 8


class Menu
{
	int n, selec; //n para saber cuantas opciones y selec para seleccionar esa opcion
	//selec es la posicion q quieres guardar mientras q pos es donde quieres guardar la frase
	char frase[MAXN][MAXFRASE]; //para las frases jejejeejeej
public:
	Menu();
	virtual ~Menu();
	void subir(); //void setselec();
	void bajar();
	int getSelec() { return selec; }
	void dibuja();
	void setFrase(const char cadena[], int pos);
	void setN(int n);

};

