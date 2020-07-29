#pragma once

#ifndef RACIONAL_H
#define RACIONAL_H

class Racional 
{
private:
	int numerador, denominador;

public:
	Racional(void);
	Racional(int, int);

	void imprimirRacional(void);
	void imprimirDecimal(void);
	
	void setNumerador(int);
	void setDenominador(int);
};

#endif