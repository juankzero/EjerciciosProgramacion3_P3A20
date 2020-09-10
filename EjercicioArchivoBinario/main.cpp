
#include <conio.h>
#include "empleados.h"
#include <iostream>

using std::cout;

int main() 
{
	//registroEmpleados();

	consultaEmpleados();
	cout << "Cantidad de empleados: " << cantidadEmpleados() << "\n";

	desactivarEmpleado(3);
	desactivarEmpleado(1);

	consultaEmpleados();

	desactivarEmpleado(9);

	_getch();
}