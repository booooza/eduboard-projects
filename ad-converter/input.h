/*
 * input.h
 *
 * Created: 14.10.2018 21:49:12
 *  Author: Marc
 */ 


#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>

int getInputValue()
{
	int input;
	scanf("%d", &input);
	return input;
}

int getButtonPressed()
{
	return 0;
}

char getPotValue()
{
	char potValue;
	ADCA.CH0.CTRL |= ADC_CH_START_bm; // Start Wandlung
	while(!ADCA.CH0.INTFLAGS); //Warte bis Wandlung abgeschlossen
	potValue= ADCA.CH0.RES; 
	return potValue;
}

#endif /* INPUT_H_ */