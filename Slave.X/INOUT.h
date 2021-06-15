
#ifndef INOUT_H
#define	INOUT_H

#include <xc.h>

#define LED0    2
#define LED1    7
#define LED2    3
#define RELAY   2
#define BUZZER  3
#define POT     1
#define BTN0    0
#define BTN1    6
#define BTN2    2


void BTNs_init();

void LEDs_init();
void LED0_ON();
void LED1_ON();
void LED2_ON();
void LED0_OFF();
void LED1_OFF();
void LED2_OFF();
void LEDs_OFF();
void LEDs_ON();
void RELAY_init();
void RELAY_ON();
void RELAY_OFF();

void BUZZER_init();
void BUZZER_ON();
void BUZZER_OFF();

int isPressed_BTN0();
int isPressed_BTN1();
int isPressed_BTN2();

void LED0_TOGGLE();
void LED1_TOGGLE();
void LED2_TOGGLE();

void LCD_WRITE_CHAR(char a[100]);
#endif