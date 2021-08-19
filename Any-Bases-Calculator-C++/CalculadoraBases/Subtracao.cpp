#include "Subtracao.h"
#include <string.h>
#include <stdlib.h>
#include "SubtradoraUmDigito.h"

Subtracao::Subtracao(int b)
{
    base = b;
    tamanhoInt = 0;
    tamanhoFrac = 0;
}

Subtracao::Subtracao()
{
}

int Subtracao::getTamanho()
{
    return tamanhoInt + tamanhoFrac + 1;
}

void Subtracao::PreparaDigitosInt(string int1, string int2)
{
    int tam1, tam2;
    tam1 = int1.size();
    tam2 = int2.size();

    if (tam1 > tam2)
        tamanhoInt = tam1;
    else
        tamanhoInt = tam2;

    inteira1 = (SubtradoraUmDigito*)malloc(sizeof(SubtradoraUmDigito) * tamanhoInt);
    inteira2 = (SubtradoraUmDigito*)malloc(sizeof(SubtradoraUmDigito) * tamanhoInt);

    for (int i = 0; i < tamanhoInt; i++)
    {
        inteira1[i] = SubtradoraUmDigito(Digito('0', base));
        inteira2[i] = SubtradoraUmDigito(Digito('0', base));
    }

    for (int i = tamanhoInt - tam1; i <= tamanhoInt; i++)
        inteira1[i] = SubtradoraUmDigito(Digito(int1[i + tam1 - tamanhoInt], base));

    for (int i = tamanhoInt - tam2; i <= tamanhoInt; i++)
        inteira2[i] = SubtradoraUmDigito(Digito(int2[i + tam2 - tamanhoInt], base));
}

void Subtracao::PreparaDigitosFrac(string frac1, string frac2)
{
    int tam1, tam2;
    tam1 = frac1.size();
    tam2 = frac2.size();

    if (tam1 > tam2)
        tamanhoFrac = tam1;
    else
        tamanhoFrac = tam2;

    fracionaria1 = (SubtradoraUmDigito*)malloc(sizeof(SubtradoraUmDigito) * tamanhoFrac);
    fracionaria2 = (SubtradoraUmDigito*)malloc(sizeof(SubtradoraUmDigito) * tamanhoFrac);

    for (int i = 0; i < tamanhoFrac; i++)
    {
        fracionaria1[i] = SubtradoraUmDigito(Digito('0', base));
        fracionaria2[i] = SubtradoraUmDigito(Digito('0', base));
    }

    for (int i = 0; i < tam1; i++)
        fracionaria1[i] = SubtradoraUmDigito(Digito(frac1[i], base));

    for (int i = 0; i < tam2; i++)
        fracionaria2[i] = SubtradoraUmDigito(Digito(frac2[i], base));
}


string Subtracao::SubtraiNumeros(string num1, string num2)
{
    inte1 = getInteira(num1);
    inte2 = getInteira(num2);
    fraci1 = getFracionaria(num1);
    fraci2 = getFracionaria(num2);

    PreparaDigitosInt(inte1, inte2);
    PreparaDigitosFrac(fraci1, fraci2);

    string resultado;
    int exd = 0;
    int x = tamanhoFrac + tamanhoInt;
    
    resultado.resize((x + 1), ' ');

    for (int i = tamanhoFrac - 1; i >= 0; i--, x--)
    {
        exd = fracionaria1[i].SubtrairDigito(fracionaria2[i].getDigito(), exd);
        resultado[x] = fracionaria1[i].getDigito().getValorChar();   
    }

    resultado[x] = ',';
    x--;

    for (int i = tamanhoInt - 1; i >= 0; i--, x--)
    {
        exd = inteira1[i].SubtrairDigito(inteira2[i].getDigito(), exd);
        resultado[x] = inteira1[i].getDigito().getValorChar();
    }

    return resultado;
}

string Subtracao::getInteira(string num)
{
    string ret = "";
    unsigned int tamanho = 0;

    for (int i = 0; i < num.size() && num[i] != ','; i++)
        tamanho++;

    ret.resize(tamanho);

    for (int i = 0; i < tamanho; i++)
        ret[i] = num[i];
    return ret;
}

string Subtracao::getFracionaria(string num)
{
    string ret = "";
    bool copiar = false;
    int posicaoVirgula = -1;
    unsigned int x = 0;
    unsigned int tamanho = 0;
    int i = 0;

    for (i = num.size() - 1; i > 0 && num[i] != ','; i--)
    {
        if (num[i - 1] == ',')
            posicaoVirgula = i - 1;

        tamanho++;
    }

    ret.resize(tamanho);

    ret = num.substr(posicaoVirgula + 1, num.size() - 1);

    if (posicaoVirgula < 0)
    {
        ret.resize(1);
        ret = "0";
    }


    return ret;
}
