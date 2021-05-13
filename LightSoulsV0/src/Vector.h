#pragma once
class Vector
{
public:
	Vector();
	Vector(float x, float y) :x(x), y(y) {};
	virtual ~Vector();
	float x;
	float y;

	float modulo();
	float argumento();

	//sobrecarga de operadores
	Vector operator+(Vector);
	Vector operator-(Vector);
	Vector operator*(float);										//prodcuto por un escalar de un vector
	float operator *(Vector v){return x * v.x + y * v.y;}			//producto escalar de dos vectores

	Vector unitario();

};

