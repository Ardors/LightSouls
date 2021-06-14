#include "Maquina_Estados.h"
#include "ETSIDI.h"
#include "Menu.h"

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
				estado = GAME;
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
		/*if (key == 'h')
			estado = HERRERO;
			estado = BRUJA;
			estado = MAGO;*/
		inicio.tecla(key);
		if (key == 27)
			estado = MENUINICIO;
		break; 

	case OPCIONES:
		switch (key) {
		case ' ':
			switch (opciones.getSelec()) {
			case 0:
				estado = START;
				break;
			case 1:
				estado = GAME;
				break;
			case 2:
				estado = START; //debe cerar el juego
				break;
			}
			break;
		case 's':
			opciones.subir();
			break;
		case 'w':
			principal.bajar();
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
	switch (estado)
	{
	case START:
		gluLookAt(0, 0, 20,  // posicion del ojo
			0, 0, -10,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
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
	case OPCIONES:
		gluLookAt(0, 0, 20,  // posicion del ojo
			0, 0, -10,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
		opciones.dibuja();
		break;
	case MENUINICIO:
		gluLookAt(0, 0, 20,  // posicion del ojo
			0, 0, -10,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
		Minicio.dibuja();
		break;
	case MENUJUEGO:
		gluLookAt(0, 0, 20,  // posicion del ojo
			0, 0, -10,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
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

