
#include <iostream>
#include "Persona.h"

using std::cout;

Persona::Persona() : nombre("ND"), edad(-1), genero('I'), estadoCivil("ND")
{
	cout << "... Se construyo Persona ...\n";
}

Persona::Persona(string _nombre, int _edad, char _genero, string _estadoCivil) :
	nombre(_nombre), edad(_edad), genero(_genero), estadoCivil(_estadoCivil)
{
	cout << "... Se construyo Persona ...\n";
}

Persona::~Persona() 
{
	cout << "... Se destruyo Persona ...\n";
}

void Persona::setNombre(string _nombre) 
{
	this->nombre = _nombre;
}

void Persona::setEdad(int _edad) 
{
	this->edad = _edad;
}

void Persona::setGenero(char _genero) 
{
	this->genero = _genero;
}

void Persona::setEstadoCivil(string _estadoCivil) 
{
	this->estadoCivil = _estadoCivil;
}

string Persona::getNombre() 
{
	return this->nombre;
}

int Persona::getEdad() 
{
	return this->edad;
}

char Persona::getGenero() 
{
	return this->genero;
}

string Persona::getEstadoCivil() 
{
	return this->estadoCivil;
}