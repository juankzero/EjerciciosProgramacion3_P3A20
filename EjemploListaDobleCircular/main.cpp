
#include <conio.h>
#include "ListaDobleCircular.h"


int main() 
{
	ListaDobleCircular ls;

	ls.agregarElemento(7);
	ls.agregarElemento(5);
	ls.agregarElemento(2);
	ls.agregarElemento(9);
	ls.agregarElemento(3);

	ls.imprimir();
	ls.imprimirReversa();

	ls.eliminarElemento(7);
	ls.eliminarElemento(9);
	ls.eliminarElemento(3);

	ls.imprimir();
	ls.imprimirReversa();

	_getch();
}