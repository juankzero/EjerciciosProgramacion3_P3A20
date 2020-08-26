#pragma once

#ifndef NODO_H
#define NODO_H

class Nodo 
{
private:
	int valor;
	Nodo* siguiente;

public:
	Nodo();
	Nodo(int, Nodo*);

	void setValor(int);
	void setSiguiente(Nodo*);

	int getValor();
	Nodo* getSiguiente();
};

#endif // !NODO_H
