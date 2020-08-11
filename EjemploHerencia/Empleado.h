#pragma once

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona 
{
protected:
	int codigo;
	float salario;
	string departamento;
	bool estado; //activo/inactivo

public:
	Empleado();
	Empleado(string, int, char, string, int, float, string);

	~Empleado();

	void setCodigo(int);
	void setSalario(float);
	void setDepartamento(string);
	void setEstado(bool);

	int getCodigo();
	float getSalario();
	string getDepartamento();
	bool getEstado();

	void imprimirEmpleado();

};

#endif // !EMPLEADO_H

