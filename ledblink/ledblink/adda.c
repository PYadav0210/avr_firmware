#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#include<avr/interrupt.h>

unsigned int val;
void _PWM_dac(void);
void _adc(void);

int main(void)
{
	sei();
	_adc();
	_PWM_dac();
	
	DDRB=1<<1;
	
	
	while(1)
	{
		ADCSRA|=1<<ADSC;//start Conversion
		while(!(ADCSRA & (1<<ADIF)));      // xxxxxxxcxxxx    1<<c   000000010000
		ADCSRA|=0<<ADIF;                   // 000000010000
		
		val=ADC;
		
		OCR1A=val;
		_delay_ms(10);
	}
}




void _adc(void){
	
	ADCSRA = 1<<ADEN; //enable Analog to Digital
	ADCSRA|=1<<ADATE;  //Auto tiggering enable
	ADCSRA|=0<<ADIE;
	//ADCSRA|=0<<ADIF;
	ADCSRA|=1<<ADPS2|1<<ADPS1|1<<ADPS0;
	ADCSRB = 0<<ADTS2|0<<ADTS1|0<<ADTS0;
	ADMUX = 0<<REFS1|1<<REFS0; //refrence voltage
	ADMUX|= 0<<ADLAR;
	ADMUX|=1<<0;
}



void _PWM_dac(void){
	
	TIMSK1=1<<OCIE1A;
	TCCR1A =  1<<WGM12|0<<WGM11|1<<WGM10|1<<COM1A1;   //PWM Bit setting 1<<WGM12|0<<WGM11|1<<WGM10 |
	TCCR1B = 0<<CS12|0<<CS11|1<<CS10; //   Prescalling to 1

}

ISR(TIMER1_COMPA_vect){
	
}