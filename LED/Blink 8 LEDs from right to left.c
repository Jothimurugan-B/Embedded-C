//Embedded C program for blinking 8 LEDs from right to left using "ARM based LPC2129 MICROCONTROLLER".
#include<LPC21XX.H>
void delay(int);
int main()
{	
  int i=0;
  IODIR0=0XFF; //configure p0.0 to p0.7 as output pins
  IOSET0=0XFF; //turn off LEDs initially (active low LEDs)
while(1)
{
  for(i=0;i<8;i++)
  {
	IOCLR0=1<<i; //Turn on selected LED
	delay(500);
	IOSET0=1<<i; //Turn off selected LED
	delay(500);  //for 500 millisec delay
	}
}
}
void delay(int t)
{
  T0PR=15000-1; //default value of Pclk 15 MHZ/sec.
  T0TCR=0X1;
  while(T0TC<t);
  T0TCR=0X3;
  T0TCR=0X0;
 } 


