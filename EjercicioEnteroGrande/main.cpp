
#include <iostream>
#include <conio.h>

#include "EnteroGrande.h"

using std::cout;
using std::cin;

int main() 
{

	EnteroGrande a;
	EnteroGrande b;

	cout << "Ingrese un numero entero maximo de " << LIMITE << " digitos: ";
	cin >> a;

	cout << "EnteroGrande ingresado: " << a;

	cout << "Ingrese otro numero entero maximo de " << LIMITE << " digitos: ";
	cin >> b;

	EnteroGrande c = a + b;

	cout << "La suma de a + b = " << c;

	_getch();

}