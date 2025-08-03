//Embedded C program for LED blinking when switch is pressed using "ARM based LPC2129 MICROCONTROLLER".
#include<LPC21XX.H>
int main()
{
int i,j;
IODIR0=0XF; //set P0.0 to P0.3 as output pins
IOSET0=0XF; //Turn off all LEDs initially (active low)
while(1)
{
  for(i=4;i<8;i++)
  {
    if(((IOPIN0>>i)&1)==0)  //if switch press is detected
	{
	  j=i-4;
	  IOCLR0=1<<j;           //Turn on the LED
	}
   }
}
}
