#include "Vector.h"
#include "math.h"

Vector::Vector()
{
	x = y = 0;
}

Vector::~Vector(){}

float Vector::modulo()
{
	return (float)sqrt(x*x + y*y);
}

float Vector::argumento()
{
	return (float)atan2(y, x);
}

Vector Vector::operator+(Vector op)
{
    Vector resultado;
    resultado.x = x + op.x;
    resultado.y = y + op.y;
    return resultado;
}

Vector Vector::operator-(Vector v)
{
    Vector res;
    res.x = x - v.x;
    res.y = y - v.y;
    return res;
}

Vector Vector::operator*(float op)
{
	Vector escalar;
	escalar.x = x * op;
	escalar.y = y * op;
	return escalar;
}

