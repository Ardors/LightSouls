#pragma once
#include "freeglut.h"
#include <stdio.h>
#include <iostream>
#include "Vector.h"
#include <fstream>

#define MAXFRASE 50
#define MAXN 4

class Menutienda {
private:
	int n=0;
	int selec=0;
	int comprada = 0;
	char items[MAXN][MAXFRASE]; //para las frases jejejeejeej
	Vector desplazamiento;
	int perdinero=0;
public:
	Menutienda();
	virtual ~Menutienda();
	void subir(); //void setselec();
	void bajar();
	int getSelec() { return selec; }
	void dibuja(int dinero); //hay q pasarle dienro
	void addFrase(const char cadena[]);
	void setdesplazamiento(float x, float y);
	void comprar(int &dinero); //es una referencia!!
	
};