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
	printf("Pin 15 (Error): %d",(data&0x08)/0x08); // & with 		00001000
	printf("Pin 13 (Select): %d",(data&0x10)/0x10); // & with 		00010000
	printf("Pin 12 (Paper-Out): %d",(data&0x20)/0x20); // & with 	00100000
	printf("Pin 10 (Ack): %d",(data&0x40)/0x40); // & with 			01000000
	printf("Pin 11 (Busy): %d",(data&0x80)/0x80); // & with 		10000000

	data= inportb(PPORT+2); // PPORT+2 is the control register
	printf("Data in the control register is\n");
	printf("Pin 1 (Strobe): %d",(data&0x01)/0x01);  	// & with 		00000001
	printf("Pin 14 (Linefeed): %d",(data&0x02)/0x02);	// & with 		00000010
	printf("Pin 16 (Reset): %d",(data&0x04)/0x04);		// & with 		00000100
	printf("Pin 17 (Select Printer): %d",(data&0x08)/0x08);// & with 	00001000
	getch();
	return 0;
}

Pin No (DB25)		Signal name			Direction			Register-bit
1					Strobe				In/Out				/Control-0
2					Data0				Out					Data-0
3					Data1				Out					Data-1
4					Data2				Out					Data-2
5					Data3				Out					Data-3
6					Data4				Out					Data-4
7					Data5				Out					Data-5
8					Data6				Out					Data-6
9					Data7				Out					Data-7
10					Ack				In					Status-6
11					Busy				In					/Status-7
12					Paper-Out			In					Status-5
13					Select				In					Status-4
14					Linefeed			In/Out					/Control-1
15					Error				In					Status-3
16					Reset				In/Out					Control-2
17					Select-Printer			In/Out					/Control-3
18-25					Ground					-				-	-

{/control means active low}

control pins from MSB to LSB is 17,16,14,1 - 4 bits [SP,R,L,S]
status pins from MSB to LSB is 11,10,12,13,15 - 5 bits [B,A,P,S,E]
data pins from MSB to LSB is 9,8,7,6..2 - 8 bits.