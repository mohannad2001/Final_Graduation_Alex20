
#ifndef LCD_H
#define	LCD_H

#include <xc.h>

#define _4BITS    4
#define _8BITS    8

void LCD_cmd(char);

void LCD_init(int mode);  // initiate driver
void LCD_clear();
void LCD_write(char); // location???

void LCD_write_str(char*);
void LCD_write_num(unsigned int);

void LCD_goto_line1();
void LCD_goto_line2();

void LCD_goto_xy(int , int);


void LCD_cmd_4bits(char);
void LCD_write_4bits(char );
void LCD_clear_4bits();


void LCD_write_str_4bits(char*);
void LCD_write_num_4bits(unsigned int);

void LCD_goto_line1_4bits();
void LCD_goto_line2_4bits();

void LCD_goto_xy_4bits(int , int);

#endif	/* XC_HEADER_TEMPLATE_H */

