/*
 * LAB3_(e).c
 *
 * Created: 02-02-2022 05:41:49 PM
 * Author : mayan
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRA=0xFF;
	int a=2;
	int array[] = {1*a,2*a,3*a,4*a,5*a,6*a,7*a,8*a,9*a,10*a};
    while (1) 
    {
		for (int z=0;z<10;z++)
		{
			PORTA = array[z];
			_delay_ms(100);
			PORTA = 0;
			_delay_ms(100);
		}
    }
}

