#pragma once

#ifndef  AGENTEVENTA_H
#define AGENTEVENTA_H

#include "Empleado.h"

class AgenteVenta : public Empleado
{
private:
	float comision;
	string zona;

public:
	AgenteVenta();
	AgenteVenta(Empleado, float, string);

	~AgenteVenta();

	void imprimirAgente();
};

#endif // ! AGENTEVENTA_H

