#pragma once
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_TIEMPO 200 //5s a 40fps

struct Animacion
{

	void cargar(ifstream& fuente) 
	{
		fuente >> n;
		frame = n;
		for (int i = 0; i < n; i++) {
			fuente >> angulo1[i];
			fuente >> angulo2[i];
			fuente >> distancia1[i];
			fuente >> activa[i];
		}
	}

	bool pasarFrame(float* ang1, float* ang2, float* dis1, bool* act) //devuelve false si la animacion acaba
	{
		frame++;
		if (frame >= n)
			return false;
		*ang1 = angulo1[frame];
		*ang2 = angulo2[frame];
		*dis1 = distancia1[frame];
		*act = activa[frame];
		return true;
	}

	bool enProceso() {
		return frame < n;
	}

	void iniciar()
	{
		frame = -1;
	}
	
	int n; //duracion;
	int frame;
	float angulo1[MAX_TIEMPO];
	float angulo2[MAX_TIEMPO];
	float distancia1[MAX_TIEMPO];
	float activa[MAX_TIEMPO];
};
