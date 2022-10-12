#include<avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 16000000UL
#include<util/delay.h>


int main (void)
{
	sei();
	TIMSK1=1<<OCIE1A;
	TCCR1A = 0<<WGM02|1<<WGM01|0<<WGM00;   //CTC Bit setting
	TCCR1B = 1<<CS02|0<<CS01|0<<CS00; //   Prescalling in 64
	OCR1A = 20000;
	DDRD=1<<5;
	while(1){
		if (OCR1A == 20000)
			OCR1A = 0;
		else
			OCR1A++;
	}
}

ISR(TIMER1_COMPA_vect)
{
	PORTD = ~PORTD;
	cli();
}