
#include "Empleado.h"

#include <iostream>

using std::cout;

Empleado::Empleado()  : codigo(-1), salario(0), departamento("ND"), estado(true), Persona()
{
	cout << "... Se construyo Empleado ...\n";
}

Empleado::Empleado(string _nombre, int _edad, char _genero, string _estadoCivil, int _codigo,
	float _salario, string _Departamento) : codigo(_codigo), salario(_salario),
	departamento(_Departamento), estado(true), Persona(_nombre, _edad, _genero, _estadoCivil)
{
	cout << "... Se construyo Empleado ...\n";
}

Empleado::~Empleado() 
{
	cout << "... Se destruyo Empleado ...\n";
}

void Empleado::setCodigo(int _codigo) 
{
	this->codigo = _codigo;
}

void Empleado::setSalario(float _salario) 
{
	this->salario = _salario;
}

void Empleado::setDepartamento(string _departamento) 
{
	this->departamento = _departamento;
}

void Empleado::setEstado(bool _estado) 
{
	this->estado = _estado;
}

int Empleado::getCodigo() 
{
	return this->codigo;
}

float Empleado::getSalario() 
{
	return this->salario;
}

string Empleado::getDepartamento() 
{
	return this->departamento;
}

bool Empleado::getEstado() 
{
	return this->estado;
}

void Empleado::imprimirEmpleado()
{
	if (estado)
		cout << "Empleado { codigo: " << getCodigo() << ", nombre: " << getNombre() << ", edad: "
		<< getEdad() << ", estadoCivil: " << getEstadoCivil() << ", genero: " << getGenero()
		<< ", departamento: " << getDepartamento() << ", salario: " << getSalario() << " }\n";
}