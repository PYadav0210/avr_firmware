/*
 * ledblink.c
 *
 * Created: 10/1/2022 6:58:45 PM
 * Author : ypurs
 */ 

#include<avr/io.h>
#define F_CPU 16000000UL               //Define CPU clock
#include <util/delay.h>
#include<avr/interrupt.h>

int main (void)
{
     
     sei(); //enable interuupt
	 EIMSK=1<<INT0;
	 EICRA=1<<0|0<<1;
	 DDRD = 1<<4|1<<5|1<<6;
	while(1)
	{
		_delay_ms(500);
		PORTD = 1<<4;
		_delay_ms(500);
		PORTD = 1<<5;
		_delay_ms(500);
		PORTD = 1<<6;
		
	
	
	}
		
	
}

ISR(INT0_vect)
{
	int i=0;   
	while (i<3)
	{
		PORTD=1<<4|1<<5|1<<6;
		_delay_ms(500);
		PORTD=0;
		_delay_ms(1000);
		i++;
		
	}
	cli();
}

