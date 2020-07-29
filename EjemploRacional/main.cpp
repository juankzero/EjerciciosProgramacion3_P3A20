
#include <conio.h>
#include "Racional.h"

#include <iostream>
using std::cout;

int main() 
{
	Racional r1;
	Racional r2(1, 2);
	Racional r3(1, 3);
	Racional r4(12, 3);

	cout << "r1: \n";
	r1.imprimirDecimal();
	r1.imprimirRacional();

	cout << "\n";

	cout << "r2: \n";
	r2.imprimirDecimal();
	r2.imprimirRacional();

	cout << "\n";

	cout << "r3: \n";
	r3.imprimirDecimal();
	r3.imprimirRacional();

	cout << "\n";

	cout << "r4: \n";
	r4.imprimirDecimal();
	r4.imprimirRacional();

	_getch();
}