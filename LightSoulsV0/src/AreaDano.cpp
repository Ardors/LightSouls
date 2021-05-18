#include "AreaDano.h"
#include <stdio.h>

AreaDano::AreaDano()
{
	angulo = rand()%(361-0);
	dano = 0.0;
}

AreaDano::~AreaDano()
{
}