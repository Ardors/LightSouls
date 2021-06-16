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

bool Interaccion::colision_coliseo(Luchador& p, Coliseo c)
{
    float distancia = (p.pos - c.pos).modulo();
    Vector direccion = (p.pos - c.pos).unitario();
    if (distancia > (c.getRadio()-p.getRadio())) {
        p.setPos((direccion.x * (c.radio - p.getRadio())), (direccion.y * (c.radio - p.getRadio())));
        return true;
    }
    return false;
}

bool Interaccion::colision_mercader(Luchador& p, Circulo m)
{
    float distancia = (p.pos - m.pos).modulo() ;
    Vector direccion = (p.pos - m.pos).unitario();
    if (distancia < (m.getRadio()+1.0)) {

        p.setPos((direccion.x * (m.radio+1.0) + m.pos.x), (direccion.y * (m.radio+1.0) + m.pos.y));
        return true;
    }
    return false;
}

bool Interaccion::tienda(Circulo c1, Circulo c2)
{

    return ((c2.pos - c1.pos).modulo() < (c1.radio + c2.radio + 1.5));

}

void Interaccion::ataque(Luchador& p1, Luchador& p2)
{
if (p1.arma.esActiva())
    if (colision(p1.arma, p2))
    {
        //int dano = (lista[i]->getDano()) * ((int)(lista[i]->getPeso() - 0.05 * e.getPeso()));
      
        p2.restarVida(10);
        std::cout << p2.getVida() << std::endl;
    }
}

void Interaccion::colision(ListaProyectiles& lp, ListaEnemigos& le)
{
    for (int i = 0; i < lp.getNumero(); i++)
    {
        for (int j = 0; j < le.getNumero(); j++)
        {
            if (colision(*(lp[i]), *(le[j])))
            {
                int dano = (lp[i]->getDano()) * ((int)(lp[i]->getPeso() - 0.05 * le[j]->getPeso()));
                le[j]->restarVida(dano);
                std::cout << le[j]->getVida() << std::endl;
                lp.eliminar(lp[i]);
                return;
            }
        }
    }
}

