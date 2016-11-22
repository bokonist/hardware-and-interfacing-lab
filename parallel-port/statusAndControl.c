#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define PPORT 0x378 //or whatever the address is. look in device manager.
int main()
{
	clrscr();
	int data;
	data = inportb(PPORT+1); // input 1 byte of hex data from the specified port. PPORT+1 is the status register.
	printf("Data in status register is\n");
	printf("Pin 15: %d",(data&0x08)/0x08);
	printf("Pin 13: %d",(data&0x10)/0x10);
	printf("Pin 12: %d",(data&0x20)/0x20);
	printf("Pin 11: %d",(data&0x40)/0x40);
	printf("Pin 10: %d",(data&0x80)/0x80);

	data= inportb(PPORT+2); // PPORT+2 is the control register
	printf("Data in the control register is\n");
	printf("Pin 1: %d",(data&0x01)/0x01);
	printf("Pin 14: %d",(data&0x02)/0x02);
	printf("Pin 16: %d",(data&0x04)/0x04);
	printf("Pin 17: %d",(data&0x08)/0x08);
	getch();
	return 0;
}

Pin No (DB25)		Signal name			Direction			Register-bit
1					Strobe				In/Out				/Control-0 			{/control means active low}
2					Data0				Out					Data-0
3					Data1				Out					Data-1
4					Data2				Out					Data-2
5					Data3				Out					Data-3
6					Data4				Out					Data-4
7					Data5				Out					Data-5
8					Data6				Out					Data-6
9					Data7				Out					Data-7
10					Ack					In					Status-6
11					Busy				In					/Status-7
12					Paper-Out			In					Status-5
13					Select				In					Status-4
14					Linefeed			In/Out				/Control-1
15					Error				In					Status-3
16					Reset				In/Out				Control-2
17					Select-Printer		In/Out				/Control-3
18-25				Ground				-					-	-

control pins from MSB to LSB is 17,16,14,1 - 4 bits
status pins from MSB to LSB is 11,10,12,13,15 - 5 bits