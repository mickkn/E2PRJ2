/*
 * Implementering af klasse UART
 *
 * RS232 driver
 *
 * Af Bjørn Sørensen
 *
 */

#include "UART.h"

UART::UART( unsigned long BaudRate, unsigned char databit )
{
	// Hvis BaudRate er mellem 110 og 115200 samt DataBit er mellem 5-9
	if((BaudRate >= 110 && BaudRate <= 115200) && (databit >= 5 && databit <= 9)) {
		
		unsigned char parity, mode, rxtx, stopbit, interrupt, ubrrValueH, ubrrValueL, dataBitUCSZ2 = 0, dataBitUCSZ10 = 0;
		long int ubrrValue;

		rxtx = 0b11;		// RXTX:
								// 00 = RXTX disabled
								// 01 = TX enable
								// 10 = RX enable
								// 11 = RXTX enable
								
		interrupt = 0b100;	// Interrupt enable:
								// 000 = Disable all interrupt
								// 1XX = Receive complete enable interrupt
								// X1X = Transmit complete enable interrupt
								// XX1 = Data register empty enable interrupt
								
		parity = 0b00;		// Parity:
								// 00 = Disable
								// 01 = Reserved
								// 10 = Even Parity
								// 11 = Odd Parity
								
		mode = 0b0;			// Mode: 0 = Asynchronous, 1 = Synchronous
		
		stopbit = 0b0;		// Stop-bit: 0 = 1 bit, 1 = 2 bit
		
		/*
		 * DO NOT EDIT BELOW !!!
		 */

		/*
		 * Baudrate setup
		 */
		ubrrValue = (F_CPU/(16*BaudRate))-1;	// Calculate value according to baudrate
		ubrrValueH = ubrrValue >> 8;			// Shift value right 8 bits to get high byte
		ubrrValueL = ubrrValue;					// Discard high byte
		
		UBRRH = ubrrValueH;	// Write high byte
		UBRRL = ubrrValueL; // Write low byte
		
		/*
		 * Databit set (Do not edit!)
		 */
		switch(databit) {
			case 5:		// 000
				dataBitUCSZ2 = 0;
				dataBitUCSZ10 = 00;
				
			case 6:		// 001
				dataBitUCSZ2 = 0;
				dataBitUCSZ10 = 0b01;
						
			case 7:		// 010
				dataBitUCSZ2 = 0;
				dataBitUCSZ10 = 0b10;
								
			case 8:		// 011
				dataBitUCSZ2 = 0;
				dataBitUCSZ10 = 0b11;
								
			case 9:		// 111
				dataBitUCSZ2 = 1;
				dataBitUCSZ10 = 0b11;
		}
							
		UCSRB = (rxtx << 3)|(interrupt << 5)|(dataBitUCSZ2 << UCSZ2); // Write to UCSRB					
		UCSRC = (1 << URSEL)|(mode << UMSEL)|(parity << UPM0)|(stopbit << USBS)|(dataBitUCSZ10 << UCSZ0); // Write to UCSRC (Do not edit!)	
	}
}

UART::~UART( )
{
	// Disable RXTX and INT
	UCSRB = (00 << 3)|(000 << 5); // Write to UCSRB
	
}

// Returnerer 0 når der ikke er modtaget en char, ellers <> 0
char UART::charReady( )
{
	return ((1 << RXC) & UCSRA);
}

// Afventer char og returnerer når den er modtaget
char UART::readChar() {
	
	while(!charReady() );

	return UDR;
	
}

// Afventer afsendelses buffer klar og afsender char
void UART::sendChar(char tegn)
{
	
	while(!((1 << UDRE) & UCSRA));
	
	UDR = tegn;
	
}

// Afsender 0-termineret char streng
void UART::sendString(char* streng) {
	unsigned char i = 0;
	
	while(streng[i] != '\0')
	{
		sendChar(streng[i]);
		i++;
	}
	
}

// Definer globale variable
char dataIn[COMMAND_SIZE];
unsigned char volatile dataCount;
unsigned char volatile commandReady;

// Globalt UART objekt
UART RS232UART (9600, 8);

// RS232 Modtage data interrupt
ISR (USART_RXC_vect)
{
	// Hent UART char
	dataIn[dataCount] = UDR;
	
	// Kontroller STX og ETX samt frame størrelse
	if((dataIn[0] == 'S' || dataIn[0] == 's') && (dataIn[COMMAND_SIZE - 1] == '\r') && (dataCount >= (COMMAND_SIZE - 1))	)
	{
		// Flag sættes for kommando klar
		commandReady = 1;

		// Counter nulstilles
		dataCount = 0;
		
	}
	// Hvis frame overskrides
	else if(dataCount >= (COMMAND_SIZE - 1))
	{
		// Tøm buffer
		for(unsigned char i = 0; i < COMMAND_SIZE; i++)
		dataIn[i] = 0;
		
		// Counter nulstilles
		dataCount = 0;
		
		// Flag nulstilles
		commandReady = 0;

	}
	// Ellers incrementer counter
	else
		dataCount++;

}