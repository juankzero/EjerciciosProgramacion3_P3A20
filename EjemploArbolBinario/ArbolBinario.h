#pragma once

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"

class ArbolBinario 
{
private:
	NodoArbol* raiz;
	NodoArbol* agregarRec(NodoArbol*, const char*);
	void imprimirRec(NodoArbol*);
public:
	ArbolBinario();

	void agregarElemento(const char*);
	void imprimir();
	
};

#endif