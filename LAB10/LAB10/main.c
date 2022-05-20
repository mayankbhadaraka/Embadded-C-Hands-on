/*
 * LAB10.c
 *
 * Created: 20-04-2022 04:07:03 PM
 * Author : mayan
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
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

void convertndisplay(unsigned char value)
{
	unsigned char x,d1,d2;
	x=value/10;
	d1=x;
	d2=value%10;
	lcd_cmd(0X8D);
	lcd_data(d1+0x30);
	lcd_data(d2+0x30);
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
	lcd_cmd(0x80);
	lcd_data('T');
	lcd_data('E');
	lcd_data('M');
	lcd_data('P');
	lcd_data('E');
	lcd_data('R');
	lcd_data('A');
	lcd_data('T');
	lcd_data('U');
	lcd_data('R');
	lcd_data('E');
	lcd_data(':');
	
	DDRA |=(1<<0);
	ADCSRA = 0x87;    // make ADC enable and c/128
	ADMUX=0xE0;       // 2.56V Vref and ADC0 single ended data will be left justified
	while (1)
	{
		ADCSRA |= (1<<ADSC);
		while ((ADCSRA&(1<<ADIF))==0);
			unsigned char data=ADCH;
			convertndisplay(data);
			_delay_ms(500);
	}
	return 0;
}
