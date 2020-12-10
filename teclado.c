#include "teclado.h"

const unsigned char linha[4] = {TL1, TL2, TL3};
unsigned int atraso_min = 5;
unsigned int atraso = 15;
unsigned int atrasoMin = 20;
unsigned int atrasoMed = 500;
unsigned int atrasoMax = 1000;

unsigned char tc_tecla(unsigned int timeout) {
    unsigned int to = 0;
    unsigned char i;
    unsigned char ret = 0;
    unsigned char tmp = PORTB;
    while (((to < timeout) || (!timeout))&&(!ret)) {
        for (i = 0; i < 3; i++) {
            PORTB |= ~linha[i];
            if (!BitTst(PORTD, 3)) { //TC1
                atraso_ms(atraso);
                if (!BitTst(PORTD, 3)) {
                    while (!BitTst(PORTD, 3));
                    ret = 1 + i;
                    break;
                }
            };
            if (!BitTst(PORTD, 2)) {
                atraso_ms(atraso);
                if (!BitTst(PORTD, 2)) {
                    while (!BitTst(PORTD, 2));
                    ret = 4 + i;
                    break;
                }
            };
            if (!BitTst(PORTD, 1)) {
                atraso_ms(atraso);
                if (!BitTst(PORTD, 1)) {
                    while (!BitTst(PORTD, 1));
                    ret = 7 + i;
                    break;
                }
            };
            if (!BitTst(PORTD, 0)) {
                atraso_ms(atraso);
                if (!BitTst(PORTD, 0)) {
                    while (!BitTst(PORTD, 0));
                    ret = 10 + i;
                    break;
                }
            };
            PORTB &= linha[i];
        };
        atraso_ms(atraso_min);
        to += 5;
    }
    if (!ret)ret = 255;
    if (ret == 11)ret = 0;
    PORTB = tmp;
    return ret;
}

void teclaLeitura(unsigned char *tmp) {
    TRISB = 0xF8;
    TRISD = 0x0F;
    do {
        *tmp = 0;
        *tmp = tc_tecla(0) + 0x30;
    } while (*tmp == 0x12F);
}
