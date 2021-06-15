
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>   // integer to array of char >> itoa
#include "LCD.h"

#define RW           2
#define RS			 1
#define EN			 4  // modified for simulation
#define ctrl		 PORTB
#define LCD_data	 PORTA

#define ctrl_dir     DDRB
#define LCD_data_dir DDRA


void LCD_cmd(char cmd){
	ctrl &= ~(1<<RS); // access to Command Register
	LCD_data = cmd;
	
	ctrl |= (1<<EN);  // Rising Edge
	_delay_ms(100);
	ctrl &= ~(1<<EN); // Falling Edge
}

void LCD_cmd_4bits(char cmd){
	ctrl &= ~(1<<RS); // access to Command Register
	
	LCD_data &= 0x0F;
	LCD_data |= (0xF0&cmd);
	
	ctrl |= (1<<EN);  // Rising Edge
	_delay_us(1);
	ctrl &= ~(1<<EN); // Falling Edge
	
	_delay_us(200);
	LCD_data &= 0x0F;
	LCD_data |= (cmd<<4);
	
	ctrl |= (1<<EN);  // Rising Edge
	_delay_us(1);
	ctrl &= ~(1<<EN); // Falling Edge
	
	_delay_ms(2);
	
}

void LCD_write_4bits(char data){
	ctrl |= (1<<RS); // access to Data Register
	
	LCD_data &= 0x0F;
	LCD_data |= (0xF0&data);
	
	ctrl |= (1<<EN);  // Rising Edge
	_delay_us(1);
	ctrl &= ~(1<<EN); // Falling Edge
	
	_delay_us(200);
	LCD_data &= 0x0F;
	LCD_data |= (data<<4);
	
	ctrl |= (1<<EN);  // Rising Edge
	_delay_us(1);
	ctrl &= ~(1<<EN); // Falling Edge
	
	_delay_ms(2);
	
}

void LCD_init(int mode){
	// Data Direction
	ctrl_dir |= (1<<RS)|(1<<EN)|(1<<RW);
	ctrl &= ~(1<<RW); // Always write to LCD
	if(mode == _4BITS){
		LCD_data_dir |= 0xF0;  // PORTx as OUTPUT
		LCD_cmd(0x20);                //Data Mode  4-bits
		_delay_ms(1);
        //LCD_data &= 0xF0;
		LCD_cmd_4bits(0x01);          // make clear LCD
		LCD_cmd_4bits(0x0C);          // display on, cursor off
		_delay_ms(100);
	}
	
	else{
		LCD_data_dir = 0xFF;  // PORTx as OUTPUT
		// initiate LCD for 8bit mode.// Data Mode  8-bits
		LCD_cmd(0x38);
		_delay_ms(1);
		LCD_cmd(0x01);          // make clear LCD
		LCD_cmd(0x0C);          // display on, cursor off
		_delay_ms(100);
	}
}

void LCD_write(char data){
	
	LCD_data = data;
	ctrl |= (1<<RS);
	
	ctrl |= (1<<EN);  // Rising Edge
	_delay_ms(1);
	ctrl &= ~(1<<EN); // Falling Edge
}

void LCD_clear(){
	_delay_ms(1);
	LCD_cmd(0x01);          // make clear LCD
	_delay_ms(1);
}
void LCD_clear_4bits(){
	_delay_ms(1);
	LCD_cmd_4bits(0x01);          // make clear LCD
	_delay_ms(1);
}

void LCD_write_str(char* str){
	
	for(int i=0; str[i]!= '\0';i++){
		LCD_write(str[i]);
	}
}
void LCD_write_str_4bits(char* str){
	
	for(int i=0; str[i]!= '\0';i++){
		LCD_write_4bits(str[i]);
	}
}

void LCD_write_num(unsigned int num){
	char strNumber[8];
	
	itoa(num, strNumber,10);
	
	LCD_write_str(strNumber);
	
}

void LCD_write_num_4bits(unsigned int num){
	char strNumber[8];
	
	itoa(num, strNumber,10);
	
	LCD_write_str_4bits(strNumber);
	
}


void LCD_goto_line1(){
	LCD_cmd(0X80);
}

void LCD_goto_line2(){
	LCD_cmd(0XC0);
}

void LCD_goto_line1_4bits(){
	LCD_cmd_4bits(0X80);
}

void LCD_goto_line2_4bits(){
	LCD_cmd_4bits(0XC0);
}

void LCD_goto_xy(int row , int col){  // col 0 ~ 15      0 ~ F
	if(row == 0 && col < 16){  // LINE 1
		LCD_cmd(0X80|col);
	}
	else if (row == 1 && col < 16) // LINE 2
	{
		LCD_cmd(0XC0|col);
	}
	else{
		//LCD_write_str("out of dimension");
	}
}

void LCD_goto_xy_4bits(int row , int col){  // col 0 ~ 15      0 ~ F
	if(row == 0 && col < 16){  // LINE 1
		LCD_cmd_4bits(0X80|col);
	}
	else if (row == 1 && col < 16) // LINE 2
	{
		LCD_cmd_4bits(0XC0|col);
	}
	else{
		//LCD_write_str_4bits("out of dimension");
	}
}