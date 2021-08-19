#pragma once
class Digito
{
	  public:
        Digito(int valor, int base);
        Digito(char valor, int base);
        Digito();
        int getValorInt();
        int getBase();
        char getValorChar();
        void setValor(char v);
        void setValor(int v);

    private:
        char valChar;
        int valInt;
        int base;
};

