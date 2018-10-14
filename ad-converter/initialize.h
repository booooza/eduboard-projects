/*
 * initialize.h
 *
 * Created: 14.10.2018 21:50:28
 *  Author: Marc
 */ 


#ifndef INITIALIZE_H_
#define INITIALIZE_H_

int initializePorts()
{
    printf("Initializing i/o ports...\n");
    
	// Port PF0 ... PF3 = Ausgang (LED1 .. LED4)

	//PortF0 ... PortF3 = Ausgang (LED1 .. 4) - PortF4 ... PortF7 = Eingang (Taster)	
 	PORTF.DIR = 0x0f;
	
	//PortE0 ... PortE3 = Ausgang (LED 5 .. 8)
	PORTE.DIR = 0x0f; 
	
	// char ledBytes = 0x00;
	// setLedBytes(ledBytes);
	
	// LED 1-4 = off
	PORTF.OUT = 0b11111111;	
	
	// LED 5-8 = off
	PORTE.OUT = 0b11111111;	
	
    return 1;
}

int initializeConverter()
{
    printf("Initializing a/d conversion...\n");
    
	// Setze PortB0 als Output (Pot1)
	PORTA.DIR = 0x00;
	
	// Aul?sung = 8bit unsigned
	ADCA.CTRLB = ADC_RESOLUTION_8BIT_gc;
	
	// Referenzspannung = Bandgap 1.0V
	ADCA.REFCTRL = ADC_REFSEL_INT1V_gc | ADC_BANDGAP_bm ; 
	
	// ADC Clockteiler = 4
	ADCA.PRESCALER = ADC_PRESCALER_DIV4_gc;
	
	// Enable Wandler (freigeben)
	ADCA.CTRLA = ADC_ENABLE_bm;
	
	//Eingangspin und Wandlungsart f?r Kanal0 festlegen
	ADCA.CH0.CTRL = ADC_CH_INPUTMODE_SINGLEENDED_gc; //Single ended Modus
	ADCA.CH0.MUXCTRL = ADC_CH_MUXPOS_PIN8_gc; //ADCPin 8 = Mess-Eingang
	
    return 1;
}

int initializeUart()
{
    printf("Initializing serial interface UART...\n");
    /*	
	//bestimmen der Baudrate
	USARTC0_BAUDCTRLA = 0x0c;
	USARTC0_BAUDCTRLB = 0x00;
	
	//Senden und Empfangen freigeben
	USARTC0_CTRLB = USART_TXEN_bm | USART_RXEN_bm;
	
	//Protokoll bestimmen
	USARTC0_CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_ODD_gc | USART_CHSIZE_8BIT_gc;
	PORTC_DIR = PIN3_bm;
	*/
    return 1;
}

#endif /* INITIALIZE_H_ */