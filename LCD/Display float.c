//Embedded c program to display float value in LCD
#include<LPC21XX.H>
#include"delay.h"

#define LCD 0XFF
#define RS 1<<8
#define E 1<<9
void init();
void command(unsigned char);
void FLOAT(float);
void integer(unsigned int);
void data(unsigned char);

int main()
{
  init();
  command(0X80);
  FLOAT(23.4123);
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

void FLOAT(float f)
{
  int n,f2;
  n=f;
  integer(n);
  data('.');
  f2=(f-n)*1000;
  integer(f2);
}

void integer(unsigned int n)
{
  int a[10],i=0;
  while(n!=0)
  {
    a[i++]=n%10;
	n/=10;
  }
  for(--i;i>=0;i--)
  {
    data(a[i]+48);
  }
}

void data(unsigned char d)
{
  IOCLR0=LCD;
  IOSET0=d;
  IOSET0=RS;
  IOSET0=E;
  delay_millisec(2);
  IOCLR0=E;
}






