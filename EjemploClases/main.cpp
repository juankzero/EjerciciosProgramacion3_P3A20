
#include <iostream>
#include <conio.h>

class Numero
{
private:
	int valor;

public:
	Numero(void) : valor(-1)
	{
		//valor = -1;
	}

	Numero(int _valor) 
	{
		setValor(_valor);
	}

	void setValor(int _valor) 
	{
		this->valor = _valor;
	}

	int getValor(void) 
	{
		return this->valor;
	}

	bool esPar(void) 
	{
		return valor % 2 == 0;
	}

	bool esPrimo(void) 
	{
		
		int contResiduos = 0;

		for (int i = 1; i <= valor; i++) 
		{
			if (valor % i == 0)
				contResiduos++;
		}

		if (contResiduos == 2)
			return true;

		return false;
	}

	bool esMultiplo(Numero valor2) 
	{

		int mayor = this->valor > valor2.getValor() ? this->valor : valor2.getValor();
		int menor = this->valor < valor2.getValor() ? this->valor : valor2.getValor();

		int residuo = mayor % menor;

		return residuo == 0;

	}

};

using std::cout;

int main() 
{

	Numero n1; //llamada al constructor sin parametros
	Numero n2(6);

	n1.setValor(3);

	cout << "n1: " << n1.getValor() << "\n";
	cout << "n2: " << n2.getValor() << "\n\n";

	cout << "n1 " << (n1.esPar() ? "es Par" : "no es Par") << "\n";
	cout << "n1 " << (n1.esPrimo() ? "es Primo" : "no es Primo") << "\n\n";

	cout << "n2 " << (n2.esPar() ? "es Par" : "no es Par") << "\n";
	cout << "n2 " << (n2.esPrimo() ? "es Primo" : "no es Primo") << "\n\n";

	cout << n1.getValor() << " y " << n2.getValor() << (n1.esMultiplo(n2) ? " son multiplos" : " no son multiplos") << "\n";




	_getch();
}