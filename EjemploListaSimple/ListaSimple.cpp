
#include "ListaSimple.h"

#include <iostream>
using std::cout;

ListaSimple::ListaSimple() : primero(nullptr)
{}

bool ListaSimple::estaVacia() 
{
	return primero == nullptr;
}

void ListaSimple::agregarElemento(int _valor) 
{
	Nodo* nuevo = new Nodo(_valor, nullptr);

	if (estaVacia())
	{
		primero = nuevo;
	}
	else
	{
		Nodo* actual = primero;

		while (actual->getSiguiente() != nullptr) 
		{
			actual = actual->getSiguiente();
		}

		actual->setSiguiente(nuevo);
	}

	cout << "Nodo agregado!\n";

}