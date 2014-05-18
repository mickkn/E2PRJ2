/*************************************************
* "LED.C":                                       *
* Implementation file for the STK500 LED driver. *
* The LEDs are connected to PC pins.             *
* Henning Hargaard, 26/3 2012                    *
**************************************************/
#include <avr/io.h>
#include "led.h"

#define MAX_LED_NR 7

#define OUTPUT_PORT PORTB
#define INPUT_PORT PINB
#define DIRECTION_PORT DDRB

void initLEDport()
{
	// Initialiser port C som output
	DIRECTION_PORT = 0xFF;
	
	// Sluk alle dioder
	OUTPUT_PORT= 0xFF;
}

void writeAllLEDs(unsigned char pattern)
{
  // Hent parameteren, vend alle bit, og skriv til lysdioderne
  // Bittene skal vendes, da HW er indrettet, 
  // så et 0 vil tænde en lysdiode
  OUTPUT_PORT = ~pattern;   
}

void turnOnLED(unsigned char led_nr)
{
// Lokal variabel
unsigned char mask;
  // Vi skal kun lave noget, hvis led_nr < 8
  if (led_nr <= MAX_LED_NR)
  {
    // Dan maske på basis af parameteren (led_nr)
    mask = ~(0b00000001 << led_nr);
    // Tænd den aktuelle lysdiode (de andre ændres ikke)
    OUTPUT_PORT = INPUT_PORT & mask;
  }   
}

void turnOffLED(unsigned char led_nr)
{
	
	unsigned char mask;
	
	// Controllere at LED_nr er inden for grænsen
	if(led_nr <= MAX_LED_NR)
	{
		// Maske som skal ORes med OUTPUT
		mask = 0b1 << led_nr;
		
		OUTPUT_PORT = INPUT_PORT | mask;
	}
	
}

void toggleLED(unsigned char led_nr)
{
	
	unsigned char mask;
		
	// Controllere at LED_nr er inden for grænsen
	if(led_nr <= MAX_LED_NR)
	{
		// Maske til at læse bit
		mask = 0b1 << led_nr;
		
		// Ex-Or output
		OUTPUT_PORT = INPUT_PORT ^ mask;
	}
	
}
