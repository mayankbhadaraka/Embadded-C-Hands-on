/*
 * Lab_3(A).c
 *
 * Created: 02-02-2022 04:14:55 PM
 * Author : mayan
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF; 
    /* Replace with your application code */
    while (1) 
    {
		PORTA = 0x01;
		_delay_ms(1000);
		PORTA = 0x00;
		_delay_ms(1000);

    }
}

