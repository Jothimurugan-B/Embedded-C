//Embedded C program for basic LED blinking using "ARM based LPC2129 MICROCONTROLLER".
#include<LPC21XX.H>
void delay(unsigned int);
int main()
{
IODIR0=0X1;
while(1)
{
IOCLR0=0X1;
delay(2);
IOSET0=0X1;
delay(2);
}
}

void delay(unsigned int t)
{
T0PR=15000000-1; //Default Pclk value of LPC2129 is 15 MHZ.
T0TCR=0X1;
while(T0TC<t);
T0TCR=0X3;
T0TCR=0X0;
}
