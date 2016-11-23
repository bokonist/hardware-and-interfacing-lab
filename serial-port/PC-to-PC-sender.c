#include <bios.h>
#define SET (0x80|0x02|0x00|0x00) //settings. look here: http://electrosofts.com/serial/
//settings are 1200 baud,7 databits, 1 stop bit, no parity
#define PORT 0x3f8;
int main()
{
	clrscr();
	int in,out, status;
	bioscom(0,PORT,SET);
	//definition is bioscom(int command, int port, char abyte)
	//commands are 
	//0- init params to the port
	//1- send char to port
	//2- receive char from port
	//3- return the current status of the com port
	// the third param is useless when command is 1 or 2.
	// ro send a data, the format is bioscom(1,data,COM1)
	printf("Data received is: ");
	while(1)
	{
		status= bioscom(3,0,PORT); //wait till you get data
		if(status& 0x100) //check the third bit of status for Dataset ready signal
		{
			out=bioscom(2,0,PORT); //get the data
			if((out & 0x7F) != 0)
			{
				putch(out); //put it on screen
			}
		}
		if(kbhit()) //if keyboard is hit
		{
			in = getch(); //get it
			if(in == '~') //check != tilda
				break;
			bioscom(1,in,PORT); //send it
		}
	} 
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

from LSB to MSB [td, rd, dtr, dcd, dsr, ri, rts, cts, ground]