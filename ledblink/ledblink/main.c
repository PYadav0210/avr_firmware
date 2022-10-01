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
	DDRD = 0xFF;
	
}

ISR(XXX_vect)
{
	
}

