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

bool Interaccion::rebote(Luchador& p1, Luchador& p2)
{
    if (colision(p1, p2)){
		Vector direccion = (p1.pos - p2.pos);
        if (direccion.modulo() > 0)
            direccion = direccion * ((p1.radio + p2.radio - direccion.modulo()) / direccion.modulo());
        else
            direccion = *new Vector(0, p1.radio + p2.radio);
		p1.pos = p1.pos + direccion* ((p2.peso / (p1.peso + p2.peso)));
        p2.pos = p2.pos - direccion* ((p1.peso / (p1.peso + p2.peso)));
        return true;
    }
    return false;
}