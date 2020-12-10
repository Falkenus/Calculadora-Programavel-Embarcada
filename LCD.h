#ifndef LCD_H
#define	LCD_H
#include "defines.h"

void nextLine();
void LCD_conf();
void lcd_wr(unsigned char val);
void lcd_cmd(unsigned char val) ;
void lcd_dat(unsigned char val);
void lcd_init(void);
void lcd_str(char* str);
void atraso_ms(int t);

#endif	/* LCD_H */

