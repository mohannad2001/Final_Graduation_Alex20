
#ifndef SPI_H
#define	SPI_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define Master 1
#define Sleev 0 
#define  f_4  0
#define  f_16  1
#define  f_64    2
#define  f_128   3
#define  f_2   4
#define  f_8   5
#define  f_32  6
//#define   f_64   7

#define Read_M      0
#define Read_L   1

#define  MOSI  5
#define  MISO 6
#define  SS  4
#define  SCK    7 

void SPI_init(int FREQ , int Type );
void SPI_enable();
char SPI_recive(void);
void SPI_send(char data);
void SPI_send_slav(char slavselector ,char data);
void SPI_wait();

#endif	/* XC_HEADER_TEMPLATE_H */

