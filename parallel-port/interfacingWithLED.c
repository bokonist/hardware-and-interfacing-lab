#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define PPORT 0x378 //or whatever the address is. look in device manager.
int main()
{
	clrscr();
	//first, connect your LED to pins 2 and 9 of the 25pin DB connector
	for(;;) //blink forever
	{
		outportb(0xFF,PPORT); //light em up
		delay(1000);
		outportb(0x00,PPORT); //turn off
		delay(1000);
	}
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