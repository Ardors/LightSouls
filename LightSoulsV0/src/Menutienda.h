#pragma once
#include "freeglut.h"

#define FILAS 4
#define COLUMNAS 6

class Menutienda {
	int selec=0;
	//int objetos[FILAS][COLUMNAS];


public:
	void dibuja();
	void subir(); //void setselec();
	void bajar();
	void dcha();
	void izqd();
	int getSelec() { return selec; }
};