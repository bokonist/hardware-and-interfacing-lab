#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define SPORT 0x3f8 //look it up in device manager
int x1,y1,x2,y2; //screen coordinates for printing results

void resetxy(int &a, int &b, int &ch) //to reset the coordinates if they go out of bounds, goto newline if the char is 'enter' etc etc
{
	if(a==81 || ch== 13)
	{
		a=1;
		b++;
	}
}

int main()
{
	clrscr();
	int data;
	x1=1; x2=1; y1=3; y2=14;
	char td,dsr,rd,a; // td- transmitted data, rd- received data, dsr- datasetready signal
	gotoxy(1,1);
	printf("Received message:\n");
	gotoxy(1,13);
	printf("Transmitted message\n");
	gotoxy(1,26);

	//setting up UART stuff
	outportb(SPORT+1,0x03); //setting for rs232 interrupt
	outportb(SPORT+3,0x80); //set DLAB on
	outportb(SPORT,0x03); //set baud rate. latch low byte.
	outportb(SPORT+1,0x00); //setbaud rate. latch high byte.
	outportb(SPORT+3,0x03); //8 bits, no parity, 1 stop bit
	outportb(SPORT+2,0xC7); //FIFO control register
	//these are all in the function defintion of init_rs232(word port, byte divisor). which inits the RS232 interface with the bps[baud rate] value of divisor.
	//look into that fuction and use that instead. include serial.h 

	//init_rs232(SPORT, 0x03); // do this instead of all this confusing shit above. may work. don't know for sure.

	do
	{
		td=getch();
		if(td!='~') // enter ~ to end comms
		{
			gotoxy(x1,y1+1); 
			outportb(SPORT,td); //send it
			putch(td); //put that char on screen
			x1++; // printing-coordinate altering stuff.
			resetxy(x1,y1,td); //keep it in bounds
			do
			{
				dsr= inportb(SPORT+5); //get the dataset ready signal
				if(dsr&0x01) //check the relevant pin. dataset is ready.
				{
					gotoxy(x2,y2+1); //goto the "received messages tab"
					rd = inportb(SPORT); //get the data
					putch(rd);
					x2++;
					resetxy(x2,y2,rd);
				}
			}while(!(dsr&0x01)); // keep receiving data as long as the dataset ready signal is high
		}
	}while(!(td&0x01)); //keep sending data from user till ~ is entered
	getch();
	return 0;

}

Serial Port pin config.

Name						Pin number (DB-9 connector)
Transmitted Data 			3	
Received Data 				2
Data Terminal Ready			4
Data Carrier Detect			1
Data Set Ready				6
Ring Indicator				9
Request To Send				7
Clear To Send				8
Signal Ground				5

from MSB to LSB [td, rd, dtr, dcd, dsr, ri, rts, cts, ground]