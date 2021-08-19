#include <stdlib.h>
#include <iostream>
#include <cctype>
#include "SomadoraUmDigito.h"

using std::string;

#pragma once
class Soma
{
    public:
        Soma(int b);
        Soma();
        string SomaNumeros(string num1, string num2);
        int getTamanho();
        int tamanhoInt;
        int tamanhoFrac;

    private:
        void PreparaDigitosInt(string int1, string int2);
        void PreparaDigitosFrac(string frac1, string frac2);
        string getInteira(string num);
        string getFracionaria(string num);

        int base;
        string inte1, inte2, fraci1, fraci2;
        SomadoraUmDigito* inteira1;
        SomadoraUmDigito* inteira2;
        SomadoraUmDigito* fracionaria1;
        SomadoraUmDigito* fracionaria2;
};

