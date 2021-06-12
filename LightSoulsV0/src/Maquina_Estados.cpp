#include "Maquina_Estados.h"
#include "Menu.h"
#include "ETSIDI.h"

Maquina_Estados::Maquina_Estados()
{
	estado = START;
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

void Maquina_Estados::dibuja()
{
	switch (estado)
	{

	case START:
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

