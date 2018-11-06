/*
 * clock-demo.c
 *
 * Created: 06.11.2018 18:36:53
 * Author : Marc
 */ 

#include <stdint.h>
#include <avr/io.h>

int main(void)
{
	OSC_CTRL |= OSC_XOSCEN_bm; // Enable external oscillator
	while (!(OSC_STATUS & OSC_XOSCEN_bm)); // Wait until oscillator is enabled
	CCP = CCP_IOREG_gc; // Configuration Change Protection = IO Register Protection
	// CLK - Clock System = System Clock Selection (External Crystal Oscillator or Clock)
	CLK_CTRL = CLK_SCLKSEL_XOSC_gc;

	/* 
	XOSC Oscillator =
	Oscillator Frequency Range = 2 - 9 MHz 
	External Oscillator Selection and Startup Time = 0.4-16 MHz XTAL - 16K CLK
	 */
	OSC_XOSCCTRL = OSC_FRQRANGE_2TO9_gc | OSC_XOSCSEL_XTAL_16KCLK_gc;
	
	PORTE_DIR = 0b00000001; // Set PORTE3 as Output (LED 8)
	
	TCE0_CTRLA = TC_CLKSEL_DIV64_gc; 	// TC0 (TCE0) - 16-bit Timer/Counter 0 = System Clock / 64
	/* 
	TC0 (TCE0) - 16-bit Timer/Counter 0 =
	Compare or Capture A Enable bit mask.
	Waveform Generation Mode (Frequency Generation Mode)
	*/
	TCE0_CTRLB = TC0_CCAEN_bm | TC_WGMODE_FRQ_gc;
	TCE0_CCA = 0x0fff; 	// TC0 (TCE0) - 16-bit Timer/Counter 0
	
	/* Replace with your application code */
	while (1)
	{
	}
	
}

