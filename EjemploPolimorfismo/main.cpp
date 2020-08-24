
#include <conio.h>
#include "Rectangulo.h"
#include "TrianguloRectangulo.h"

#include <iostream>

using std::cout;

//prototipo de funcion
void imprimirFiguras2D(Figura2D*);

int main() 
{

	/*Rectangulo r1(6, 2);
	TrianguloRectangulo tr1(6, 4);
	

	r1.imprimirFigura();
	tr1.imprimirFigura();*/

	//Arreglo de objetos de tipo apuntador Figura2D
	//apuntador almacenar direccion de memoria 0x0002FE
	Figura2D* figuras[4];

	figuras[0] = new Rectangulo(12, 4);
	figuras[1] = new TrianguloRectangulo(6, 2);
	figuras[2] = new Rectangulo(9, 5);
	figuras[3] = new TrianguloRectangulo(5, 2);

	for (int  i = 0; i < 4; i++) 
	{
		imprimirFiguras2D(figuras[i]);
	}

	_getch();
}

void imprimirFiguras2D(Figura2D* figura)
{

	//instanceof
	if (figura->getTipo() == TipoFigura::tRectangulo)
	{
		Rectangulo* r1 = (Rectangulo*)figura;

		auto r2 = figura;

		r1->imprimirFigura();
		cout << "TipoFigura: " << r1->getTipo() << "\n";
	}
	else if (figura->getTipo() == TipoFigura::tTrianguloRectangulo)
	{
		((TrianguloRectangulo*)figura)->imprimirFigura();
		cout << "TipoFigura: " << ((TrianguloRectangulo*)figura)->getTipo() << "\n";
	}

}
