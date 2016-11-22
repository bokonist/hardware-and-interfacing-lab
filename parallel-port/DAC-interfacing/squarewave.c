#include <stdio.h>
#include <conio.h>
#define INTERFACE 0xb4c0 //look it up in device manager, whatever the addr is
int main()
{
	clrscr();
	//get a PCI/DAC interface. connect that huge ugly band to your old archaic computer and connect the CRO to the interface.
	for(;;) //forever and ever and ever.
	{
		outportb(INTERFACE,0xFF); 
		delay(1000);
		outportb(INTERFACE,0x00);
		delay(1000);
	}
}