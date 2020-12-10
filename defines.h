#ifndef DEFINES_H
#define	DEFINES_H

//include das outras Libs
#include "LCD.h"
#include "teclado.h"
#include "operacoes.h"

//Define do Pic
#define PIC18F4520

//Configuracoes
#pragma config OSC=HS                  // Oscilador c/ cristal externo HS
#pragma config WDT=OFF                 // Watchdog controlado por software
#pragma config LVP=OFF                 // Sem programação em baixa tensão
#pragma config DEBUG = OFF             // Desabilita debug
#pragma config WDTPS = 1               // Configura prescaler do watchdog

//Define das operacoes bitwise
#define BitSet(arg,bit) ((arg) |= (1<<bit))
#define BitClr(arg,bit) ((arg) &= ~(1<<bit)) 
#define BitFlp(arg,bit) ((arg) ^= (1<<bit)) 
#define BitTst(arg,bit) ((arg) & (1<<bit)) 

//define para registros especiais
//define das PORT's
#define PORTA	(*(volatile __near unsigned char*)0xF80)
#define PORTB	(*(volatile __near unsigned char*)0xF81)
#define PORTC	(*(volatile __near unsigned char*)0xF82)
#define PORTD	(*(volatile __near unsigned char*)0xF83)
#define PORTE	(*(volatile __near unsigned char*)0xF84)
//define dos TRIS's
#define TRISA	(*(volatile __near unsigned char*)0xF92)
#define TRISB	(*(volatile __near unsigned char*)0xF93)
#define TRISC	(*(volatile __near unsigned char*)0xF94)
#define TRISD	(*(volatile __near unsigned char*)0xF95)
#define TRISE	(*(volatile __near unsigned char*)0xF96)
//outros define's de registros especiais
//conferir funcoes no datasheet do pic18f4520, se necessario
#define INTCON	(*(volatile __near unsigned char*)0xFF2)
#define INTCON2	(*(volatile __near unsigned char*)0xFF1)
#define PIE1	(*(volatile __near unsigned char*)0xF9D)
#define PIR1	(*(volatile __near unsigned char*)0xF9E)
#define PIR2	(*(volatile __near unsigned char*)0xFA1)
#define TMR0L	(*(volatile __near unsigned char*)0xFD6)
#define TMR0H	(*(volatile __near unsigned char*)0xFD7)
#define T0CON	(*(volatile __near unsigned char*)0xFD5)
#define ADCON2	(*(volatile __near unsigned char*)0xFC0)
#define ADCON1	(*(volatile __near unsigned char*)0xFC1)
#define ADCON0	(*(volatile __near unsigned char*)0xFC2)
#define ADRESL	(*(volatile __near unsigned char*)0xFC3)
#define ADRESH	(*(volatile __near unsigned char*)0xFC4)
#define RCSTA	(*(volatile __near unsigned char*)0xFAB)
#define TXSTA	(*(volatile __near unsigned char*)0xFAC)
#define TXREG	(*(volatile __near unsigned char*)0xFAD)
#define RCREG	(*(volatile __near unsigned char*)0xFAE)
#define SPBRG	(*(volatile __near unsigned char*)0xFAF)
#define SPBRGH	(*(volatile __near unsigned char*)0xFB0)
#define BAUDCON	(*(volatile __near unsigned char*)0xFB8)
#define RCON	(*(volatile __near unsigned char*)0xFD0)
#define WDTCON	(*(volatile __near unsigned char*)0xFD1)
#define T2CON	(*(volatile __near unsigned char*)0xFCA)
#define PR2	    (*(volatile __near unsigned char*)0xFCB)
#define CCP2CON	(*(volatile __near unsigned char*)0xFBA)
#define CCPR2L	(*(volatile __near unsigned char*)0xFBB)
#define CCP1CON	(*(volatile __near unsigned char*)0xFBD)
#define CCPR1L	(*(volatile __near unsigned char*)0xFBE)
#define SSPCON2 (*(volatile __near unsigned char*)0xFC5)
#define SSPCON1 (*(volatile __near unsigned char*)0xFC6)
#define SSPSTAT (*(volatile __near unsigned char*)0xFC7)
#define SSPAD   (*(volatile __near unsigned char*)0xFC8)
#define SSPBUF  (*(volatile __near unsigned char*)0xFC9)

//defines do LCD
#define L_ON	0x0F
#define L_OFF	0x08
#define L_CLR	0x01 //limpa LCD
#define L_L1	0x80 //cursor na linha 1
#define L_L2	0xC0 //cursor na linha 2
#define L_L3    0x94 //cursor na linha 3
#define L_L4    0xD4 //cursor na linha 4
#define L_CR	0x0F		
#define L_NCR	0x0C	
#define L_CFG   0x38

//defines do Teclado
#define TL1     0x01
#define TL2     0x02
#define TL3     0x04


#endif	/* DEFINES_H */

