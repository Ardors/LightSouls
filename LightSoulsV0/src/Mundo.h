#include "Circulo.h"
#include "Vector.h"
#include "Segmento.h"
#include "ListaProyectiles.h"

//ancho y alto de la ventana
#define ANCHO 1000
#define ALTO 700

class Mundo
{
public:
	~Mundo();
	void tecla(unsigned char key);
	void mouse(int x, int y);
	void inicializa();
	void mueve();
	void dibuja();

	Vector camara;
	
	Circulo c;
	ListaProyectiles proyectiles;
};
