#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>  


#include "UART.h"

void    UART_init(int BAUDRATE) 
{
    UCSRB |= ((1<<RXEN) | (1<<TXEN));
    UCSRB |=(1<<RXCIE);
    UART_setBaudRate( BAUDRATE);
}
void   UART_setBaudRate (int  BAUDRATE)
{
   int UBRR= ((F_CPU/16.0)/BAUDRATE)-1;
    UBRRL = (char) UBRR;
    UBRRH = (UBRR >>8);
}
//CALCULATE FROM EQUATION 
//UBRL
//UBRH
    
void  UART_SEND(char data)
{
    while  (!(UCSRA &(1<<UDRE))) ;
    UDR = data ;
}
char UART_recieve()
{
    while (!(UCSRA & (1<<RXC)));
    return UDR;
}
void UART_Send_str(char str[])
{
    int i ;
    for ( i =0 ;str[i]!= '\0' ; i++)
    {
        UART_SEND(str[i]);
    }
    
}
void UART_Send_Num(int number)
{
    char buff[11];
    itoa(number,buff,10);
    UART_Send_str(buff);
}