#include <stdio.h>
#include <conio.h>
#define INTERFACE 0xb4c0 //look it up in device manager, whatever the addr is
int main()
{
	clrscr();
	//get a PCI/DAC interface. connect that huge ugly band to your old archaic computer and connect the CRO to the interface.
	int data=0x01 , mode=0; //mode 0 is increment mode, 1 is decrement
	for(;;) //forever and ever and ever.
	{
		outportb(INTERFACE,data); 
		if(data==0xFF || data==0x00) //peak or -ve peak reached
			(mode==0)?mode=1:mode=0; //flip mode
		if(mode==1)
			data--;
		else
			data++;
	}
}