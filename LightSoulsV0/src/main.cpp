#include "Maquina_Estados.h"
#include "freeglut.h"
#include "ETSIDI.h"

//Mundo mundo;
Maquina_Estados maquina;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnKeyboardUp(unsigned char key, int x, int y); //cuando se suelta una tecla	
void OnPassiveMotionFunc(int x, int y);

int main(int argc,char* argv[])
{
	//ETSIDI::setJustificacion();

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1152,648);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("LightSouls");

	//habilitar luces y preparar camara ortogonal
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	glOrtho(-ANCHO/(RELACION*2), ANCHO / (RELACION * 2), -ALTO / (RELACION * 2), ALTO / (RELACION * 2), 0.1, 50);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	glutPassiveMotionFunc(OnPassiveMotionFunc);

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	maquina.inicializa();
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	maquina.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	maquina.tecla(key);
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	maquina.teclaSuelta(key);
	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion
	maquina.mueve();

	//no borrar estas lineas
	glutTimerFunc(10,OnTimer,0);
	glutPostRedisplay();
}

void OnPassiveMotionFunc(int x, int y)
{
//se ejcuta al mover el ratón
	maquina.mouse(x,y);
	glutPostRedisplay();
}
