#pragma once

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura2D.h"

class Rectangulo : public Figura2D
{
private:
	int base, altura;

public:
	Rectangulo(void);
	Rectangulo(int, int);

	void setBase(int);
	void setAltura(int);

	int getBase();
	int getAltura();

	float getArea();
	float getPerimetro();
	void imprimirFigura();
	TipoFigura getTipo();

};

#endif // !RECTANGULO_H
