
#include "Byte.h"
#include <cmath>

Byte::Byte(void) 
{
	//inicializar el byte en 0
	for (int i = 0; i < 8; i++) 
	{
		this->bits[i] = 0;
	}
}

//10001101,  00001101
Byte::Byte(const char* _byte) 
{

	for (int i = 0; i < 8; i++)
	{
		this->bits[i] = _byte[i] - 48;
	}
}

//destructor de la clase
Byte::~Byte() 
{}

std::ostream& operator<<(std::ostream& out, const Byte& _byte) 
{
	// { 00001010 }
	out << "{ ";
	for (int i = 0; i < 8; i++) 
	{
		//cout << 1
		out << _byte.bits[i];
	}
	out << " }\n";

	return out;
}

Byte operator+(const Byte& _b1, const Byte& _b2) 
{
	Byte nuevo;
	int acarreo = 0;

	for (int i = 8 - 1; i >= 0; i--) 
	{
		int resultado = 0;

		if (acarreo == 0)
		{
			if (_b1.bits[i] == 0 && _b2.bits[i] == 0)
			{
				resultado = 0;
				acarreo = 0;
			}
			else if (_b1.bits[i] == 1 && _b2.bits[i] == 0 ||
				_b1.bits[i] == 0 && _b2.bits[i] == 1)
			{
				resultado = 1;
				acarreo = 0;
			}
			else if (_b1.bits[i] == 1 && _b2.bits[i] == 1)
			{
				resultado = 0;
				acarreo = 1;
			}
		}
		else //cuando acarreo sea 1
		{    //1
			//0010
			//0111
			//====
			//1001

			if (_b1.bits[i] == 0)
			{
				resultado = 1;
				acarreo = 0;
			}
			else
			{
				resultado = 0;
				acarreo = 1;
			}

			if (resultado == 0 && _b2.bits[i] == 0)
			{
				resultado = 0;
			}
			else if (resultado == 0 && _b2.bits[i] == 1)
			{
				resultado = 1;
			}
			else if (resultado == 1 && _b2.bits[i] == 0)
			{
				resultado = 1;
				acarreo = 0;
			}
			else if (resultado == 1 && _b2.bits[i] == 1)
			{
				resultado = 0;
				acarreo = 1;
			}

		} //fin del else princial acarreo

		nuevo.bits[i] = resultado;

	}// fin de ciclo for

	return nuevo;

}

int Byte::obtenerDecimal() 
{
	int resultado = 0;
	int exponente = 0;

	for ( int i = 8 - 1; i >= 0; i--, exponente++) 
	{

		if (this->bits[i] == 1)
			resultado += pow(2, exponente);

	}

	return resultado;

}