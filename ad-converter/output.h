/*
 * output.h
 *
 * Created: 14.10.2018 21:49:58
 *  Author: Marc
 */ 


#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdio.h>



void setLedBytes (char ledBytes)
{	
	ledBytes = ~ledBytes;									// Variable wird negiert
	PORTF.OUT = (PORTF.OUT & 0xF0);									// PORTF wird mit UND Maskiert
	PORTF.OUT = ((PORTF.OUT & 0x0F) | (ledBytes & 0x0F));		// PORTF wird mit UND Maskiert, nur F wird beschrieben. Variable writeledbyte ebenfalls mit UND Maskiert, low nibble wird ins PORTF übertragen
	PORTE.OUT = (PORTE.OUT & 0xF0);									// PORTE wird mit UND Maskiert
	PORTE.OUT = ((PORTE.OUT & 0x0F) | ((ledBytes & 0xF0) >> 4));// PORTF wird mit UND Maskiert, nur F wird beschrieben. Variable writeledbyte ebenfalls mit UND Maskiert high nibble und dann wird die high nibble um 4 mal nach rechts geshiftet und dann ins PORTF übertragen
}



void setUartChar (char uartChar)
{
	printf("Sending uart character: %c\n", uartChar);
}

#endif /* OUTPUT_H_ */