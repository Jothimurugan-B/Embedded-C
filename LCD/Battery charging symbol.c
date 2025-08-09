//Embedded C program to display battery charging animation in LCD.
#include<LPC21XX.H>
#include"lcd string.h" //including 'display the string' code as header
unsigned int a[]={0X0E,0X1B,0X11,0X11,0X11,0X11,0X1F,0X00,
                  0X0E,0X1B,0X11,0X11,0X11,0X1F,0X1F,0X00,
                  0X0E,0X1B,0X11,0X11,0X1F,0X1F,0X1F,0X00, 
				  0X0E,0X1B,0X11,0X1F,0X1F,0X1F,0X1F,0X00,   
                  0X0E,0X1B,0X1F,0X1F,0X1F,0X1F,0X1F,0X00,
				  0X0E,0X1F,0X1F,0X1F,0X1F,0X1F,0X1F,0X00} ;
void cgram(unsigned int);
int main()
{
  unsigned int i;
  init();
  command(0X80);
  string("bat charging:");
  cgram(48);
  while(1){
 
  for(i=0;i<6;i++){
  delay_millisec(1000);
   command(0X8D);
  data(i);
  
  }
  }
 }
void cgram(unsigned int n)
{
  int i;
  command(0X40);
  for(i=0;i<n;i++)
  data(a[i]);
}

   

