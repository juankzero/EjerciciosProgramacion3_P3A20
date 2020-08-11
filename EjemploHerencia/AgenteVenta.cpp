
#include "AgenteVenta.h"

#include <iostream>

AgenteVenta::AgenteVenta() : comision(0), zona("ND"), Empleado()
{
	cout << "... Se construyo AgenteVenta ...\n";
}

AgenteVenta::AgenteVenta(Empleado e, float _comision, string _zona): comision(_comision), zona(_zona),
	Empleado(e.getNombre(), e.getEdad(), e.getGenero(), e.getEstadoCivil(), e.getCodigo(), e.getSalario(),
		e.getDepartamento())
{
	cout << "... Se construyo AgenteVenta ...\n";
}

AgenteVenta::~AgenteVenta() 
{
	cout << "... Se destruyo AgenteVenta ...\n";
}

void AgenteVenta::imprimirAgente() 
{
	this->imprimirEmpleado();
	cout << "AgenteVenta { comision: " << comision << ", zona: " << zona << " }\n";
}