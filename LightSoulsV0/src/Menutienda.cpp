#include "Menutienda.h"

#define ANCHO 51.2
#define ALTO 28.8

void Menutienda::dibuja()
{
	float celdax = ANCHO * 0.07;
	float celday = ALTO * 0.14;
	glPushMatrix();
	glTranslatef(-ANCHO*0.44, ALTO*0.27, 0);  //el primer desplazamiento para encuadrar todo el menu
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) { 
			if(selec==i*COLUMNAS+j) //reconocer cual esta seleccionado 
				glColor3ub(255, 255, 255);
			else
				glColor3ub(255, 0, 0);

			glBegin(GL_POLYGON);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, celday, 0.0f);
			glVertex3f(celdax, celday, 0.0f);
			glVertex3f(celdax, 0.0f, 0.0f);
			glEnd();
			glTranslatef(celdax*1.3, 0, 0); //al siguiente cuadrado el espacio es de uno
			
		}
		glTranslatef(-celdax * 1.3 * COLUMNAS, - celday * 1.3, 0); //para ir a la izquierda y bajar
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-ANCHO*0.44, -ALTO*0.41, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.0f, 0.0f, 0.0f);
	glVertex3f(-0.0f, ALTO*0.1, 0.0f);
	glVertex3f(ANCHO*0.527, ALTO*0.1, 0.0f);
	glVertex3f(ANCHO * 0.527, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(ANCHO * 0.15, ALTO * 0.09, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.0f, 0.0f, 0.0f);
	glVertex3f(-0.0f, ALTO * 0.32, 0.0f);
	glVertex3f(ANCHO * 0.28, ALTO * 0.32, 0.0f);
	glVertex3f(ANCHO * 0.28, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(ANCHO * 0.15, ALTO * -0.41, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.0f, 0.0f, 0.0f);
	glVertex3f(-0.0f, ALTO * 0.43, 0.0f);
	glVertex3f(ANCHO * 0.28, ALTO * 0.43, 0.0f);
	glVertex3f(ANCHO * 0.28, 0.0f, 0.0f);
	glEnd();
	glPopMatrix();
	
}

void Menutienda::subir()
{
	if (selec < COLUMNAS)
		selec += COLUMNAS* (FILAS - 1);
	else
		selec -= COLUMNAS;
}

void Menutienda::bajar()
{
	if (selec >= COLUMNAS*(FILAS-1))
		selec -= COLUMNAS * (FILAS - 1);
	else
		selec += COLUMNAS;
}

void Menutienda::dcha() //al hacer el modulo tienen el mismo resto q es 3 (si son numeros equidistantes)
{
	if (selec % COLUMNAS == COLUMNAS-1)
		selec -= COLUMNAS - 1;
	else
		selec++;
}

void Menutienda::izqd() //al hacer el modulo tienen el mismo resto q es 3 (si son numeros equidistantes)
{
	if (selec % COLUMNAS == 0)
		selec += COLUMNAS - 1;
	else
		selec--;
}
