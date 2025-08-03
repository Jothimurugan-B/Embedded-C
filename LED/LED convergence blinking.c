//Embedded C program for blinking LEDs in convergence pattern using "ARM based LPC2129 MICROCONTROLLER".
#include<LPC21XX.H>
void delay(int);
int main()
{	
int i,j;
   IODIR0=0XFF; // Set P0.0–P0.7 as output
   IOSET0=0XFF; // Turn off all LEDs initially (active low LEDs)
  while(1)
{
  for(i=0,j=7;i<=j;i++,j--)
  {
   
	IOCLR0=1<<i | 1<<j; //Turn on selected 2 LEDs
	delay(500);
	IOSET0=1<<i | 1<<j; //Turn off selected 2 LEDs 
	delay(500);  //providing 500 milliseconds delay
	}
}
}
void delay(int t)
{
  T0PR=15000-1;
  T0TCR=0X1;
  while(T0TC<t);
  T0TCR=0X3;
  T0TCR=0X0;
 } 


