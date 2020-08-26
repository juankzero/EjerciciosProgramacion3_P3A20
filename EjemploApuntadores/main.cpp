
#include <iostream>
#include <conio.h>

using std::cout;

int cuboPorValor(int);
void cuboPorReferencia(int*);

int main() 
{
	/*
	int y = 5;
	int* yPtr = nullptr;

	// & = Devuelve la Dir. de Memoria de una variable

	yPtr = &y;

	cout << "Valor de y: " << y << "\n";
	cout << "Direccion de memoria de y: " << &y << "\n";
	cout << "Direccion de memoria de yPtr: " << yPtr << "\n";

	cout << "El valor depositado en direccion de memoria yPtr: " << *yPtr << "\n";

	y = 12;

	cout << "El valor depositado en direccion de memoria yPtr: " << *yPtr << "\n";

	*yPtr = 8;

	cout << "Valor de y: " << y << "\n";
	*/

	int numero = 5;

	/*cout << "El valor de numero es: " << numero << "\n";
	cout << "Direccion de memoria de numero antes de llamada a funcion: " << &numero << "\n";
	numero = cuboPorValor(numero);
	cout << "Direccion de memoria de numero despues de llamada a funcion: " << &numero << "\n";
	cout << "El nuevo valor de numero es: " << numero << "\n";
	*/


	cuboPorReferencia(&numero);

	cout << "El valor de numero es: " << numero << "\n";


	float notas[5];

	notas[0] = 25;
	notas[1] = 92;
	notas[2] = 83;
	notas[3] = 72;
	notas[4] = 61;

	for (int i = 0; i < 5; i++) 
	{
		cout << "Direccion de memoria en arreglo con indice [ " << i << "]: " << &notas[i] << "\n";
	}


	_getch();
}

int cuboPorValor(int numero) 
{
	cout << "Direccion de memoria de numero en funcion: " << &numero << "\n";

	return numero * numero * numero;
}

void cuboPorReferencia(int* numeroPtr) 
{

	*numeroPtr = *numeroPtr * *numeroPtr * *numeroPtr;

}