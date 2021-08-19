#include <string>
#include "Digito.h"
using std::string;

#pragma once
class SubtradoraUmDigito
{
    public:
        SubtradoraUmDigito(Digito dig);
        SubtradoraUmDigito();
        int SubtrairDigito(Digito dig, int exd);
        Digito getDigito();
        string toString();

    private:
        Digito digito;
        int excedente;
};
