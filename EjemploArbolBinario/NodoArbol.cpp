
#include "NodoArbol.h"
#include <iostream>

using namespace std;

NodoArbol::NodoArbol() :  nombre(nullptr), hijoDerecho(nullptr), hijoIzquierdo(nullptr)
{}

NodoArbol::NodoArbol(const char* _nombre, NodoArbol* _hDerecho, NodoArbol* _hIzquierdo)
{
	setNombre(_nombre);
	setHijoDerecho(_hDerecho);
	setHijoIzquierdo(_hIzquierdo);
}

void NodoArbol::setNombre(const char* _nombre) 
{
	//Reservar el espacio de memoria con la longitud de la cadena
	nombre = new char[strlen(_nombre)];
	strcpy_s(nombre, strlen(_nombre) + 1, _nombre);
}

void NodoArbol::setHijoDerecho(NodoArbol* _hDerecho) 
{
	this->hijoDerecho = _hDerecho;
}

void NodoArbol::setHijoIzquierdo(NodoArbol* _hIzquierdo) 
{
	this->hijoIzquierdo = _hIzquierdo;
}

char* NodoArbol::getNombre() 
{
	return this->nombre;
}

NodoArbol* NodoArbol::getHijoDerecho() 
{
	return this->hijoDerecho;
}

NodoArbol* NodoArbol::getHijoIzquierdo() 
{
	return this->hijoIzquierdo;
}