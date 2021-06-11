

#define F_CPU 16000000UL
#include "final_header.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>




// MASTER



// The Master recieve the data from the UART the send it to the salve , as the data will be send SPI will be the same data for the data recived UART


char data;

int main(void) {

    LCD_init(_4BITS);
    LCD_clear_4bits();
    UART_init(9600);
    SPI_init(Master, f_128);
    SPI_enable();


    while (1) {

        data = UART_recieve();

        SPI_send(data);
        _delay_ms(200);


    }
}
