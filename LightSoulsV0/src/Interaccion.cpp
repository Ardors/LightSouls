#include "Interaccion.h"

bool Interaccion::colision(Segmento s, Circulo c)
{
    //si la distancia entre un segmento y una esfera es menor que el radio de la esfera hay colisión (bool -> TRUE)
    return (s.DistanciaPunto(c.pos) < c.radio);
}

bool Interaccion::colision(Circulo c1, Circulo c2)
{
    //si la distancia entre esferas es menor que su radio hay colision (bool -> TRUE)
    return ((c2.pos - c1.pos).modulo() < (c1.radio + c2.radio));
}



