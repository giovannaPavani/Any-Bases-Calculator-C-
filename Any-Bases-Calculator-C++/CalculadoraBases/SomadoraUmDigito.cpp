#include "SomadoraUmDigito.h"
#include <string>
#include <stdlib.h>
#include <cctype>

SomadoraUmDigito::SomadoraUmDigito(Digito dig)
{
    if (dig.getValorChar() == 'ç')
        digito = Digito(-1, dig.getBase());
    else
        digito = dig;

    excedente = 0;
}

SomadoraUmDigito::SomadoraUmDigito()
{
    digito = Digito('0', 10);
}

int SomadoraUmDigito::SomarDigito(Digito somar, int exd)
{
    int excedente = 0;
    int aSomar = somar.getValorInt();
    int base = digito.getBase();

    int val = digito.getValorInt() + aSomar + exd;

    if (val >= base)
    {
        digito.setValor(val % base); // parte da direita
        excedente = (val - digito.getValorInt()) / base; // parte da esquerda
    }
    else
    {
        digito.setValor(val);
        excedente = 0;
    }

    return excedente;
}

Digito SomadoraUmDigito::getDigito()
{
    return digito;
}


string SomadoraUmDigito::toString() {
    string ret = "";
    ret[0] = digito.getValorChar();
    return ret;
}

