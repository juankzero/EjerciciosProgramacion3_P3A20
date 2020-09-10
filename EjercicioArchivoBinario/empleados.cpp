#include <fstream>
#include <iostream>

#include "empleados.h"

using namespace std;

void registroEmpleados() 
{
	// ios::app "append" -> guardar al final del archivo
	ofstream empleadosOut("empleados.bin", ios::out | ios::app | ios::binary);

	if (!empleadosOut)
	{
		cout << "Error al intentar abrir el archivo empleados.bin\n";
		return;
	}

	cout << "\n\n*** R E G I S T R O  D E  E M P L E A D O S ***\n\n";

	int opcion = 0;
	empleado nuevo;

	do 
	{
		cout << "Ingrese codigo: ";
		cin >> nuevo.codigo;

		cout << "Ingrese nombre: ";
		cin >> nuevo.nombre;

		cout << "Ingrese puesto: ";
		cin >> nuevo.puesto;

		cout << "Ingrese codigo de jefe (-1 si no tiene): ";
		cin >> nuevo.codigoJefe;

		nuevo.activo = 1; //true

		empleadosOut.write(reinterpret_cast<const char*>(&nuevo), sizeof(empleado));

		cout << "\nEmpleado guardado!\n";

		cout << "Desea agregar un nuevo empleado? (-1 para finalizar): ";
		cin >> opcion;

	} while (opcion != -1);

	empleadosOut.close();

}

void consultaEmpleados() 
{
	ifstream empleadosIn("empleados.bin", ios::in | ios::binary);

	if (!empleadosIn)
	{
		cout << "Error al intentar leer el archivo empleados.bin\n";
		return;
	}

	cout << "\n\n*** C O N S U L T A  D E  E M P L E A D O S ***\n\n";

	//posicionarse al inicio del archivo
	empleadosIn.seekg(0, ios::beg);

	empleado actual;

	empleadosIn.read(reinterpret_cast<char*>(&actual), sizeof(empleado));

	//eof -> end of file
	while (!empleadosIn.eof()) 
	{
		if (actual.activo)
		{
			cout << "Empleado { codigo: " << actual.codigo << ", nombre: " << actual.nombre
				<< ", puesto: " << actual.puesto << ", codigoJefe: " << actual.codigoJefe << " }\n";
		}

		empleadosIn.read(reinterpret_cast<char*>(&actual), sizeof(empleado));
	}

	empleadosIn.close();
}

void desactivarEmpleado(int _posicionEmpleado) 
{
	if (_posicionEmpleado > cantidadEmpleados())
	{
		cout << "Posicion de empleado incorrecta!\n";
		return;
	}

	//lectura/escritura en archivo binario
	fstream empleadosInOut("empleados.bin", ios::in | ios::out | ios::binary);

	if (!empleadosInOut)
	{
		cout << "Error al intentar abrir el archivo empleados.bin\n";
		return;
	}

	int posicionArchivo = (_posicionEmpleado - 1) * sizeof(empleado);
	empleadosInOut.seekg(posicionArchivo, ios::beg);

	empleado aModificar;

	empleadosInOut.read(reinterpret_cast<char*>(&aModificar), sizeof(empleado));

	aModificar.activo = 0; //false

	empleadosInOut.seekp(posicionArchivo, ios::beg);

	empleadosInOut.write(reinterpret_cast<const char*>(&aModificar), sizeof(empleado));

	cout << "Empleado desativado!\n";

	empleadosInOut.close();



}

int cantidadEmpleados() 
{
	fstream empleadosIn("empleados.bin", ios::in | ios::binary);

	if (!empleadosIn)
	{
		cout << "Error al intentar abrir el archivo empleados.bin\n";
		return -1;
	}

	//posicionarse al final del archivo
	empleadosIn.seekg(0, ios::end);

	//obtener en que byte me encuentro?

	int posicion = empleadosIn.tellg();

	//retorna la cantidad de empleados almacenados en archivo
	return posicion / sizeof(empleado);

}