#pragma once
#include <freeglut.h>
#include <iostream>
#include "Mundo.h"
<<<<<<< Updated upstream
#include "Menu.h"
#include "Menutienda.h"
<<<<<<< Updated upstream
=======
#include "Menutienda.h"
#include "Menu.h"
>>>>>>> Stashed changes
=======
#include <iostream>

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
<<<<<<< Updated upstream
	void inicializa() { mundo.inicializa(); }
	void mueve() { mundo.mueve(); }
	void mouse(int x, int y) { mundo.mouse(x,y); }
protected:
	enum Estado { START, GAME, GAME_OVER, ENDING, MENU, TIENDA };
=======
	void inicializa();
	void mueve() { mundo.mueve(); inicio.mueve(); }
	void mouse(int x, int y) { mundo.mouse(x, y); inicio.mouse(x, y); }
protected:
	enum Estado { START, GAME, GAME_OVER, ENDING, MENU, HERRERO, BRUJA, MAGO, INICIO, OPCIONES, MENUINICIO, MENUJUEGO,SALIR };
	int dinero = 200;
>>>>>>> Stashed changes
	Estado estado;
	Mundo mundo;
	Menu principal;
<<<<<<< Updated upstream
	Menutienda menutienda;
	int dinero=200;
=======
	Menu opciones;
	Menu Minicio;
	Menu Mjuego;
	Menutienda bruja;
	Menutienda herrero;
	Menutienda mago;
>>>>>>> Stashed changes
};
