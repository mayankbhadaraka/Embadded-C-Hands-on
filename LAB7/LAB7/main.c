#include <avr/io.h>
#define F_CPU 16000000UL
#include <stdio.h> 
#include <util/delay.h>

void lcd_cmd(unsigned char cmd) //create function to send commands to lcd
{
	PORTD = cmd; //using PortD for sending  command
	PORTC = 0x04; //using PortC for controlling lcd with RS,RW, Enable  	
	_delay_ms(10);
	PORTC = 0x00;
}
void lcd_data (unsigned char data)
{
	PORTD = data; //using PortB for sending data
	PORTC = 0x05; //using PortC for controlling lcd with RS,RW, Enable  	
	_delay_ms(10);
	PORTC = 0x01;
}
void lcd_init ()
{
	
	lcd_cmd(0x38); 
	lcd_cmd(0x0F);
	
	lcd_cmd(0x01);
	
	} 
int main(void) {
	DDRB = 0xFF;  	
	DDRC = 0xFF;
	lcd_init();
	while (1)
	{
		lcd_cmd(0x80);
		
		lcd_data('H');  	 	
		_delay_ms(500);  	 	
		lcd_data('E');  	 	
		_delay_ms(500);  	 	
		lcd_data('L');  	 	
		_delay_ms(500);  	 	
		lcd_data('L');  	 	
		_delay_ms(500);  	 	
		lcd_data('O');  	 	
		_delay_ms(500);
		
		
		lcd_cmd(0xC0);
		
		lcd_data('E');  	 	
		_delay_ms(500);  	 	
		lcd_data('S');  	 	
		_delay_ms(500);
		
		
	}
}
