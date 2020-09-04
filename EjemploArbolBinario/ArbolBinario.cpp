
#include "ArbolBinario.h"
#include <iostream>

using namespace std;

ArbolBinario::ArbolBinario() : raiz(nullptr)
{}

void ArbolBinario::agregarElemento(const char* _nombre) 
{
	raiz = agregarRec(raiz, _nombre);
}

NodoArbol* ArbolBinario::agregarRec(NodoArbol* _raiz, const char* _nombre) 
{
	if (_raiz == nullptr)
	{
		NodoArbol* nuevo = new NodoArbol(_nombre, nullptr, nullptr);
		_raiz = nuevo;
		cout << "Nodo agregado!\n";
	}
	else if (strcmp(_nombre, _raiz->getNombre()) > 0)
	{
		_raiz->setHijoDerecho(agregarRec(_raiz->getHijoDerecho(), _nombre));
	}
	else if (strcmp(_nombre, _raiz->getNombre()) < 0)
	{
		_raiz->setHijoIzquierdo(agregarRec(_raiz->getHijoIzquierdo(), _nombre));
	}

	
	return _raiz;
}

void ArbolBinario::imprimir() 
{
	imprimirRec(raiz);
}

void ArbolBinario::imprimirRec(NodoArbol* _raiz) 
{
	if (_raiz == nullptr)
		return;

	cout << "[ " << _raiz->getNombre() << " ] ";
	imprimirRec(_raiz->getHijoIzquierdo());
	imprimirRec(_raiz->getHijoDerecho());
}
