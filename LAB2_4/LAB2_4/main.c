/*
 * LAB2_4.c
 *
 * Created: 19-01-2022 05:12:49 PM
 * Author : mayank
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
	DDRA = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
		for (int i=1;i<8;i++)
		{
			PORTA = (0x01 <<i );
			PORTA = 0x00;
		}
    }
}

