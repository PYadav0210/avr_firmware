#include<avr/io.h>
#include<avr/interrupt.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<stdbool.h>


int main (void)
{
	sei();
	TIMSK1=1<<OCIE1A;
	TCCR1A =  1<<WGM12|0<<WGM11|1<<WGM10|1<<COM1A1;   //PWM Bit setting 1<<WGM12|0<<WGM11|1<<WGM10 |
	TCCR1B = 0<<CS12|0<<CS11|1<<CS10; //   Prescalling to 1
	
	DDRB=1<<1;
	int pwm = 0;
	//bool up= true;
	while(1)
	{
		OCR1A = pwm;
          //pwm +=up?1:-1;
		if(pwm==0xff)
		pwm=0;
		//up = false;
		else 
		pwm++;
		//up = true;
		_delay_ms(10);
	
		 
		
		 
	
	}
}

ISR(TIMER1_COMPA_vect)
{
	
	//PORTB =~PORTB;
	//_delay_ms(500);
	//cli();
}