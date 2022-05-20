/*
 * LAB2_3.c
 *
 * Created: 19-01-2022 04:56:07 PM
 * Author : mayan
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
    char mynum[]={1,2,3,4,5,6,7,8};
	unsigned char z;
	DDRC = 0xFF;
    while (1) 
    {
		for (z=0;z<9;z++)
		{
			PORTC = mynum[z];
		}
    }
}

