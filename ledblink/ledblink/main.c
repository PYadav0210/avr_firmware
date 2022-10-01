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
	PORTD = 1<<2;
	DDRD = 1<<2;
	while(1)
	{
		PORTD =~PORTD;
		_delay_ms(1000);
	
	}
		
	
}

ISR(XXX_vect)
{
	
}

