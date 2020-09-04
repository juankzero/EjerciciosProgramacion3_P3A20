#pragma once

#ifndef NODO_H
#define NODO_H

class Nodo
{
private:
	int valor;
	Nodo* siguiente;
	Nodo* anterior;

public:
	Nodo();
	Nodo(int, Nodo*, Nodo*);

	void setValor(int);
	void setSiguiente(Nodo*);
	void setAnterior(Nodo*);

	int getValor();
	Nodo* getSiguiente();
	Nodo* getAnterior();
};

#endif // !NODO_H
