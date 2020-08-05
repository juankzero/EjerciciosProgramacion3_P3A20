#pragma once

#ifndef ENTERO_GRANDE_H
#define ENTERO_GRANDE_H

#include <iostream>

#define LIMITE 30

class EnteroGrande 
{
	//salida de flujo de datos --> cout (<<)
	//insercion/entrada de flujo de datos --> cin (>>)
	
	friend std::ostream& operator<<(std::ostream&, const EnteroGrande&);
	friend std::istream& operator>>(std::istream&, EnteroGrande&);



private:
	int* iValor; //arreglo dinamico
	char* cValor;

public:
	EnteroGrande(void);

};

#endif // !ENTERO_GRANDE_H
