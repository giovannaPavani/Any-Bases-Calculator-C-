#include "SubtradoraUmDigito.h"
#include <string>
#include <stdlib.h>
#include <cctype>

SubtradoraUmDigito::SubtradoraUmDigito(Digito dig)
{
    if (dig.getValorChar() == 'ç')
        digito = Digito(-1, dig.getBase());
    else
        digito = dig;
   
    excedente = 0;
}

SubtradoraUmDigito::SubtradoraUmDigito()
{
    digito = Digito('0', 10);
}

Digito SubtradoraUmDigito::getDigito() {
    return digito;
}

int SubtradoraUmDigito::SubtrairDigito(Digito dig, int exd)
{
    int excedente = 0;
    int aSubtrair = dig.getValorInt();
    int base = digito.getBase();

    int val = digito.getValorInt() - aSubtrair + exd;

    if (val < 0)
    {
        val = digito.getValorInt() + base - aSubtrair + exd;
        digito.setValor(val);
        excedente = -1;
    }
    else
    {
        digito.setValor(val);
        excedente = 0;
    }

    return excedente;
}

string SubtradoraUmDigito::toString() {
    string ret = "";
    ret[0] = digito.getValorChar();
    return ret;
}

