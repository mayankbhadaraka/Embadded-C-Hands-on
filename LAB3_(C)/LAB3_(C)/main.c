/*
 * LAB3_(C).c
 *
 * Created: 02-02-2022 04:50:03 PM
 * Author : mayan
 */ 

#define F_CPU 16000000UL //clock speed is 16MHz

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	char mynum[] = {1,2,3,4,5,6,7,8};
	unsigned char z;
	DDRA = 0xFF;
	
	while(1)
	{
		for (z=0;z<8;z++)
		{
		PORTA = mynum[z];
		_delay_ms(100);
		PORTA = 0;
		_delay_ms(100);
		} 
		for (z=7;z>=0;z--)
		{
			PORTA = mynum[z];
			_delay_ms(100);
			PORTA = 0;
			_delay_ms(100);
		}
	}
}


