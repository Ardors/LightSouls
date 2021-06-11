#include "Maquina_Estados.h"
#include "ETSIDI.h"

Maquina_Estados::Maquina_Estados()
{
	estado = START;
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
			estado = GAME;
		if (key == 's')
		{
			//salimos del juego
		}
		if (key == ' ')
			estado = INICIO;	
		break;

	case INICIO:
		inicio.tecla(key);
		break;

	case GAME:
		mundo.tecla(key);
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

	//aqui es donde hay que poner el codigo de dibujo

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
		break;


	case INICIO:
		inicio.dibuja();
		break;

	case GAME:
		mundo.dibuja();
		break;
	case MENU:
		//presentamos el dosier de controles y explicaciones de habilidades
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

