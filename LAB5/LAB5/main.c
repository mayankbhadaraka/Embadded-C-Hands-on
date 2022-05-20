/*
 * LAB5.c
 *
 * Created: 23-02-2022 04:32:32 PM
 * Author : mayan
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


int main(void)
{
    DDRC=0xFF;
    while (1) 
    {
		PORTC=0x00;
		_delay_ms(100);
		PORTC=0x05;
		_delay_ms(100);
		PORTC=0x28;
		_delay_ms(100);
		PORTC=0x2D;
		_delay_ms(100);
		PORTC=0x1E;
		_delay_ms(100);
    }
}

