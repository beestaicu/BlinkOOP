/*
 * LED_Matrix.c
 *
 * Created: 24/05/2020 12:44:32
 * Author : bee
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#define my_delay2 1
#define my_delay 100

int vertical();					// function to call in main
int horizontal();				// function to call in main
int vertical_dot();				// function to call in main
int horizontal_dot();			// function to call in main
int vertical_per_dot();			// function to call in vertical()
int horizontal_per_dot();		// function to call in horizotal()

// for number 

int i;
int c[5] = {0b11111110,0b11111101,0b11111011,0b11110111,0b11101111}; // port c 01234low
int b1[5] = {0b00000000,0b00100100,0b00111110,0b00100000,0b00000000}; // number 1
int b2[5] = {0b00000000,0b00111010,0b00101010,0b00101110,0b00000000}; // number 2
int b3[5] = {0b00000000,0b00101010,0b00101010,0b00111110,0b00000000}; // number 3
int b4[5] = {0b00000000,0b00001110,0b00001000,0b00111110,0b00000000}; // number 4
int b5[5] = {0b00000000,0b00101110,0b00101010,0b00111010,0b00000000}; // number 5
int b6[5] = {0b00000000,0b00111110,0b00101010,0b00111010,0b00000000}; // number 6
int b7[5] = {0b00000000,0b00000010,0b00000010,0b00111110,0b00000000}; // number 7
int b8[5] = {0b00000000,0b00111110,0b00101010,0b00111110,0b00000000}; // number 8
int b9[5] = {0b00000000,0b00101110,0b00101010,0b00111110,0b00000000}; // number 9
int b0[5] = {0b00000000,0b00111110,0b00100010,0b00111110,0b00000000}; // number 0
int j;
int number_1();
int number_2();
int number_3();
int number_4();
int number_5();
int number_6();
int number_7();
int number_8();
int number_9();
int number_0();

// for character


int main(void){

	DDRB = 0b00111111;			// Set B0,1,2,3,4,5 as output for positive LED
	DDRC = 0b00011111;			// Set C0,1,2,3,4 as output for negative LED
	PORTB = 0x00;				// clear port b
	PORTC = 0x00;				// clear port c
	while(1){
		vertical();				
		horizontal();			
		vertical_dot();			
		horizontal_dot();		
		number_1();
		number_2();
		number_3();
		number_4();
		number_5();
		number_6();
		number_7();
		number_8();
		number_9();
		number_0();
	
	}
} //end main


number_1(){
	
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b1[i];
			_delay_ms(my_delay2);
		}
	}
	
}

number_2(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b2[i];
			_delay_ms(my_delay2);
		}
	}
}

number_3(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b3[i];
			_delay_ms(my_delay2);
		}
	}
}

number_4(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b4[i];
			_delay_ms(my_delay2);
		}
	}
}

number_5(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b5[i];
			_delay_ms(my_delay2);
		}
	}
}

number_6(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b6[i];
			_delay_ms(my_delay2);
		}
	}
}

number_7(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b7[i];
			_delay_ms(my_delay2);
		}
	}
}

number_8(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b8[i];
			_delay_ms(my_delay2);
		}
	}
}

number_9(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b9[i];
			_delay_ms(my_delay2);
		}
	}
}

number_0(){
	for(j = 0; j<100; j++){
		for (i = 0; i<5; i++){
			PORTC = c[i];
			PORTB = b0[i];
			_delay_ms(my_delay2);
		}
	}
}

vertical(){
	//vertical
	
	PORTB = 0b00111111; // B0,1,2,3,4,5 high
	PORTC = 0b11111110; // C0 low
	_delay_ms(my_delay);
	PORTC = 0b11111101; // c1 low
	_delay_ms(my_delay);
	PORTC = 0b11111011; // c2 low
	_delay_ms(my_delay);
	PORTC = 0b11110111; // c3 low
	_delay_ms(my_delay);
	PORTC = 0b11101111; // c4 low
	_delay_ms(my_delay);
}

horizontal(){
	//horizontal
	PORTC = 0b00000000; // port c low
	PORTB = 0b00000001; // b0 high
	_delay_ms(my_delay);
	PORTB = 0b00000010; // b1 high
	_delay_ms(my_delay);
	PORTB = 0b00000100; // b2 high
	_delay_ms(my_delay);
	PORTB = 0b00001000; // b3 high
	_delay_ms(my_delay);
	PORTB = 0b00010000; // b4 high
	_delay_ms(my_delay);
	PORTB = 0b00100000; // b5 high
	_delay_ms(my_delay);
}

vertical_per_dot(){
	PORTC = 0b11111110; // C0 low
	_delay_ms(my_delay);
	PORTC = 0b11111101; // C1 low
	_delay_ms(my_delay);
	PORTC = 0b11111011; // C2 low
	_delay_ms(my_delay);
	PORTC = 0b11110111; // C3 low
	_delay_ms(my_delay);
	PORTC = 0b11101111; // C4 low
	_delay_ms(my_delay);
}

horizontal_per_dot(){
	PORTB = 0b00000001; // b0 high
	_delay_ms(my_delay);
	PORTB = 0b00000010; // b1 high
	_delay_ms(my_delay);
	PORTB = 0b00000100; // b2 high
	_delay_ms(my_delay);
	PORTB = 0b00001000; // b3 high
	_delay_ms(my_delay);
	PORTB = 0b00010000; // b4 high
	_delay_ms(my_delay);
	PORTB = 0b00100000; // b5 high
	_delay_ms(my_delay);
}

vertical_dot(){
	// one dot for horizontal
	//clear port B,C
	PORTB = 0x00;
	PORTC = 0x00;
	// first row
	PORTB = 0b00000001; // B0 high
	vertical_per_dot();
	// second row
	PORTB = 0b00000010; // B1 high
	vertical_per_dot();
	// third row
	PORTB = 0b00000100; // B2 high
	vertical_per_dot();
	// forth row
	PORTB = 0b00001000; // B3 high
	vertical_per_dot();
	//fifth row
	PORTB = 0b00010000; // B4 high
	vertical_per_dot();
	//sixth row
	PORTB = 0b00100000; // B5 high
	vertical_per_dot();
}

horizontal_dot(){
	// one dot for vertical
	
	// first column
	PORTC = 0b11111110; // c0 low
	horizontal_per_dot();
	// second column
	PORTC = 0b11111101; // c1 low
	horizontal_per_dot();
	// third column
	PORTC = 0b11111011; // c2 low
	horizontal_per_dot();
	// forth column
	PORTC = 0b11110111; // c3 low
	horizontal_per_dot();
	//fifth column
	PORTC = 0b11101111; // c4 low
	horizontal_per_dot();
}
