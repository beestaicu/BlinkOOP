/*
 * Button_LED_swtich.c
 *
 * Created: 22/05/2020 14:20:55
 * Author : bee
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int led_switch(); // Define switch function
int led_circle(); // Define circle function
int i = 0;

int main(void)
{
	DDRD = 0XFF;        // Set port D all is output
	DDRB = 0b00000001;  // Set B0 as input
	PINB |= 0b00000001; // Set B0 connect to pull-up resistor
	while(1){
		/*if(!(PINB & 0b00000001)){
			memory ^=1;
			if (memory == 0){
				led_circle();
				_delay_ms(100);
			}
			else if (memory == 1){
				led_switch();
				_delay_ms(100);
			}
		}
	}*/
		if (!(PINB & 0b00000001)){
			if (i == 0){
				i = 1;
			}
			else if(i == 1){
				i = 0;
			}
			
			
		}
		
			if (i == 0){
					led_circle();
			}
	
				else if (i ==1){
						led_switch();
						
			}
		}
	
	
}


int led_switch(){
	PORTD = 0X00;       // Initialise portD pins all is low
	PORTD = 0b10101010; // Set port1,3,5,7 is high, 0,2,4,6 is low
	_delay_ms(1000);    // Delay one second
	PORTD = 0b01010101; // Set port port 1,3,5,7 is low, 0,2,4,6 is high
	_delay_ms(1000);    // Delay one second
}

int led_circle(){
	PORTD = 0X00;                // Initialise portD all is low
	int array[8] = {PORTD0, PORTD1, PORTD2, PORTD3, PORTD4, PORTD5, PORTD6, PORTD7}; // Define an arrray for store the portd pins
	int i,j;                     // define i and j
	for (i = 0; i <8; i++){ 
		PORTD |= (1<<array[i]);  // Set port0->7 to high one-by-one
		_delay_ms(100);
	}
	for (j = 7; j >0; j--){
		PORTD &=~ (1<<array[j]); // Set port 7->0 to low one-by-one
		_delay_ms(100);
	}
}