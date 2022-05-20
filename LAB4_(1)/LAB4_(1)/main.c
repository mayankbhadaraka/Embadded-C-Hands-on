/*
 * LAB4_(1).c
 *
 * Created: 09-02-2022 05:03:26 PM
 * Author : mayan
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0xFF;
	DDRB=0xFF;
	char arr[]={0xFC,0x60,0xDA,0XF2,0X66,0XB6,0XBE,0XE0,0XFE,0XF6};
	while (1)
	{
		for (int i=0;i<=9;i++)
		{
			PORTB=arr[i];
			for (int j=0;j<=9;j++)
			{
				PORTA=arr[j];
				_delay_ms(100);
			}
		}
	}
}

