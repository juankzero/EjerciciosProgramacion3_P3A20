#pragma once

#ifndef FIGURA2D_H
#define FIGURA2D_H

enum TipoFigura 
{
	tRectangulo, //0
	tTrianguloRectangulo, //1
	tCirculo //2
};

//definicion de clase abstracta
class Figura2D 
{
public:
	virtual float getArea() = 0;
	virtual float getPerimetro() = 0;
	virtual void imprimirFigura() = 0;
	virtual TipoFigura getTipo() = 0;
};

#endif