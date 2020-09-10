
#include "EntidaBancaria.h"

#include <fstream>
#include <iostream>

using namespace std;

void EntidadBancaria::ingresarCliente() 
{
	//escritura en archivo
	ofstream clientesOut("clientes.dat", ios::app);

	if (!clientesOut)
	{
		cout << "Error al intentar abrir el archivo de clientes.dat\n";
		return;
	}

	int codigoCliente;
	char nombreCliente[30];
	char genero;
	char estado; //'A' activo | 'I' inactivo

	cout << "\n\n*** I N G R E S O  D E  C L I E N T E S ***\n\n";

	int cantidad;

	cout << "Defina cantidad de clientes a ingresar: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++)
	{
		cout << "Ingrese codigo de cliente: ";
		cin >> codigoCliente;

		cout << "Ingrese nombre: ";
		cin >> nombreCliente;

		cout << "Ingrese genero (F: Femenino | M: Masculino): ";
		cin >> genero;

		estado = 'A';

		clientesOut << codigoCliente << ' ' << nombreCliente << ' ' << genero << ' ' << estado << "\n";
	}

	clientesOut.close();
}

void EntidadBancaria::consultarClientes() 
{
	ifstream clientesIn("clientes.dat", ios::in);

	if (!clientesIn)
	{
		cout << "Error al intentar abrir el archivo clientes.dat\n";
		return;
	}

	int numeroCliente;
	char nombreCliente[30];
	char generoCliente;
	char estadoCliente;

	cout << "\n\n*** C O N S U L T A  D E  C L I E N T E S ***\n\n";

	while (clientesIn >> numeroCliente >> nombreCliente >> generoCliente >> estadoCliente) 
	{
		if (estadoCliente == 'A')
		{
			cout << numeroCliente << "\t" << nombreCliente << "\t" << generoCliente << "\n";
		}
	}

	clientesIn.close();

}

int EntidadBancaria::buscarCliente(const char* _nombre) 
{

	ifstream clientesIn("clientes.dat", ios::in);

	if (!clientesIn)
	{
		cout << "Error al intentar abrir el archivo clientes.dat\n";
		return -1;
	}

	int codigoCliente;
	char nombreCliente[30];
	char generoCliente;
	char estadoCliente;

	while (clientesIn >> codigoCliente >> nombreCliente >> generoCliente >> estadoCliente) 
	{
		if (estadoCliente == 'A')
		{
			if (strcmp(_nombre, nombreCliente) == 0)
			{
				clientesIn.close();
				return codigoCliente;
			}

		}
	}

	// no se encontro el cliente
	return -1;

}

void EntidadBancaria::ingresarCuenta() 
{

	ofstream cuentasOut("cuentas.dat", ios::app);

	if (!cuentasOut)
	{
		cout << "Error al intentar abrir el archivo cuentas.dat\n";
		return;
	}

	int codigoCliente = -1;
	char nombreCliente[30];
	char cuentaCliente[6];

	cout << "\n\n*** I N G R E S O  D E  C U E N T A ***\n\n";

	do
	{
		cout << "Ingrese nombre de cliente a crear cuenta: ";
		cin >> nombreCliente;

		codigoCliente = buscarCliente(nombreCliente);

	} while (codigoCliente == -1);

	cout << "Ingrese cuenta de cliente: ";
	cin >> cuentaCliente;

	cuentasOut << cuentaCliente << ' ' << codigoCliente << ' ' << 0 << "\n";

	cout << "Cuenta creada!\n";

	cuentasOut.close();

}

void EntidadBancaria::consultarCuentas() 
{
	ifstream cuentasIn("cuentas.dat", ios::in);

	if (!cuentasIn)
	{
		cout << "Error al intentar abrir el archivo cuentas.dat\n";
		return;
	}

	char cuentaCliente[6];
	int codigoCliente;
	int saldo;

	cout << "\n\n*** C O N S U L T A  D E  C U E N T A S ***\n\n";

	while (cuentasIn >> cuentaCliente >> codigoCliente >> saldo ) 
	{
		cout << cuentaCliente << "\t" << buscarClientePorCodigo(codigoCliente) << "\t"
			<< saldo << "\n";
	}

	cuentasIn.close();

}

char* EntidadBancaria::buscarClientePorCodigo(int _codigo) 
{
	ifstream clientesIn("clientes.dat", ios::in);

	if (!clientesIn)
	{
		cout << "Error al intentar abrir el archivo clientes.dat\n";
		return nullptr;
	}

	int codigoCliente;
	char nombreCliente[30];
	char generoCliente;
	char estadoCliente;
	char* nCliente;

	while (clientesIn >> codigoCliente >> nombreCliente >> generoCliente >> estadoCliente) 
	{
		if (estadoCliente == 'A')
		{
			if (codigoCliente == _codigo)
			{
				nCliente = new char[strlen(nombreCliente)];
				strcpy_s(nCliente, strlen(nombreCliente) + 1, nombreCliente);

				clientesIn.close();
				return nCliente;
			}
		}

	}

	// si no encuentra el codigo de cliente
	return nullptr;

}