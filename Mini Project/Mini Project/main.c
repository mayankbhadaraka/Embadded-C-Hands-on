/*
 * Mini Project.c
 *
 * Created: 10-03-2022 10:06:15 AM
 * Author : mayan
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <stdio.h>
#include <util/delay.h>

void lcd_cmd(unsigned char cmd) //create function to send commands to lcd
{
	PORTA = cmd; //using PortD for sending  command
	PORTB = 0x04; //using PortC for controlling lcd with RS,RW, Enable
	_delay_ms(10);
	PORTB = 0x00;
}
void lcd_data (unsigned char data)
{
	PORTA = data; //using PortB for sending data
	PORTB = 0x05; //using PortC for controlling lcd with RS,RW, Enable
	_delay_ms(10);
	PORTB = 0x01;
}
void lcd_init ()
{
	
	lcd_cmd(0x38);
	lcd_cmd(0x0F);
	lcd_cmd(0x01);
	
}


void Row1()
{
	if (PINC == 0x01)
	{
		lcd_data('1');	
	}
	else if (PINC == 0x02)
	{
		lcd_data('2');
	}
	else if (PINC == 0x04)
	{
		lcd_data('3');
	}
	else if (PINC == 0x08)
	{
		lcd_data('4');
	}
}
void Row2()
{
	if (PINC == 0x01)
	{
		lcd_data('5');
	}
	else if (PINC == 0x02)
	{
		lcd_data('6');
	}
	else if (PINC == 0x04)
	{
		lcd_data('7');
	}
	else if (PINC == 0x08)
	{
		lcd_data('8');
	}
	
}
void Row3()
{
	if (PINC == 0x01)
	{
		lcd_data('9');
	}
	else if (PINC == 0x02)
	{
		lcd_data('A');
	}
	else if (PINC == 0x04)
	{
		lcd_data('B');
	}
	else if (PINC == 0x08)
	{
		lcd_data('C');
	}
	
}
void Row4()
{
	if (PINC == 0x01)
	{
		lcd_data('D');
	}
	else if (PINC == 0x02)
	{
		lcd_data('E');
	}
	else if (PINC == 0x04)
	{
		lcd_data('F');
	}
	else if (PINC == 0x08)
	{
		lcd_data('G');
	}
	
}

int main(void)
{
    DDRA=0xFF;
	DDRB=0xFF;
	DDRC=0x00;
	DDRD=0xFF;
	lcd_init();
	lcd_data('A');
    while (1) 
    {
		if (PORTD=0x70)  
		{
			Row1();
			_delay_ms(50);
		}
		if (PORTD=0xB0)
		{
			Row2();
			_delay_ms(50);
		}
		if (PORTD=0xD0)
		{
			Row3();
			_delay_ms(50);
		}
		if (PORTD=0xE0)
		{
			Row4();
			_delay_ms(50);
		}
    }
}

