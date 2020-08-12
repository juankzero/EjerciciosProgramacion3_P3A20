
#include "TrianguloRectangulo.h"
#include <cmath>

#include <iostream>
using std::cout;

TrianguloRectangulo::TrianguloRectangulo() : base(0), altura(0), hipotenusa(0)
{}

TrianguloRectangulo::TrianguloRectangulo(int _base, int _altura) 
{
	setBase(_base);
	setAltura(_altura);
}

void TrianguloRectangulo::setBase(int _base) 
{
	this->base = _base;
}

void TrianguloRectangulo::setAltura(int _altura)
{
	this->altura = _altura;
}

int TrianguloRectangulo::getBase()
{
	return this->base;
}

int TrianguloRectangulo::getAltura() 
{
	return this->altura;
}

float TrianguloRectangulo::getHipotenusa() 
{
	return sqrt(pow(base, 2) + pow(altura, 2));
}

float TrianguloRectangulo::getArea() 
{
	return (this->base * this->altura) / 2;
}

float TrianguloRectangulo::getPerimetro() 
{
	return getBase() + getAltura() + getHipotenusa();
}

void TrianguloRectangulo::imprimirFigura() 
{
	cout << "TrianguloRectangulo { base: " << getBase() << ", altura: " << getAltura()
		<< ", hipotenusa: " << getHipotenusa() << ", area: " << getArea() << ", perimetro: "
		<< getPerimetro() << " }\n";
}

TipoFigura TrianguloRectangulo::getTipo() 
{
	return TipoFigura::tTrianguloRectangulo;
}