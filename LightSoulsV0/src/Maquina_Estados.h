#pragma once
#include <freeglut.h>
#include <iostream>
#include "Mundo.h"

using namespace std;

class Maquina_Estados
{
public:
	Maquina_Estados();
	Mundo mundo;
	void SpecialKey(unsigned char key);
	void tecla(unsigned char key);
	void dibuja();
	void inicializa() { mundo.inicializa(); }
	void mueve() { mundo.mueve(); }
	void mouse(int x, int y) { mundo.mouse(x,y); }
protected:
	enum Estado { START, GAME, GAME_OVER, ENDING, MENU, TIENDA };
	Estado estado;
};
