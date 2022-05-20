/*
 * LAB8(MiniProject).c
 *
 * Created: 09-03-2022 05:50:05 PM
 * Author : mayan
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void lcd_cmd(unsigned char cmd) //create function to send commands to lcd
{
	PORTA = cmd; //using PortD for sending  command
	PORTB = 0x04; //using PortC for controlling lcd with RS,RW, Enable
	_delay_ms(10);
	PORTB = 0x00;
}
void lcd_data (unsigned char data)
{
	PORTA = data; //using PortB for sending data
	PORTB = 0x05; //using PortC for controlling lcd with RS,RW, Enable
	_delay_ms(10);
	PORTB = 0x01;
}
void lcd_init ()
{
	lcd_cmd(0x01);
	lcd_cmd(0x38);
	lcd_cmd(0x0F);
	
}

int key_open()
{
	unsigned char Y;
	 PORTD=0xFF;
	 Y=PINC & 0xFF;
	if(Y==0xFF)
	{
		lcd_data('O');
		return 1;
	}
	else
	{
		lcd_data('C');
	}
}

int key_Down()
{
	unsigned char X,Y;
	X=PINC;
	Y=X&0xFF;
	if (Y!=0xFF)
		return 1;
}
void LCD_String (char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)  /* send each char of string till the NULL */
	{
		lcd_data(str[i]);  /* call LCD data write */
	}
}


int main(void)
{
    DDRA=0xFF;
	DDRB=0xFF;
	DDRD=0xFF;
	DDRC=0x00;
	unsigned char Y;
	lcd_init();
	LCD_String("Praced keys:");
	lcd_cmd(0xC0);
    while (1) 
    {
		
		if (key_open()==1)
		{
			
			if (key_Down()==1)
			{
				_delay_ms(10);
				if (key_Down()==1)
				{
					PORTD=0x00;
					Y=(PINC & 0XFF);

					if (Y==0x01)
					{
						if (PORTD=0x01)
						{
							lcd_data('1');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x02)
						{
							lcd_data('5');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x04)
						{
							lcd_data('9');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x08)
						{
							lcd_data('D');
							_delay_ms(50);
							break;
						}
					}
					else if (Y==0x02)
					{
						if (PORTD=0x01)
						{
							lcd_data('2');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x02)
						{
							lcd_data('6');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x04)
						{
							lcd_data('A');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x08)
						{
							lcd_data('E');
							_delay_ms(50);
							break;
						}
					}
					else if (Y==0x04)
					{
						if (PORTD=0x01)
						{
							lcd_data('3');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x02)
						{
							lcd_data('7');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x04)
						{
							lcd_data('B');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x08)
						{
							lcd_data('F');
							_delay_ms(50);
							break;
						}
					}
					else if (Y==0x08)
					{
						if (PORTD=0x01)
						{
							lcd_data('4');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x02)
						{
							lcd_data('8');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x04)
						{
							lcd_data('C');
							_delay_ms(50);
							break;
						}
						else if (PORTD=0x08)
						{
							lcd_data('G');
							_delay_ms(50);
							break;
						}
					}
					
				}
			}
			
		}
    }
}

