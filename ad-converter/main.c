/*
 * ad-converter.c
 *
 * Created: 14.10.2018 21:48:17
 * Author : Marc
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "initialize.h"
#include "input.h"
#include "output.h"
#include "menu.h"

int choice;
char potValue;



int main(void)
{
	/** Initialize i/o ports **/
	initializePorts();	

	/** Initialize a/d conversion **/
	initializeConverter();

	/** Initialize serial interface UART 
	 * (baudrate: 9600, data bits: 8, parity bit: o (odd), stop bits: 1) **/
	initializeUart();
	
	choice = 1;

	/** Run forever**/
	while (1) 
    {
		// printMenu();
		// choice = getInputValue();
		switch(choice)
		{
			/** Button 1 **/
			case(1):
				printf("\nStarting: Display binary result of a/d conversion on leds (e.g. 10011100)\n");
				/** TODO: Get result of a/d conversion **/
				potValue = getPotValue();

				/** TODO: Trigger leds **/
				// char ledBytes = potValue;
				// char setLedBytes (ledBytes);
				setLedBytes(potValue);
				break;
			/** Button 2 **/
			case(2):
				printf("\nStarting: Send ASCII result over serial interface (e.g. 156)\n");
				/** TODO: Get result of a/d conversion **/
				potValue = getPotValue();
				
				/** TODO: Convert binary result to ASCII **/
				/*
				*/

				/** TODO: Send over serial **/
				setUartChar(potValue);
				break;
			/** Button 3 **/
			case(3):
				printf("\nStarting: Send real result over serial interface (e.g. 0.61 V)\n");
				/** TODO: Get result of a/d conversion **/
				potValue = getPotValue();
				
				/** TODO: Convert binary result to serial **/
				/*
				*/

				/** TODO: Send over serial **/
				setUartChar(potValue);
				break;
		}
	// Delay Loop
	int Time=0;
 	for(Time=0; Time <= 30000; Time++); //Delay Time
	}
    
}

