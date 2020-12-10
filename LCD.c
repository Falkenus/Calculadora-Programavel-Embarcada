#include "LCD.h"

unsigned char nowLine = L_L1;

void nextLine(){
    switch(nowLine){
        case L_L1:
            lcd_cmd(L_L2);
            break;
        case L_L2:
            lcd_cmd(L_L3);
            break;
        case L_L3:
            lcd_cmd(L_L4);
            break;
        case L_L4:
            lcd_cmd(L_L1);
            break;
    }
    return;
}

void LCD_conf(){
    ADCON1 = 0x06;
    TRISB = 0x01;
    TRISD = 0x00;
    TRISE = 0x00;
    return;
}

void lcd_wr(unsigned char val) {
    PORTD = val;
    return;
}

void lcd_cmd(unsigned char val) {
    if (val == L_L1 || val == L_L2 || val == L_L3 || val == L_L4) {
        nowLine = val;
    }
    BitSet(PORTE, 1); // Enable - PORTEbits.RE1
    lcd_wr(val);
    BitClr(PORTE, 2); // Data - PORTEbits.RE2
    atraso_ms(3);
    BitClr(PORTE, 1);
    atraso_ms(3);
    BitSet(PORTE, 1);
    return;
}

void lcd_dat(unsigned char val) {
    BitSet(PORTE, 1);
    lcd_wr(val);
    BitSet(PORTE, 2);
    atraso_ms(3);
    BitClr(PORTE, 1);
    atraso_ms(3);
    BitSet(PORTE, 1);
    return;
}

void lcd_init(void) {
    BitClr(PORTE, 1);
    BitClr(PORTE, 2);
    atraso_ms(20);
    BitSet(PORTE, 1);
    lcd_cmd(L_CFG);
    atraso_ms(5);
    lcd_cmd(L_CFG);
    atraso_ms(1);
    lcd_cmd(L_CFG); //configura
    lcd_cmd(L_OFF); //desliga
    lcd_cmd(L_ON); //liga
    lcd_cmd(L_CLR); //limpa
    lcd_cmd(L_CFG); //configura
    lcd_cmd(L_L1);
    return;
}

void lcd_str(char* str) {
    unsigned char i = 0;
    while (str[i] != 0) {
        lcd_dat(str[i]);
        i++;
    }
    return;
}

void atraso_ms(int t) {
    volatile unsigned char j, k;
    volatile unsigned int i;

    for (i = 0; i < (t); i++) {
        for (j = 0; j < 41; j++) {
            for (k = 0; k < 3; k++);
        }
    }
    return;
}