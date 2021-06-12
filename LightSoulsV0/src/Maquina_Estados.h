#pragma once
#include <freeglut.h>
#include <iostream>
#include "Mundo.h"
<<<<<<< Updated upstream
#include "Menu.h"
#include "Menutienda.h"
=======
#include "Menutienda.h"
#include "Menu.h"
>>>>>>> Stashed changes

using namespace std;

class Maquina_Estados
{

public:
	
	Maquina_Estados();
<<<<<<< Updated upstream
=======
	Mundo mundo;
	Menu inicio;
	
	
>>>>>>> Stashed changes
	void SpecialKey(unsigned char key);
	void tecla(unsigned char key);
	void dibuja();
	void inicializa() { mundo.inicializa(); }
	void mueve() { mundo.mueve(); }
	void mouse(int x, int y) { mundo.mouse(x,y); }
protected:
	enum Estado { START, GAME, GAME_OVER, ENDING, MENU, TIENDA };
	Estado estado;
	Mundo mundo;
	Menu principal;
	Menutienda menutienda;
	int dinero=200;
};
