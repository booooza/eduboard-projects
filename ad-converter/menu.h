/*
 * menu.h
 *
 * Created: 14.10.2018 21:50:47
 *  Author: Marc
 */ 


#ifndef MENU_H_
#define MENU_H_

int printMenu()
{
	printf("\n--- MENU ---\n");
	printf("Press a button\n");
	printf("1 - Display binary result of a/d conversion on leds (e.g. 10011100)\n");
	printf("2 - Send ASCII result over serial interface (e.g. 156)\n");
	printf("3 - Send real result over serial interface (e.g. 0.61 V)\n");
	printf("Selection: \n");
	return 0;
}

#endif /* MENU_H_ */