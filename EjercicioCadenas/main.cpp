
#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>

using namespace std;

int main() 
{
	string nombre;
	string apellidos;

	nombre = "Mauricio";
	apellidos = "Lopez Najera";

	//concatenacion
	string nombreCompleto = nombre + ' ' +apellidos;
	//nombreCompleto += " Hola";

	cout << "Nombre { " << nombreCompleto << " }\n";
	cout << "Longitud de nombre: " << nombreCompleto.size() << "\n";

	//==================================

	char nombreC[20];
	char apellidosC[20];

	cout << "Escriba un nombre: ";
	cin >> nombreC;
	cin.ignore();
	cout << "Escriba sus apellidos: ";
	string apellidosS;
	getline(cin, apellidosS);
	//cin >> apellidosC;

	char* nombreCompletoC;
	
	nombreCompletoC = new char[strlen(nombreC) + strlen(apellidosS.c_str()) + 2];

	//int size = strlen(nombreC) + strlen(apellidosS.c_str()));

	strcpy_s(nombreCompletoC, strlen(nombreC) + 1, nombreC);
	strcat_s(nombreCompletoC, strlen(nombreC) + strlen(apellidosS.c_str()) + 1, apellidosS.c_str());
	//strcpy_s(nombreCompletoC, strlen(apellidosC) + 1, apellidosC);

	cout << "El nombre escrito { " << nombreCompletoC << " }\n";

	_getch();
}