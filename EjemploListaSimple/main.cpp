
#include <conio.h>
#include "ListaSimple.h"

int main() 
{
	ListaSimple ls;

	ls.agregarElemento(5);
	ls.agregarElemento(3);
	ls.agregarElemento(1);
	ls.agregarElemento(7);
	ls.agregarElemento(4);

	ls.imprimir();

	ls.eliminar(4);
	ls.eliminar(3);

	ls.imprimir();

	ls.eliminar(5);

	ls.imprimir();

	_getch();
}