
#include "ListaDobleCircular.h"

#include <iostream>

using std::cout;

ListaDobleCircular::ListaDobleCircular() : primero(nullptr), ultimo(nullptr)
{}

bool ListaDobleCircular::estaVacia() 
{
	return primero == nullptr;
}

void ListaDobleCircular::agregarElemento(int _valor) 
{

	Nodo* nuevo = new Nodo(_valor, nullptr, nullptr);

	if (estaVacia())
	{

		primero = ultimo = nuevo;

		ultimo->setSiguiente(primero);
		primero->setAnterior(ultimo);

	}
	else
	{

		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);

		ultimo = nuevo;

		ultimo->setSiguiente(primero);
		primero->setAnterior(ultimo);

	}

	cout << "Nodo agregado!\n";

}

void ListaDobleCircular::imprimir() 
{
	if (estaVacia())
		return;

	Nodo* actual = primero;

	do 
	{
		cout << "[ " << actual->getValor() << " ] ";
		actual = actual->getSiguiente();

	} while ( actual != primero );

	cout << "\n";
}

void ListaDobleCircular::imprimirReversa() 
{
	if (estaVacia())
		return;

	Nodo* actual = ultimo;

	do 
	{
		cout << "[ " << actual->getValor() << " ] ";
		actual = actual->getAnterior();
	} while (actual != ultimo);

	cout << "\n";
}

void ListaDobleCircular::eliminarElemento(int _valor)
{
	if (estaVacia())
		return;

	Nodo* actual = primero;

	do 
	{
		if (actual->getValor() == _valor)
		{
			if (actual == primero)
			{
				primero = primero->getSiguiente();
				primero->setAnterior(ultimo);
				ultimo->setSiguiente(primero);

			}
			else if (actual == ultimo)
			{
				ultimo = ultimo->getAnterior();
				ultimo->setSiguiente(primero);
				primero->setAnterior(ultimo);

			}
			else //eliminacion en medio de la lista
			{
				actual->getAnterior()->setSiguiente(actual->getSiguiente());
				actual->getSiguiente()->setAnterior(actual->getAnterior());

			}
			delete actual;
			cout << "Nodo Eliminado!\n";
			return;
		}
		else
			actual = actual->getSiguiente();


	} while (actual != primero);


}