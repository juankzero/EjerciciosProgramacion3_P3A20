#pragma once

#ifndef ENTIDAD_BANCARIA_H
#define ENTIDAD_BANCARIA_H

enum TipoMovimiento 
{
	Deposito, 
	Retiro
};

class EntidadBancaria
{
public:
	static void ingresarCliente();
	static void consultarClientes();

	static int buscarCliente(const char*);

	static void ingresarCuenta();
	static void consultarCuentas();

	static char* buscarClientePorCodigo(int);

	// se debe afectar el archivo de cuentas actualizando el saldo actual de la cuenta
	// agregar un nuevo movimiento al archivo movimientos.dat
	static void ingresarMovimiento(int _nCuenta, TipoMovimiento, int _valorMoneda);

};

#endif // !ENTIDAD_BANCARIA_H
