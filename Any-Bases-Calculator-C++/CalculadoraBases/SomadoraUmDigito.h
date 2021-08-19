#include <string>
#include "Digito.h"
using std::string;

#pragma once
class SomadoraUmDigito
{
    public:
        SomadoraUmDigito(Digito dig);
        SomadoraUmDigito();
        int SomarDigito(Digito dig, int exd);
        Digito getDigito();
        string toString();

    private:
        Digito digito;
        int excedente;
};
