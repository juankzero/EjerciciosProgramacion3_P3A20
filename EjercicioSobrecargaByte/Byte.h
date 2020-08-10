#pragma once

#ifndef BYTE_H
#define BYTE_H

#include <iostream>

class Byte 
{
	//Definiciones de funciones no miembro de la clase
	friend std::ostream& operator<<(std::ostream&, const Byte&);
	friend Byte operator+(const Byte&, const Byte&);

private:
	int bits[8];

public:
	Byte(void);
	Byte(const char*);

	//destructor de clase
	~Byte();

	int obtenerDecimal();

	Byte operator~(void);

};

#endif
