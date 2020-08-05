
#include "EnteroGrande.h"

EnteroGrande::EnteroGrande(void) 
{
	iValor = new int[LIMITE];
	cValor = new char[LIMITE];

	for(int i = 0; i < LIMITE; i++)
	{
		iValor[i] = 0;
		cValor[i] = 'a';
	}
}

std::istream& operator>>(std::istream& in, EnteroGrande& _entero) 
{
	in >> _entero.cValor;

	int longitud = strlen(_entero.cValor);
	int posicion = LIMITE - 1;

	for (int i = longitud - 1; i >=0 ; i--) 
	{
		switch (_entero.cValor[i]) 
		{
			case '0':
				_entero.iValor[posicion--] = 0;
				break;
			case '1':
				_entero.iValor[posicion--] = 1;
				break;
			case '2':
				_entero.iValor[posicion--] = 2;
				break;
			case '3':
				_entero.iValor[posicion--] = 3;
				break;
			case '4':
				_entero.iValor[posicion--] = 4;
				break;
			case '5':
				_entero.iValor[posicion--] = 5;
				break;
			case '6':
				_entero.iValor[posicion--] = 6;
				break;
			case '7':
				_entero.iValor[posicion--] = 7;
				break;
			case '8':
				_entero.iValor[posicion--] = 8;
				break;
			case '9':
				_entero.iValor[posicion--] = 9;
				break;
		}

	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const EnteroGrande& _entero) 
{
	out << "{ ";
	for (int i = 0; i < strlen(_entero.cValor); i++) 
	{
		out << _entero.iValor[LIMITE - strlen(_entero.cValor) + i];
	}
	out << " }\n";

	return out;

}