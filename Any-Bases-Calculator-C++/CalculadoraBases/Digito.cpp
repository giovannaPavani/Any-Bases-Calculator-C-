#include "Digito.h"
#include <cctype>

Digito::Digito(int v, int b)
{
	setValor(v);
	base = b;
}

Digito::Digito(char v, int b)
{
	setValor(v);
	base = b;
}

Digito::Digito() {}

void Digito::setValor(char v)
{
	valChar = v;

	int val;

	if (isalpha(v)) // letra
	{
		v = toupper(v);
		val = (v - 55);
	}
	// converte para int
	else
		val = v - '0';

	valInt = val;
}

void Digito::setValor(int v)
{
	valInt = v;

	char val;

	if (v > 9) // deu alguma letra
		val = (55 + v);
	else // número < 10 --> apenas converte para char
		val = v + '0';

	valChar = val;
}

int Digito::getValorInt()
{
	return valInt;
}

int Digito::getBase()
{
	return base;
}

char Digito::getValorChar()
{
	return valChar;
}