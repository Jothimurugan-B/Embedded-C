//Embedded c program to display an integer in LCD.
#include<LPC21XX.H>
#include"delay.h"

#define LCD 0XFF
#define RS 1<<8
#define E 1<<9

void init();
void command(unsigned char);
void integer(unsigned int);
void data(int);

int main()
{
  init();
  command(0X80);
  integer(2304);
}

void init()
{
  IODIR0=0X3FF;
  command(0X01);
  command(0X02);
  command(0X0C);
  command(0X38);
}

void command(unsigned char cmd)
{
  IOCLR0=LCD;
  IOSET0=cmd;
  IOCLR0=RS;
  IOSET0=E;
  delay_millisec(2);
  IOCLR0=E;
}

void integer(unsigned int n)
{
  int i=0,a[10];
  while(n!=0){
  a[i++]=n%10;
  n=n/10;
  }
  for(--i;i>=0;i--)
  data(a[i]+48);
}

void data(int d)
{
  IOCLR0=LCD;
  IOSET0=d;
  IOSET0=RS;
  IOSET0=E;
  delay_millisec(2);
  IOCLR0=E; 
}


