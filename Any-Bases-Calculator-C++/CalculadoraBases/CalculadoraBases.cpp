#include <iostream>
#include <string.h>
#include "Soma.h"
#include "Subtracao.h"
#include "SomadoraUmDigito.h"

using namespace std;

//DECLARACAO DE FUNCOES
bool verificar(string numero, unsigned int base, char operacao);
string verificarMaiorModulo(string numero1, string numero2);
char verificarSinal(string numero1, string numero2);
string getFracionaria(string num);
string getInteira(string num);

//DEFINICAO DE FUNCOES
bool verificar(string numero, unsigned int base, char operacao)
{
    int i;
    int tam = numero.size();

    if (operacao != '+' && operacao != '*' && operacao != '-' && operacao != '/')
    {
        cout << "A operação solicitada é invalida. Apenas + , - , *  e / são válidos.\n" << endl;
        return false;
    }


    if (base > 36 || base < 2) // verifica o tamanho da base
    {
        cout << "\nO numero inserido nao esta na base %d! Tente novamente.\n" << base;
        return false;
    }

    if (base <= 10) // se for menor que 10
    {
        for (i = 0; i < tam; i++)
        {
            if ((!isdigit(numero[i]) || (numero[i] - '0') >= base) && numero[i] != ',' && numero[i] != '-') // verifica se há dígitos maiores que a base digitiada
            {
                cout << "\nO numero inserido nao esta na base " << base << "! Tente novamente.\n" << endl;
                return false;
            }
        }
    }
    else //base > 10
    {
        for (i = 0; i < tam; i++)
        {
            if (isalpha(numero[i])) // verifica se é letra
            {
                char letra = toupper(numero[i]); // maiuscula
                int num = letra - 55; // converte para o valor numérico na base 10

                if (num >= base)
                {
                    cout << "\nO numero inserido nao esta na base %d! Tente novamente.\n" << endl;
                    return false;
                }
                numero[i] = letra; // salva
            }

            if (!isdigit(numero[i]) && !isalpha(numero[i]) && !(numero[i] == ',')) // verifica se n tem caracter especial (apenas número, letra e virgula)
            {
                cout << "\nO numero inserido nao esta na base %d! Tente novamente.\n" << endl;
                return false;
            }
        }
    }

    return true;
}

char verificarOperacao(string numero1, string numero2)
{
    if (numero1.at(0) == '-' && numero2.at(0) == '-') //tem q tirar o menos dos 2 numeros aqui
        return '+';

    if (numero1.at(0) != '-' && numero2.at(0) != '-')
        return '+';

    if ((numero1.at(0) == '-' && numero2.at(0) != '-') ||
        (numero1.at(0) != '-' && numero2.at(0) == '-')) // (-1 + 5) e (6 + -4) são subtrações
        return '-'; 

    return '+';
}


char verificarSinal(string numero1, string numero2)
{
    char neg1, neg2;
    neg1 = numero1[0];
    neg2 = numero2[0];

    if (neg1 == '-' && neg2 == '-') //tem q tirar o menos dos 2 numeros aqui
        return '-';
    if (neg1 != '-' && neg2 != '-')
        return '+';
    else {
        if (neg1 == '-') //tem q tirar o menos do numero1 aqui
        {

            if (verificarMaiorModulo(numero1, numero2) == numero1)
                return '-';
            else
                return '+';
        }
        if (neg1 != '-') //tem q tirar o menos do numero2 aqui
        {
            if (verificarMaiorModulo(numero1, numero2) == numero1)
                return '+';
            else
                return '-';
        }
    }

    
}

string verificarMaiorModulo(string numero1, string numero2)
{
    int tamInteiro1 = (getInteira(numero1)).size();
    int tamInteiro2 = (getInteira(numero2)).size();
    int digitoInteiro1, digitoInteiro2;
    int digitoFrac1, digitoFrac2;

    if (tamInteiro1 == tamInteiro2)
    {
        if (getInteira(numero1) == getInteira(numero2))
        {
            for (int i = 0; i < (getFracionaria(numero1)).size(); i++)//na parte fracionaria
            {
                if (isalpha(numero1[i]))
                {
                    numero1[i] = toupper(numero1[i]);
                    digitoFrac1 = (numero1[i] - 55);
                }
                else
                    digitoFrac1 = numero1[i];

                if (isalpha(numero2[i]))
                {
                    numero2[i] = toupper(numero2[i]);
                    digitoFrac2 = (numero1[i] - 55);
                }
                else
                    digitoFrac2 = numero2[i];

                if (digitoFrac1 > digitoFrac2)
                    return numero1;
                else if (digitoFrac1 < digitoFrac2)
                    return numero2;
                else
                    continue;
            }
        }
        else
        {
            for (int i = 0; i < tamInteiro1; i++)//na parte inteira
            {
                if (isalpha(numero1[i]))
                {
                    numero1[i] = toupper(numero1[i]);
                    digitoInteiro1 = (numero1[i] - 55);
                }
                else
                    digitoInteiro1 = numero1[i];

                if (isalpha(numero2[i]))
                {
                    numero2[i] = toupper(numero2[i]);
                    digitoInteiro2 = (numero1[i] - 55);
                }
                else
                    digitoInteiro2 = numero2[i];

                if (digitoInteiro1 > digitoInteiro2)
                    return numero1;
                else if (digitoInteiro1 < digitoInteiro2)
                    return numero2;
                else
                    continue;
            }
        }
    }
    else
        if (tamInteiro1 > tamInteiro2)
            return numero1;
        else
            return numero2;
}


string getInteira(string num)
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

string getFracionaria(string num)
{
    string ret = "";
    int posicaoVirgula = -1;
    unsigned int tamanho = 0;

    for (int i = num.size() - 1; i > 0 && num[i] != ','; i--)
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

//---------------------------------------------------------------------------//
//                              PROGRAMA - MAIN
//---------------------------------------------------------------------------//

int main()
{
    int base = 10;
    char operacao = '-', negTotal;
    string numero1 = "450", numero2 = "324", resultado;

    cout << "-=-=-=-=-=-=-=-=-=-PROJETO OPERA-=-=-=-=-=-=-=-=-=-\n" << endl;
    cout << "Giovanna, Maria Luiza e Vinicius - PD19" << endl;

    do
    {
        cout << "\nDigite a base da operacao: ";
        cin >> base;

        cout << "\nDigite a operacao (+, -, *, /): ";
        cin >> operacao;

        cout << "\nDigite o numero a ser operado: ";
        cin >> numero1;

        cout << "\nDigite o outro numero a ser operado: ";
        cin >> numero2;

    } while (!verificar(numero1, base, operacao) || !verificar(numero2, base, operacao));


    negTotal = verificarSinal(numero1, numero2);
    operacao = verificarOperacao(numero1, numero2);
    string maior = verificarMaiorModulo(numero1, numero2);
    string aux;

    if (maior != numero1)
    {
        aux = numero1;
        numero1 = numero2;
        numero2 = aux;
    }

    if (numero1.at(0) == '-')
        numero1[0] = '0';

    if (numero2.at(0) == '-') // (-1 + -5) é subtração
        numero2[0] = '0';

    //função coisada lá

    if (operacao == '+')
    {
        Soma minhaSoma = Soma(base);
        string maior = verificarMaiorModulo(numero1, numero2);  
    }

    if (operacao == '-')
    {
        Subtracao minhaSubtracao = Subtracao(base);
        string maior = verificarMaiorModulo(numero1, numero2);
        if (maior == numero1)
            resultado = minhaSubtracao.SubtraiNumeros(maior, numero2);
        else
            resultado = minhaSubtracao.SubtraiNumeros(maior, numero1);
    }

    cout << "\nO resultado deu: ";
    if (negTotal == '-')
        cout << negTotal;

    for (int i = 0; i < resultado.size(); i++) {
        if (resultado[i] == '0' && i == 0)
          continue;
         cout << resultado[i];
    }
   

    return 0;
}