#pragma once
#include "Circulo.h"
#include <time.h>
#include <math.h>

class Proyectil: public Circulo
{
private:
    float masa;
    float dano;                      //daño
    clock_t tiempo_creacion;         //registra el momento en que se crea el proyectil
    friend class Interaccion;
    float t_max;                     //tiempo tras el cual el proyectil desaparece
public:
    Proyectil(Vector posicion = { 0,0 }, float ang = 0);

    float getMasa() { return masa; }
    void setMasa(float m) { masa = m; }

    float getDano() { return dano; }
    void setDano(float d) { dano = d; }
    
    bool t_excedido();               //comprueba si se ha excedido el tiempo maximo del proyectil
};