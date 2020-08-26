#pragma once


#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "Nodo.h"

class ListaSimple 
{
private:
	Nodo* primero;

public:
	ListaSimple();

	void agregarElemento(int);
	bool estaVacia();
	void imprimir();

};

#endif // !LISTA_SIMPLE_H
