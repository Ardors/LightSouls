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
	Vector operator+(Vector);
	Vector operator-(Vector);
	Vector operator*(float);
};

