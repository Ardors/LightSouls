#pragma once
#include <freeglut.h>
#include <iostream>
#include "Mundo.h"
#include "Inicio.h"
#include "Menu.h"
#include "Menutienda.h"

using namespace std;

class Maquina_Estados
{
public:
	Maquina_Estados();
	void SpecialKey(unsigned char key);
	void tecla(unsigned char key);
	void teclaSuelta(unsigned char key);
	void dibuja();
	void inicializa() {}
	void mueve();
	void mouse(int x, int y) { mundo.mouse(x, y); inicio.mouse(x, y); }
protected:
	enum Estado { START, GAME, GAME_OVER, ENDING, MENU, HERRERO, BRUJA, MAGO, INICIO, CREDITOS, MENUINICIO, MENUJUEGO, INSTRUCCIONES};
	Estado estado;
	Mundo mundo;
	Inicio inicio;
	Menu principal;
	Menu Minicio;
	Menu Mjuego;
	Menutienda bruja ,herrero, mago;
	int dinero = 200;
};
