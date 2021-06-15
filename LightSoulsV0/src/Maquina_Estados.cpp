#include "Maquina_Estados.h"
#include "Menu.h"
<<<<<<< Updated upstream
#include "ETSIDI.h"
=======
#include <windows.h>
#include <stdlib.h>


>>>>>>> Stashed changes

Maquina_Estados::Maquina_Estados()
{
	estado = START;
<<<<<<< Updated upstream
<<<<<<< Updated upstream
	principal.addFrase("JUGAR");
	principal.addFrase("OPCIONES");
	principal.addFrase("SALIR");
	principal.setdesplazamiento(-4, -0.8f);

	menutienda.addFrase("armas/lanza.txt");
	menutienda.addFrase("armas/garrote.txt");
	menutienda.addFrase("armas/espada.txt");
	menutienda.addFrase("armas/alabarda.txt");
	
	//
=======
	inicio.addFrase("INICIO");
	inicio.addFrase("opciones");
>>>>>>> Stashed changes
=======

	//MENU PRINCIPAL
	principal.addFrase("   JUGAR");
	principal.addFrase("  OPCIONES");
	principal.addFrase("   SALIR");
	principal.setdesplazamiento(0, 0);
	//
	//MENU OPCIONES
	opciones.addFrase("OPCIONES");
	opciones.addFrase("PANTALLA COMPLETA");
	opciones.addFrase("MODO VENTANA");
	opciones.addFrase("SALIR");
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
	herrero.addFrase("armas/espada.txt");
	herrero.addFrase("armas/lanza.txt");
	herrero.addFrase("armas/garrote.txt");
	herrero.addFrase("armas/alabarda.txt");
>>>>>>> Stashed changes
}

void Maquina_Estados::SpecialKey(unsigned char key)
{
	switch (estado)
	{
	case GAME:
		if (key == 'ESQ')
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
		
		if (key == 'e')
		{
			estado = GAME;
		}
		switch (key) {
<<<<<<< Updated upstream
		case 's':
			principal.subir();
			menutienda.subir();

		case 'w':
			principal.bajar();
			menutienda.bajar();
		case 'c':
			menutienda.comprar(dinero);
		}
		break;
		
=======
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
				estado = SALIR; //debe cerar el juego
				break;
			}
			break;
		case 's':
			principal.subir();
			ETSIDI::play("sonido/menu.wav");
			break;
		case 'w':
			principal.bajar();
			ETSIDI::play("sonido/menu.wav");
			break;

		}
		break;
	case SALIR:
	{
		exit(0);
	}
		break;
	case INICIO:
		inicio.tecla(key);
		if (key == 27)
			estado = MENUINICIO;
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
			ETSIDI::play("sonido/menu.wav");
			break;
		case 'w':
			Minicio.bajar();
			ETSIDI::play("sonido/menu.wav");
			break;
		}
		break;
	

>>>>>>> Stashed changes
	case GAME:
		mundo.tecla(key);
		

<<<<<<< Updated upstream
=======
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
			ETSIDI::play("sonido/menu.wav");
			break;
		case 'w':
			Mjuego.bajar();
			ETSIDI::play("sonido/menu.wav");
			break;
		}
>>>>>>> Stashed changes
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

void Maquina_Estados::dibuja()
{
	gluLookAt(0, 0, 20,  // posicion del ojo
		0, 0, -10,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
	switch (estado)
	{

	case START:
<<<<<<< Updated upstream
		gluLookAt(0, 0, 20,  // posicion del ojo
			0, 0, -10,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	
		
		
		

<<<<<<< Updated upstream
		//principal.dibuja();
		menutienda.dibuja();
=======
		

		inicio.dibuja();
		//opciones.dibuja();
>>>>>>> Stashed changes
		break;
	

	case GAME:
		//mundo.dibuja();
		gluLookAt(0, 0, 20,  // posicion del ojo
			0, 0, -10,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);
		break;
	case MENU:
		//presentamos el dosier de controles y explicaciones de habilidades
=======

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
>>>>>>> Stashed changes
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

void Maquina_Estados::inicializa()
{

}


