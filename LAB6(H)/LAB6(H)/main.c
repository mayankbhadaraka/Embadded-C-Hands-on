/*
 * LAB6(H).c
 *
 * Created: 01-03-2022 09:09:51 AM
 * Author : mayan
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC=0xFF;
	int i=4;
/*
 i=1 = Single phase stepper CW
 i=2 : Single phase stepper CCW
 i=3 : Two phase stepper CW
 i=4 : Two phase stepper CCW
 */ 
    while (1) 
    {
		switch (i)
		{
			case 1:
				PORTC=0x08;
				_delay_ms(500);
				PORTC=0x04;
				_delay_ms(500);
				PORTC=0x02;
				_delay_ms(500);
				PORTC=0x01;
				_delay_ms(500);
				break;
			case 2:
				PORTC=0x01;
				_delay_ms(500);
				PORTC=0x02;
				_delay_ms(500);
				PORTC=0x04;
				_delay_ms(500);
				PORTC=0x08;
				_delay_ms(500);
				break;
			case 3:
				PORTC=0x0C;
				_delay_ms(500);
				PORTC=0x06;
				_delay_ms(500);
				PORTC=0x03;
				_delay_ms(500);
				PORTC=0x09;
				_delay_ms(500);
				break;
			case 4:
				PORTC=0x09;
				_delay_ms(500);
				PORTC=0x03;
				_delay_ms(500);
				PORTC=0x06;
				_delay_ms(500);
				PORTC=0x0C;
				_delay_ms(500);
				break;
		}
    }
}

