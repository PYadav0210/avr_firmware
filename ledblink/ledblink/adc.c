#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/interrupt.h>

int main(void)
{
	ADCSRA = 1<<ADEN; //enable Analog to Digital
	ADCSRA|=1<<ADATE;  //Auto tiggering enable
	ADCSRA|=0<<ADIE;
	//ADCSRA|=0<<ADIF;
	ADCSRA|=1<<ADPS2|1<<ADPS1|1<<ADPS0;
	ADCSRB = 0<<ADTS2|0<<ADTS1|0<<ADTS0;
	ADMUX = 0<<REFS1|1<<REFS0; //refrence voltage
	ADMUX|= 0<<ADLAR;
	ADMUX|=1<<0;
	DDRD=0xff;
	while(1)
	{
		ADCSRA|=1<<ADSC;//start Conversion
		while(!(ADCSRA & (1<<ADIF)));       xxxxxxxcxxxx    1<<c   000000010000
		ADCSRA|=0<<ADIF;                    000000010000
		
		PORTD=ADC&0b11111000;
	}
}
	
