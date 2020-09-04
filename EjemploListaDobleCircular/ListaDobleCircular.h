#pragma once

#ifndef LISTA_DOBLE_CIRCULAR_H
#define LISTA_DOBLE_CIRCULAR_H

#include "Nodo.h"

class ListaDobleCircular
{
private:
	Nodo* primero;
	Nodo* ultimo;

public:
	ListaDobleCircular();

	bool estaVacia();
	void agregarElemento(int);
	void insertarElemento(int, int);

	void imprimir();
	void imprimirReversa();

	void eliminarElemento(int);
	void eliminarEnPosicion(int);
};


#endif // !LISTA_DOBLE_CIRCULAR_H
