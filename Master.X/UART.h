
#ifndef UART_H
#define	UART_H

#include <xc.h> 


void    UART_init(int BAUDRATE) ;
//Enable TX RX
//CALL UART_SETBAUD
void   UART_setBaudRate (int  BAUDRATE);
//CALCULATE FROM EQUATION 
//UBRL
//UBRH
    
void  UART_SEND(char data);
char UART_recieve();
void UART_Send_str();
void UART_Send_Num();

#endif	/* XC_HEADER_TEMPLATE_H */

