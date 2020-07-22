#include <iostream>
#include <conio.h>

#include <cstdlib>
#include <ctime>

//Definir los prototipos de funcion en programa
void juegoPrincipal(void);
bool esCorrecto(int, int);


int main() 
{
	//generacion de numero aleatorio
	srand(time(NULL));

	juegoPrincipal();

}

void juegoPrincipal(void) 
{
	int numeroIndicado;
	int numeroAdivinar;
	char respuesta;

	do 
	{
		numeroAdivinar = 1 + rand() % 1000;

		std::cout << "Tengo un numero entre 1 y 1000.\n"
			<< "Lo puedes adivinar?\n"
			<< "Ingresa tu primera opcion. " << std::endl << "? ";

		//console input
		std::cin >> numeroIndicado;

		while (!esCorrecto(numeroAdivinar, numeroIndicado))
			std::cin >> numeroIndicado;	

		std::cout << "Excelente! Has descubierto el numero generado!\n"
			<< "Deseas volver a jugar? (y o n) ";
		std::cin >> respuesta;

		std::cout << std::endl;

	} while ( respuesta == 'y' );

	_getch();

}

bool esCorrecto(int numeroAdivinar, int numeroIndicado) 
{
	if (numeroIndicado == numeroAdivinar)
		return true;

	if (numeroIndicado < numeroAdivinar)
		std::cout << "Muy bajo. Intentalo de nuevo.\n? ";
	else
		std::cout << "Muy alto. Intentalo de nuevo.\n? ";

	return false;
}

