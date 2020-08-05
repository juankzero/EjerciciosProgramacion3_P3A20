
#include <iostream>
#include <conio.h>

#include "EnteroGrande.h"

using std::cout;
using std::cin;

int main() 
{

	EnteroGrande a;

	cout << "Ingrese un numero entero maximo de " << LIMITE << " digitos: ";
	cin >> a;

	cout << "EnteroGrande ingresado: " << a;

	_getch();

}