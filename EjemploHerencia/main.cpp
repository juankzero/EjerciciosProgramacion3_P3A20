
#include <conio.h>

#include "Empleado.h"
#include "Persona.h"
#include "AgenteVenta.h"

int main() 
{

	//Persona p1("Juan", 23, 'M', "Soltero");
	//Empleado e1("Maria", 25, 'F', "Soltero", 100, 1200, "Programador Junior");
	//Empleado e2("Jose", 21, 'M', "Casado", 101, 800, "Tecnico");

	/*Empleado lista[10];

	for (int i = 0; i < 10; i++) 
	{
		lista[i].imprimirEmpleado();
	}*/

	//ambito local (local scope)
	
	
	{
		Empleado e1("Maria", 25, 'F', "Soltero", 100, 1200, "Ventas");
		e1.imprimirEmpleado();

	}
	

	

	/*AgenteVenta av1(e1, 0.08, "Norte");

	av1.imprimirAgente();*/

	//e1.imprimirEmpleado();
	//e2.imprimirEmpleado();


	_getch();
}