#include "operacoes.h"

int myAtoi(unsigned char* str) { //char[] para inteiro
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++)
        res = res * 10 + str[i] - '0';
    return res;
}

void myItoa(int dataIn, unsigned char* bffr, int radix) { //int num para ser convertido, char[] para armazenar o convertido, radix para a base numerica (padrao 10)
    int temp_dataIn;
    temp_dataIn = dataIn;
    int stringLen = 1;
    while ((int) temp_dataIn / radix != 0) {
        temp_dataIn = (int) temp_dataIn / radix;
        stringLen++;
    }
    temp_dataIn = dataIn;
    do {
        *(bffr + stringLen - 1) = (temp_dataIn % radix) + '0';
        temp_dataIn = (int) temp_dataIn / radix;
    } while (stringLen--);
}

int soma(int x, int y) {
    return x + y;
}

int subtracao(int x, int y) {
    return x - y;
}

int multiplicacao(int x, int y) {
    return x*y;
}

int divisao(int x, int y) {
    return x / y;
}

int potencia(int x, int y) {
    int soma = 1;
    for (int i = 0; i < y; i++) {
        soma = soma*x;
    }
    return soma;
}

int restoDaDivisao(int n, int d) {
    return n % d;
}

int operacoes(int aux1, int aux2, int aux3) {
    switch (aux3) {
        case 1111:
            return soma(aux1, aux2);

        case 1112:
            return subtracao(aux1, aux2);

        case 1113:
            return multiplicacao(aux1, aux2);

        case 1114:
            return divisao(aux1, aux2);

        case 1115:
            return potencia(aux1, aux2);

        case 1116:
            return restoDaDivisao(aux1, aux2);

    }
}
