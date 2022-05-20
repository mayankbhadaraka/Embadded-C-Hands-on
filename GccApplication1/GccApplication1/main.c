/*
 * GccApplication1.c
 *
 * Created: 02-02-2022 04:36:49 PM
 * Author : mayan
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB = 0xFF;
    while (1) 
    {
			PORTB = 0xFF;
			_delay_ms(100);
			PORTB = 0x00;
			_delay_ms(100);

    }
}

