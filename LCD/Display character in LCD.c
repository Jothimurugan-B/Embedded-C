//Embedded C program to display a character in LCD display
#include<LPC21XX.H>
#include"delay.h" //Including delay code as header

#define LCD 0XFF
#define RS 1<<8
#define E 1<<9

void init();
void command(unsigned char);
void data(unsigned char);
int main()
{
   init();
   command(0X80); //display the character in the address (0X80)
   data('B'); //intended to display character 'B'
  
 }
 void init()
 {
   IODIR0=0X3FF;
   command(0X1);
   command(0X2);
   command(0X0C);
   command(0X38);
  }

  void command(unsigned char cmd)
  {
  IOCLR0=LCD;
	IOSET0=cmd;
	IOCLR0=RS;
	IOSET0=E;
	delay_millisec(2); //here delay is provided for internal operations of LCD to be finished
	IOCLR0=E;
  }

  void data(unsigned char ch)
  {
  IOCLR0=LCD;
	IOSET0=ch;
	IOSET0=RS;
	IOSET0=E;
	delay_millisec(2);
	IOCLR0=E;
  }


   
