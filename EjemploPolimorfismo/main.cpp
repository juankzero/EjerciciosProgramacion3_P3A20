
#include <conio.h>
#include "Rectangulo.h"
#include "TrianguloRectangulo.h"

int main() 
{

	Rectangulo r1(6, 2);
	TrianguloRectangulo tr1(6, 4);
	

	r1.imprimirFigura();
	tr1.imprimirFigura();


	_getch();
}