#pragma once

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona 
{
	//tipos de acceso: private, public, protected
protected:
	string nombre, estadoCivil;
	int edad;
	char genero;

public:

	//definicion de constructores de la clase
	Persona();
	Persona(string, int, char, string);

	//definicion del destructor de la clase
	~Persona();

	void setNombre(string);
	void setEdad(int);
	void setGenero(char);
	void setEstadoCivil(string);

	string getNombre();
	int getEdad();
	char getGenero();
	string getEstadoCivil();

};


#endif // !PERSONA_H
