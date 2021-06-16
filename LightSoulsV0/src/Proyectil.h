#pragma once
#include "Circulo.h"
#include <time.h>
#include <math.h>
#include "ETSIDI.h"

class Proyectil: public Circulo
{
private:
    float peso;
    float dano;                      //daño
    clock_t tiempo_creacion;         //registra el momento en que se crea el proyectil
    friend class Interaccion;
    float t_max;                     //tiempo tras el cual el proyectil desaparece

public:
    Proyectil(Vector posicion = { 0,0 }, float ang = 0, float radio = 0.5, int damage = 5, float peso = 10);

    float getPeso() { return peso; }
    void setPeso(float m) { peso = m; }

    float getDano() { return dano; }
    void setDano(float d) { dano = d; }
    
    bool t_excedido();               //comprueba si se ha excedido el tiempo maximo del proyectil
};