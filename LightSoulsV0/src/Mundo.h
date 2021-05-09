#include "Circulo.h"
#include "Vector.h"

//ancho y alto de la ventana
#define ANCHO 1000
#define ALTO 700

class Mundo
{
public: 
	void tecla(unsigned char key);
	void mouse(int x, int y);
	void inicializa();
	void mueve();
	void dibuja();

	Vector camara;

	Circulo c;
};
