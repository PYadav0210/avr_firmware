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
     
    
	 TIMSK1=1<<TCNT1;
	 TCCR1B=1<<CS02|0<<CS01|1<<CS00;
	 
	   
	 DDRD = 1<<5;
	
	while(1)
	{
	 sei(); //enable interrupt

	
	}
		
	
}

ISR(TIMER1_OVF_vect)
{
	
	PORTD=~PORTD;
	cli();
}

