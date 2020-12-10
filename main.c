#include "defines.h"
#include "teclado.h"
#include "operacoes.h"
#include "LCD.h"
#define MAX 5
#define LIM 4

void main(void) {
    LCD_conf();
    lcd_init();
    unsigned char tmp = 0x00;
    unsigned char i = 0;
    unsigned char num1[MAX], num2[MAX], num3[MAX], num4[MAX];
    int aux1, aux2, aux3;
    for (char j = 0; j < LIM; j++) {
        num1[i] = 0x00;
        num2[i] = 0x00;
        num3[i] = 0x00;
        num4[i] = 0x00;
    }
    i = 0;
    lcd_str("Num1: ");
    while (i < LIM) {
        tmp = 0x00;
        teclaLeitura(&tmp);
        num1[i] = tmp;
        LCD_conf();
        lcd_dat(num1[i]);
        if (num1[i] != 0) {
            i++;
        }
        if (i == LIM) {
            nextLine();
        }
    }
    i = 0;
    lcd_str("Num2: ");

    while (i < LIM) {
        tmp = 0x00;
        teclaLeitura(&tmp);
        num2[i] = tmp;
        LCD_conf();
        lcd_dat(num2[i]);
        if (num2[i] != 0) {
            i++;
        }
        if (i == LIM) {
            nextLine();
            for (int k = 0; k < 4; k++) {
                lcd_cmd(0x10);
            }
        }
    }
    i = 0;
    lcd_str("Op: ");

    while (i < LIM) {
        tmp = 0x00;
        teclaLeitura(&tmp);
        num3[i] = tmp;
        LCD_conf();
        lcd_dat(num3[i]);
        if (num3[i] != 0) {
            i++;
        }
        if (i == LIM) {
            nextLine();
            for (int k = 0; k < 4; k++) {
                lcd_cmd(0x10);
            }
        }
    }
    lcd_str("Res: ");
    aux1 = myAtoi(num1);
    aux2 = (myAtoi(num2));
    aux3 = myAtoi(num3);
    myItoa(operacoes(aux1, aux2, aux3), num4, 10);
    lcd_str(num4);
    while (1);
}
