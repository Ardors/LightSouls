#pragma once
#include "Circulo.h"
class Proyectil :
    public Circulo
{
private:
    float masa;
    float dano;             //daño
    float tiempo;           //
    friend class Interaccion;
public:
    //Proyectil(float r = 1, float m = 1, float d = 1, float t = 0.025) :radio(r), masa(m), dano(d), tiempo(t) {}

    float getMasa() { return masa; }
    void setMasa(float m) { masa = m; }

    float getDano() { return dano; }
    void setDano(float d) { dano = d; }
    

};

