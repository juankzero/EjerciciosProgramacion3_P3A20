#pragma once

#ifndef EMPLEADOS_H
#define EMPLEADOS_H

struct empleado 
{
	int codigo;			//4 bytes
	char nombre[30];	//30 bytes
	char puesto[15];	//15 bytes
	int codigoJefe;		//4 bytes
	bool activo;		//1 byte
}; // sizeof() = 54 bytes

void registroEmpleados();
void consultaEmpleados();
void desactivarEmpleado(int);
int cantidadEmpleados();

#endif