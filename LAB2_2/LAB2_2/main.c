/*
 * LAB2_2.c
 *
 * Created: 19-01-2022 04:47:48 PM
 * Author : mayan
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
    DDRB = 0xFF;
    while (1) 
    {
		PORTB = 0xFF;
		PORTB = 0x00;
    }
}

