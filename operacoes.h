#ifndef OPERACOES_H
#define	OPERACOES_H
#include "defines.h"

int myAtoi(unsigned char* str);
void myItoa(int dataIn, unsigned char* bffr, int radix);
int operacoes( int aux1, int aux2, int aux3);
int soma(int x, int y);
int subtracao(int x, int y);
int multiplicacao(int x, int y);
int divisao(int x, int y);
int potencia(int x, int y);
int restoDaDivisao(int n, int d);
#endif	/* OPERACOES_H */

