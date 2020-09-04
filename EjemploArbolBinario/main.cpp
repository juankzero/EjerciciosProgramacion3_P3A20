
#include <conio.h>
#include "ArbolBinario.h"


int main() 
{
	ArbolBinario arbol;

	arbol.agregarElemento("John");
	arbol.agregarElemento("Omar");
	arbol.agregarElemento("Luis");
	arbol.agregarElemento("Elkyn");
	arbol.agregarElemento("Francis");
	arbol.agregarElemento("Rosa");

	arbol.imprimir();


	_getch();
}