/*
 * LAB3_(D).c
 *
 * Created: 02-02-2022 05:27:09 PM
 * Author : mayan
 */ 

#define F_CPU 16000000UL //clock speed is 16MHz
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	int array[] = {1,2,4,8,16,32,64,128};
	while (1)
	{
		for (int i=0; i<8; i++)
		{
			PORTA =array[i];
			_delay_ms(100);
			PORTA = 0;
			_delay_ms(100);
		}
		
		
		
	}
}


