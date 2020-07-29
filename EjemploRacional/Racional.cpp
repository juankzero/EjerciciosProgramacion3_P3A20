
#include "Racional.h"
#include <iostream>

using std::cout;

//implementacion de constructores de clase Racional

// :: operador de resolucion de ambito

Racional::Racional(void) : numerador(-1), denominador(-1)
{}

Racional::Racional(int _numerador, int _denominador) 
{
	setNumerador(_numerador);
	setDenominador(_denominador);
}

void Racional::setNumerador(int _numerador) 
{
	this->numerador = _numerador;
}

void Racional::setDenominador(int _denominador) 
{
	if (_denominador == 0)
	{
		cout << "Imposible asignar valor a variable Denominador\n";
		this->denominador = 1;
		return;
	}

	this->denominador = _denominador;
}

void Racional::imprimirDecimal(void) 
{
	if (this->numerador == 0 && this->denominador == 0)
	{
		cout << "Resultado no definido\n";
		return;
	}
	else if (this->denominador == 0)
	{
		cout << "No se puede dividir por cero\n";
		return;
	}

	cout << "Formal Decimal { " << float(this->numerador) / float(this->denominador) << " }\n";

}

void Racional::imprimirRacional(void) 
{
	if (this->numerador == 0 && this->denominador == 0)
	{
		cout << "Resultado no definido\n";
		return;
	}
	else if (this->denominador == 0)
	{
		cout << "No se puede dividir por cero\n";
		return;
	}

	cout << "Forma Racional { " << this->numerador << "/" << this->denominador << " }\n";
}