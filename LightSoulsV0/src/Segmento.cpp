#include "Segmento.h"

Segmento::Segmento(float p1_x, float p1_y, float p2_x, float p2_y)
{
    p1.x = p1_x;
    p1.y = p1_y;
    p2.x = p2_x;
    p2.y = p2_y;
}

float Segmento::DistanciaPunto(Vector punto, Vector * direccion) {      

        Vector u = (punto - p1);
        Vector v = (p2 - p1).unitario();
        float longitud = (p1 - p2).modulo();
        Vector dir;
        float valor = u * v;
        float distancia = 0;
        if (valor < 0)
            dir = u;
        else if (valor > longitud)
            dir = (punto - p2);
        else
            dir = u - v * valor;
        distancia = dir.modulo();
        if (direccion != 0)                                                 //si nos dan un vector…
            *direccion = dir.unitario();
        return distancia;

}

void Segmento::dibuja()
{
    glColor3ub(0, 255, 0);
    glBegin(GL_LINES);
    glVertex3d(p1.x, p1.y, 0);
    glVertex3d(p2.x, p2.y, 0);
    glEnd();
}


