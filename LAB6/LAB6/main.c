/*
 * LAB6.c
 *
 * Created: 23-02-2022 05:00:53 PM
 * Author : mayan
 */ 
#define F_CPU 16000000UL
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC=0xFF;
    while (1) 
    {
		PORTC=0x08;
		_delay_ms(500);
		PORTC=0x04;
		_delay_ms(500);
		PORTC=0x02;
		_delay_ms(500);
		PORTC=0x01;
		_delay_ms(500);
    }
}

