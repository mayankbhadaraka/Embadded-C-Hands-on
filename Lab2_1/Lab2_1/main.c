#define F_CPU 16000000UL  //clock speed is 16MHz
#include <avr/io.h>


int main(void)
{
	DDRA=0xFF;
    while (1) 
    {
		PORTA = 0x01;
		PORTA = 0x00;
    }
}

