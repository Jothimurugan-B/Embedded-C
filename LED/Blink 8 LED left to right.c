//Embedded C program for blinking 8 LED from left to right using "ARM based LPC2129 MICROCONTROLLER".
#include<LPC21XX.H>
#include "delay.h" //here including delay code as h file.

int main()
{	
 int i=0;
 IODIR0=0XFF;  // Configure P0.0 to P0.7 as output
 IOSET0=0XFF;  // Turn off all LEDs initially (active low LEDs)
while(1)
{
  for(i=7;i>=0;i--)
  {
   IOCLR0=1<<i; //Turn on selected LED
	 delay_millisec(500);
	 IOSET0=1<<i; //Turn off selected LED
	 delay_millisec(500);
	}
}
}
