/*
 * LAB9_B.c
 *
 * Created: 23-03-2022 05:28:27 PM
 * Author : mayan
 */ 

#include <avr/io.h>

void usart_init(void)
{
	UCSRB=(1<<TXEN);
	UCSRC=(1<<UCSZ1)|(1<<UCSZ0)|(1<<URSEL);
	UBRRL=0x33;
}
void usart_send(unsigned char ch)
{
	while(!(UCSRA & ( 1 << UDRE )));
	UDR=ch;
}




int main(void)
{
	unsigned char  str[30]="My Name is Mayank";
	unsigned char strLength=30;
	unsigned char i=0;
	usart_init();
	while (1)
	{
		usart_send(str[i++]);
		if (i>=strLength)
			i=0;
	}
	return 0;
}

