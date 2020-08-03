
#include "Byte.h"

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