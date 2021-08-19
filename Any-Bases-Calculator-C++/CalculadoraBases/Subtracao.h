#include <stdlib.h>
#include <iostream>
#include <cctype>
#include "SubtradoraUmDigito.h"

using std::string;

#pragma once
class Subtracao {
    public:
        Subtracao(int b);
        Subtracao();
        string SubtraiNumeros(string num1, string num2);
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
        SubtradoraUmDigito* inteira1;
        SubtradoraUmDigito* inteira2;
        SubtradoraUmDigito* fracionaria1;
        SubtradoraUmDigito* fracionaria2;
};
