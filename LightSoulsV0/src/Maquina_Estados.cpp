#include "Maquina_Estados.h"
#include "ETSIDI.h"
#include "Menu.h"
#include <windows.h>
#include <stdlib.h>

Maquina_Estados::Maquina_Estados()
{
	estado = START;

	//MENU PRINCIPAL
	principal.addFrase("JUGAR");
	principal.addFrase("OPCIONES");
	principal.addFrase("SALIR");
	principal.setdesplazamiento(0, 0);
	//
	//MENU OPCIONES
	opciones.addFrase("OPCIONES");
	opciones.addFrase("OPCIONES");
	opciones.addFrase("OPCIONES");
	opciones.setdesplazamiento(-4, -0.8f);
	//
	//MENU INICIO
	Minicio.addFrase("IVOLVER");
	Minicio.addFrase("IOPCIONES");
	Minicio.addFrase("ISALIR");
	Minicio.setdesplazamiento(-4, -0.8f);
	//
	//MENU JUEGO
	Mjuego.addFrase("JVOLVER");
	Mjuego.addFrase("IrInicio");
	Mjuego.addFrase("JOPCIONES");
	Mjuego.addFrase("JSALIR");
	Mjuego.setdesplazamiento(-4, -0.8f);
	//
	bruja.addFrase("armas/lanza.txt");
	bruja.addFrase("armas/garrote.txt");
	bruja.addFrase("armas/espada.txt");
	bruja.addFrase("armas/alabarda.txt");

}

void Maquina_Estados::SpecialKey(unsigned char key)
{
	switch (estado)
	{
	case GAME:
		if (key == 'ESC')
		{
			estado = MENU;
		}
		break;
	}
}

void Maquina_Estados::tecla(unsigned char key)
{
	switch (estado)
	{
	case START:
		switch (key) {
		case ' ':
			switch (principal.getSelec()) {
			case 0:
				inicio.inicializa();
				estado = INICIO;
				break;
			case 1:
				estado = OPCIONES;
				break;
			case 2:
				estado = INICIO; //debe cerar el juego
				break;
			}
			break;
		case 's':
			principal.subir();
			break;
		case 'w':
			principal.bajar();
			break;
		}
		break;

	case INICIO:
		inicio.tecla(key);
		if (key == 27)
			estado = INICIO;
		if (key == ' ') {
			switch (inicio.triggers())
			{
			case 1:
				estado = HERRERO;
				break;
			case 2:
				estado = MAGO;
				break;
			case 3:
				estado = BRUJA;
				break;
			case 4:
				mundo.inicializa();
				estado = GAME;
				break;
			}
		}
		break;

	case BRUJA:
		switch (key) {
		case 's':
			bruja.subir();
			break;
		case 'w':
			bruja.bajar();
			break;
		case 27:
			estado = INICIO;
		}
		break;

	case HERRERO:
		switch (key) {
		case 's':
			herrero.subir();
			break;
		case 'w':
			herrero.bajar();
			break;
		case 27:
			estado = INICIO;
		}
		break;

	case MAGO:
		switch (key) {
		case 's':
			mago.subir();
			break;
		case 'w':
			mago.bajar();
			break;
		case 27:
			estado = INICIO;
		}
		break;

	case OPCIONES:
		switch (key) {
		case ' ':
			switch (opciones.getSelec()) {
			case 0:
				estado = START;
				break;
			case 1:
			{HWND foregroundWindow = GetForegroundWindow();
			ShowWindow(foregroundWindow, SW_MAXIMIZE);
			}
			break;
			case 2:
			{HWND foregroundWindow = GetForegroundWindow();
			ShowWindow(foregroundWindow, SW_NORMAL);
			}
			break;
			case 3:
			{
				exit(0);
			}

			break;
			}

			break;
		case 's':
			opciones.subir();
			ETSIDI::play("sonido/menu.wav");
			break;
		case 'w':
			principal.bajar();
			ETSIDI::play("sonido/menu.wav");
			break;
		}
		break;
		
	case MENUINICIO:
		switch (key) {
		case ' ':
			switch (Minicio.getSelec()) {
			case 0:
				estado = GAME; //seguirjugando
				break;
			case 1:
				estado = START; //volerinicio
				break;
			case 2:
				estado = OPCIONES;
				break;
			case 3:
				estado = INICIO; //debe cerar el juego
				break;
			}
			break;
		case 's':
			Minicio.subir();
			break;
		case 'w':
			Minicio.bajar();
			break;
		}
		break;
		

	case GAME:
		mundo.tecla(key);
		if (key == 27)
			estado = MENUJUEGO;
		break;

	case MENUJUEGO:
		switch (key) {
		case ' ':
			switch (Mjuego.getSelec()) {
			case 0:
				estado = GAME; //seguirjugando
				break;
			case 1:
				estado = START; //volerinicio
				break;
			case 2:
				estado = OPCIONES;
				break;
			case 3:
				estado = INICIO; //debe cerar el juego
				break;
			}
			break;
		case 's':
			Mjuego.subir();
			break;
		case 'w':
			Mjuego.bajar();
			break;
		}
		break;


	case GAME_OVER:
		if (key)
		{
			estado = START;
		}
		//pantalla fin del juego
		break;
	
	case ENDING:
		if (key)
		{
			//salimos a la pantalla principal 
		}
	}
}

void Maquina_Estados::teclaSuelta(unsigned char key)
{
	switch (estado)
	{
	case GAME:
		mundo.teclaSuelta(key);
		break;

	case INICIO:
		inicio.teclaSuelta(key);
		break;
	}
}

void Maquina_Estados::dibuja()
{
	gluLookAt(0, 0, 20,  // posicion del ojo
		0, 0, -10,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
	switch (estado)
	{
	case START:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(-9, -6);
		glTexCoord2d(1, 1); glVertex2f(9, -6);
		glTexCoord2d(1, 0); glVertex2f(9, 6);
		glTexCoord2d(0, 0); glVertex2f(-9, 6);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		principal.dibuja();

		break;
	case GAME:

		mundo.dibuja();

		break;
	case INICIO:

		inicio.dibuja();

		break;
	case BRUJA:
		bruja.dibuja(dinero);
		break;

	case HERRERO:
		herrero.dibuja(dinero);
		break;

	case MAGO:
		mago.dibuja(dinero);
		break;
	case OPCIONES:
		opciones.dibuja();
		break;
	case MENUINICIO:
		Minicio.dibuja();
		break;
	case MENUJUEGO:
		Mjuego.dibuja();
		break;
	case GAME_OVER:
		//OpenGL::Print("HAS MUERTO", 0, 0, 255, 255, 255);
		//OpenGL::Print("Pulsa cualquier tecla para continuar", 0, 20, 255, 255, 0);
		break;
	case ENDING:
		//OpenGL::Print("ENHORABUENA!", 0, 0, 255, 255, 255);
		//OpenGL::Print("Pulsa cualquier tecla para continuar", 0, 20, 255, 255, 0);
		break;
	}
}

void Maquina_Estados::mueve()
{
	switch (estado)
	{
	case GAME:
		mundo.mueve();
		break;
	case INICIO:
		inicio.mueve();
		break;
	}

}

