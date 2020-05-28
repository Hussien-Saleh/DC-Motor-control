/*
    a program to control a DC-Motor using three push-buttons
    requirements:
    - the three switches are connected to pin 0 & 1 & 2 in PORTA
    - connect switches using PULL DOWN configuration
    - IN1 & IN2 of the L293D chip are connected to first two pins in PORTC
    conditions:
    - if the first switch is pressed, motor rotates clockwise
    - if the second switch is pressed, motor rotates anticlockwise
    - if the third switch is pressed, motor should stop
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRA &= ~(0x07<<PA0); /* PA0, PA1 & PA2 as input pins */ 
	DDRC |= (0x03<<PC0); 	/* PC0 & PC1 as output pins */
	PORTC &= ~(0x03<<PC0); // motor is in equilibirum state
	 
  for(;;)
  {
		/* check if the first button is pressed */
		if(PINA & (1<<PA0))
		{
      // rotate clockwise
			PORTC &= (~(1<<PC0));
		  PORTC |= (1<<PC1);
		}
		
		/* check if the second button is pressed */
		else if(PINA & (1<<PA1))
		{
      // rotate anti-clock wise
			PORTC |= (1<<PC0);
			PORTC &= (~(1<<PC1));	
		}		
		/* check if the third button is pressed  */
		else if(PINA & (1<<PA2))
		{
      // stop the motor
			PORTC &= (~(1<<PC0));
			PORTC &= (~(1<<PC1));
		}				    
  }
}
