//Embedded C program for providing delay using "ARM based LPC2129 MICROCONTROLLER".
#include<LPC21XX.H>
void delay_sec(int);
void delay_millisec(int);
void delay_microsec(int);

int main()
{
  delay_sec(1);
  delay_millisec(500);
  delay_microsec(1000);
}
void delay_sec(int t)
{
  T0PR=15000000-1; //Default value of Pclk is 15 MHZ.
  T0TCR=0X1;
  while(T0TC<t);
  T0TCR=0X3;
  T0TCR=0X0;
 }
void delay_millisec(int t)
{
  T0PR=15000-1;
  T0TCR=0X1;
  while(T0TC<t);
  T0TCR=0X3;
  T0TCR=0X0;
 }
void delay_microsec(int t)
{
  T0PR=15-1;
  T0TCR=0X1;
  while(T0TC<t);
  T0TCR=0X3;
  T0TCR=0X0;
 }


