#include "Maquina_Estados.h"
#include "ETSIDI.h"
#include "Menu.h"
#include <windows.h>
#include <stdlib.h>

Maquina_Estados::Maquina_Estados()
{
	ETSIDI::playMusica("sonido/inicio.wav", TRUE);

	estado = START;

	//MENU PRINCIPAL
	principal.addFrase("   JUGAR");
	principal.addFrase(" CREDITOS");
	principal.addFrase("CONTROLES");
	principal.addFrase("   SALIR");
	principal.setdesplazamiento(-10.5, 1);
	//
	//MENU INICIO
	Minicio.addFrase("VOLVER");
	Minicio.addFrase("TITULO");
	Minicio.addFrase(" SALIR");
	Minicio.setdesplazamiento(-3, 1.5);
	//
	//MENU JUEGO
	Mjuego.addFrase("VOLVER");
	Mjuego.addFrase(" INICIO");
	Mjuego.addFrase(" SALIR");
	Mjuego.setdesplazamiento(-3, 2);
	//
	herrero.addFrase("armas/espada.txt");
	herrero.addFrase("armas/lanza.txt");
	herrero.addFrase("armas/garrote.txt");
	herrero.addFrase("armas/alabarda.txt");
	herrero.cargardibujo();
	bruja.setdibujo("imagenes/bruja.png");

	//
	herrero.setdibujo("imagenes/herrero.png");
	//
	mago.setdibujo("imagenes/mago.png");

}

void Maquina_Estados::SpecialKey(unsigned char key)
{

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
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonido/palacioblanco.wav", TRUE);
				inicio.inicializa();
				estado = INICIO;
				break;
			case 1:
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonido/jardindelareina.wav", TRUE);
				estado = CREDITOS;
				break;
			case 2:
				estado = INSTRUCCIONES;
				break;
			case 3:
				exit(0);
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
		if (key == ' ') {
			switch (inicio.triggers())
			{
			case 1:
				estado = HERRERO;
				break;
				/*case 2:
					estado = MAGO;
					break;
				case 3:
					estado = BRUJA;
					break;*/
			case 4:
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonido/hollowknight.wav", TRUE);
				mundo.inicializa();
				estado = GAME;
				break;
			}
		}
		if (key == 27)
			estado = MENUINICIO;
		break;
/*
	case BRUJA:
		switch (key) {
		case 's':
			bruja.subir();
			break;
		case 'w':
			bruja.bajar();
			break;
		case ' ':
			inicio.c.cargar(bruja.comprar(dinero));
			break;
		case 27:
			estado = INICIO;
		}
		break;
*/
	case HERRERO:
		switch (key) {
		case 's':
			herrero.subir();
			break;
		case 'w':
			herrero.bajar();
			break;
		case ' ':
			inicio.c.cargar(herrero.comprar(dinero));
			mundo.c.cargar(herrero.comprar(dinero));

			break;
		case 27:
			estado = INICIO;
		}
		break;
/*
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
*/
	case INSTRUCCIONES:
		estado = START;
		break;
	case CREDITOS:
		ETSIDI::stopMusica();
		ETSIDI::playMusica("sonido/inicio.wav", TRUE);
		estado = START;
		break;
		
	case MENUINICIO:
		switch (key) {
		case ' ':
			switch (Minicio.getSelec()) {
			case 0:
				estado = INICIO; //seguirjugando
				break;
			case 1:
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonido/inicio.wav", TRUE);
				estado = START;
				break;
			case 2:
				exit(0);
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
				ETSIDI::stopMusica();
				ETSIDI::playMusica("sonido/palacioblanco.wav", TRUE);
				estado = INICIO; //volerinicio
				break;
			case 2:
				exit(0);//debe cerar el juego
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
		if (key == ' ')
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonido/inicio.wav", TRUE);
			estado = START;
		}
		//pantalla fin del juego
		break;
	
	case ENDING:
		if (key == ' ')
		{
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonido/inicio.wav", TRUE);
			estado = START;
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
		glTexCoord2d(0, 1); glVertex2f(-16, -12);
		glTexCoord2d(1, 1); glVertex2f(16, -12);
		glTexCoord2d(1, 0); glVertex2f(16, 12);
		glTexCoord2d(0, 0); glVertex2f(-16, 12);
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
	/*case BRUJA:
		bruja.dibuja(dinero);
		break;
*/
	case HERRERO:
		herrero.dibuja(dinero);
		break;
/*
	case MAGO:
		mago.dibuja(dinero);
		break;*/
	case INSTRUCCIONES:

		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::printxy2("ARRIBA: W", -8, 8);
		ETSIDI::printxy2("ABAJO: S", -8, 6);
		ETSIDI::printxy2("IZQUIERDA: A", -8, 4);
		ETSIDI::printxy2("DERECHA: D", -8, 2);
		ETSIDI::printxy2("ABRIR MENU: ESC", -8, 0);
		ETSIDI::printxy2("ACEPTAR: ESPACIO", -8, -2);
		ETSIDI::printxy2("ATAQUE 1: E", -8, -4);
		ETSIDI::printxy2("ATAQUE 2: Q", -8, -6);
		ETSIDI::printxy2("DISPARAR: ESPACIO", -8, -8);

		break;

	case CREDITOS:
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::printxy2("SILVIA SAETA ALVAREZ", -14, 4);
		ETSIDI::printxy2("FRANCISCO JOSE PADILLA DE AGUIAR", -14, 2);
		ETSIDI::printxy2("MIRIAM ORTEGA BUSTOS", -14, 0);
		ETSIDI::printxy2("ANGEL SANZ DIAZ", -14, -4);
		ETSIDI::printxy2("PABLO DANIEL MARTIN DE DOMINGO ", -14, -2);

		break;
	case MENUINICIO:
		Minicio.dibuja();
		break;
	case MENUJUEGO:
		Mjuego.dibuja();
		break;
	case GAME_OVER:
		mundo.dibuja();
		ETSIDI::printxy2("¡¡HAS MUERTO!!", -4, 4);
		break;
	case ENDING:
		mundo.dibuja();
		ETSIDI::printxy2("¡¡VICTORIA SOLDADO!!", -6, 4);
		break;
	}
}

void Maquina_Estados::mueve()
{
	switch (estado)
	{
	case GAME:
		mundo.mueve();
		if (mundo.c.muerto())
			estado = GAME_OVER;
		if (mundo.enemigos.generar_oleadas())
			estado = ENDING;
		break;
	case INICIO:
		inicio.mueve();
		break;
	}

}

