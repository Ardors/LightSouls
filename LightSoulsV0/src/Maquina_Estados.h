#pragma once
#include <freeglut.h>
#include <iostream>
#include "Mundo.h"
#include "Inicio.h"

using namespace std;

class Maquina_Estados
{
public:
	Maquina_Estados();
	void SpecialKey(unsigned char key);
	void tecla(unsigned char key);
	void teclaSuelta(unsigned char key);
	void dibuja();
	void inicializa() { mundo.inicializa(); inicio.inicializa(); }
	void mueve() { mundo.mueve(); inicio.mueve(); }
	void mouse(int x, int y) { mundo.mouse(x, y); inicio.mouse(x, y); }
protected:
	enum Estado { START, GAME, GAME_OVER, ENDING, MENU, TIENDA, INICIO };
	Estado estado;
	Mundo mundo;
	Inicio inicio;
};
