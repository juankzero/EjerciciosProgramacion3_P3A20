
#include "Rectangulo.h"
#include <iostream>

using std::cout;

Rectangulo::Rectangulo() : base(0), altura(0)
{}

Rectangulo::Rectangulo(int _base, int _altura) : base(_base), altura(_altura)
{
	/*setBase(_base);
	setAltura(_altura);*/
}

void Rectangulo::setBase(int _base)
{
	this->base = _base;
}

void Rectangulo::setAltura(int _altura) 
{
	this->altura = _altura;
}

int Rectangulo::getBase() 
{
	return this->base;
}

int Rectangulo::getAltura() 
{
	return this->altura;
}

float Rectangulo::getArea() 
{
	return this->base * this->altura;
}

float Rectangulo::getPerimetro() 
{
	return 2 * (this->base + this->altura);
}

void Rectangulo::imprimirFigura() 
{
	cout << "Rectangulo: { base: " << getBase() << ", altura: " << getAltura()
		<< ", area: " << getArea() << ", perimetro: " << getPerimetro() << " }\n";
}

TipoFigura Rectangulo::getTipo() 
{
	return TipoFigura::tRectangulo;
}