#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h> 
#include "INOUT.h"

int isPressed_BTN0(){
    if(PINB & (1<<BTN0)){
        return 1;
    }
    else{
        return 0;
    }
}

int isPressed_BTN1(){
    if(PIND & (1<<BTN1)){
        return 1;
    }else{
        return 0;
    }
}

int isPressed_BTN2(){
    if(PIND & (1<<BTN2)){
        return 1;
    }else{
        return 0;
    }
}

void BTNs_init(){
    DDRD &= ~((1<<BTN1)|(1<<BTN2));
    DDRB &= ~(1<<BTN0);
}

void BUZZER_init() {
    DDRA |= (1 << BUZZER);
}

void BUZZER_ON() {
    PORTA |= (1 << BUZZER);
}

void BUZZER_OFF() {
    PORTA &= ~(1 << BUZZER);
}

void RELAY_init() {
    DDRA |= (1 << RELAY);
}

void RELAY_ON() {
    PORTA |= (1 << RELAY);
}

void RELAY_OFF() {
    PORTA &= ~(1 << RELAY);
}

void LEDs_init() {
    // Data Direction (input or output)
    DDRC |= (1 << LED1) | (1 << LED0); // PC2,PC7 are output
    DDRD |= (1 << LED2); // PD3 is output
}

void LED0_ON() {
    PORTC |= (1 << LED0);
}

void LED1_ON() {
    PORTC |= (1 << LED1);
}

void LED2_ON() {

    PORTD |= (1 << LED2);
}

void LED0_OFF() {
    PORTC &= ~(1 << LED0);
}

void LED1_OFF() {
    PORTC &= ~(1 << LED1);
}

void LED2_OFF() {
    PORTD &= ~(1 << LED2);
}

void LEDs_OFF() {
    LED0_OFF();
    LED1_OFF();
    LED2_OFF();
}

void LEDs_ON() {
    LED0_ON();
    LED1_ON();
    LED2_ON();
}

void LED0_TOGGLE(){
    
    PORTC ^= (1<<LED0);
    
}
void LED1_TOGGLE(){
    
    PORTC ^= (1<<LED0);
    
}

void LED2_TOGGLE(){
    
    PORTC ^= (1<<LED0);
    
}