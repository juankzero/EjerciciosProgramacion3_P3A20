#pragma once

#ifndef NODOARBOL_H
#define NODOARBOL_H

class NodoArbol 
{
private:
	char* nombre;
	NodoArbol* hijoDerecho;
	NodoArbol* hijoIzquierdo;

public:
	NodoArbol();
	NodoArbol(const char*, NodoArbol*, NodoArbol*);

	void setNombre(const char*);
	void setHijoDerecho(NodoArbol*);
	void setHijoIzquierdo(NodoArbol*);

	char* getNombre();
	NodoArbol* getHijoDerecho();
	NodoArbol* getHijoIzquierdo();

};

#endif // !NODOARBOL_H
