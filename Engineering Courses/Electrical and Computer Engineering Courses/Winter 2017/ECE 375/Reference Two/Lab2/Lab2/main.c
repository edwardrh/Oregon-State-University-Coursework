
/*
This code will cause a TekBot connected to the AVR board to
move forward and when it touches an obstacle, it will reverse
and turn away from the obstacle and resume forward motion.

PORT MAP
Port B, Pin 4 -> Output -> Right Motor Enable
Port B, Pin 5 -> Output -> Right Motor Direction
Port B, Pin 7 -> Output -> Left Motor Enable
Port B, Pin 6 -> Output -> Left Motor Direction
Port D, Pin 1 -> Input -> Left Whisker
Port D, Pin 0 -> Input -> Right Whisker
*/

#define F_CPU 16000000 //
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main(void)
{
	DDRB = 0b11110000;      // configure Port B pins for input/output
	PORTB = 0b11110000;     // set initial value for Port B outputs
	// (initially, disable both motors)

	DDRD = 0b00000000;      // configure Port D pins for input/output

	while (1) { // loop forever

		PORTB = 0b01100000;     // make TekBot move forward
		_delay_ms(500);         // wait for 500 ms
		
		if (PIND == 0b11111110) { //Right Whisker Hit
			PORTB = 0b00000000;     // move backward
			_delay_ms(500);         // wait for 500 ms
			PORTB = 0b01000000;     // turn right
			_delay_ms(500);        // wait for 500 ms
		}
		else if ((PIND == 0b11111101)) { //Left Whisker Hit
			PORTB = 0b00000000;     // move backward
			_delay_ms(500);         // wait for 500 ms
			PORTB = 0b00100000;     // turn left
			_delay_ms(500);        // wait for 500 ms
		}
		else if ((PIND == 0b11111100)) { //Both Whiskers Hit
			PORTB = 0b00000000;     // move backward
			_delay_ms(500);         // wait for 500 ms
		}
	}
}
