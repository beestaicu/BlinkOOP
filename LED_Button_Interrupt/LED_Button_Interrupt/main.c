/*
 * LED_Button_Interrupt.c
 *
 * Created: 23/05/2020 13:23:45
 * Author : bee
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
void led_switch();
void led_circle();
uint8_t button_state();
uint8_t i=0;

ISR(INT0_vect){
	i^=1; // toggles the state of variable i
	PORTC ^= (1<<PINC0); //toggles the state of LED on PINC0 
	_delay_ms(300); 
}

int main(void)
{
DDRD = 0b11111011; // set port d as output apart d2 input
DDRC = 0xff; // set all pins on port c as output
PORTD = 0X00; // initialize all port d to low
EIMSK |= (1<<INT0); // Turns on INT0 (on pin D2)
sei();


    while (1) 
    {
		if (i == 1){
			led_switch();
    }
	else if (i == 0){
		led_circle();
		} 
	} // end while
} // end main
void led_switch(){
	PORTD = 0b10101010; // Set port 1,3,5,7 is high, 0,2,4,6 is low
	_delay_ms(100);
	PORTD = 0b01010101; // Set port 1,3,5,7 is low, 0,2,4,6 is high
	_delay_ms(100);
}

void led_circle(){
	// Define an array for store
	int array[8] = {PORTD0, PORTD1, PORTD2, PORTD3, PORTD4, PORTD5, PORTD6, PORTD7};
	int i,j;
	for (i = 0; i <8; i++){
		PORTD |= (1 <<array[i]); // set port 0->7 to high one-by-one
		_delay_ms(100);
	}
	for (j = 7; j >0;j--){
		PORTD &=~ (1<<array[j]); // set port 7->0 to low one-by-one
		_delay_ms(100);
	}
	
}