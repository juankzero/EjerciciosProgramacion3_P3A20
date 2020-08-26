
#include "Nodo.h"

Nodo::Nodo() : valor(-1), siguiente(nullptr)
{}

Nodo::Nodo(int _valor, Nodo* _siguiente) : valor(_valor), siguiente(_siguiente)
{}

void Nodo::setValor(int _valor) 
{
	this->valor = _valor;
}

void Nodo::setSiguiente(Nodo* _siguiente) 
{
	this->siguiente = _siguiente;
}

int Nodo::getValor() 
{
	return this->valor;
}

Nodo* Nodo::getSiguiente() 
{
	return this->siguiente;
}