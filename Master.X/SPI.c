#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>  
#include "SPI.h"
void SPI_init(int Type, int FREQ) {
    SPCR |= (1<<SPIE);
    switch (Type) {
        case Master:
            SPCR |= (1 << MSTR);
            DDRB |= (1<<MOSI) | (1<<SS) | (1<<SCK);
            break;
        case Sleev:
            SPCR &= ~(1 << MSTR);
            DDRB |= (1<<MISO);
            break;

    }
    switch (FREQ) {
        case f_4:
            break;
        case f_16:
            SPCR |= (1 << SPR0);
            break;
        case f_64:
            SPCR |= (1 << SPR1);
            break;
        case f_128:
            SPCR |= ((1 << SPR1) | (1 << SPR0));
            break;
        case f_2:
            SPSR |= (1 << SPI2X);
            break;
        case f_8:
            SPSR |= (1 << SPI2X);
            SPCR |= (1 << SPR0);
            break;
        case f_32:
            SPSR |= (1 << SPI2X);
            SPCR |= (1 << SPR1);
            break;
//        case f_64:
//            SPSR |= (1 << SPI2X);
//            SPCR |= ((1 << SPR1) | (1 << SPR0));
//            break;
    }
}

void SPI_enable() {
    SPCR |= (1 << SPE);

}
void SPI_send(char data) {
    SPDR = data;
    SPI_wait();


}
void SPI_send_slav(char slavslct ,char data)
{
    PORTA &=~(1<<slavslct);
    SPDR= data;
    SPI_wait();
    PORTA |=(1<<slavslct);
         
    
}
char SPI_recive(void) {
    SPI_wait();
    return SPDR;
}



void SPI_wait() {
    while (!(SPSR & (1 << SPIF)));
}
