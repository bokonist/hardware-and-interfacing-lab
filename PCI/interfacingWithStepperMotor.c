#include <stdio.h>
#include <conio.h>
#define INTERFACE 0xb4c0
int main()
{
	//get a PCI/DAC interface. connect that huge ugly band to your old archaic computer and connect the stepper motor to the interface.
	int i,j, look[] = {0x09, 0x05,0x06,0x0A};
	clrscr();
	//if you want to rotate it clockwise 360 degrees, run this following loop 360/7.2 times. just reverse the look[] array for counter-clockwise
	for(i=0;i<50;i++)
	{
			for (j = 0; j < 4; ++j)
			{
				outportb(INTERFACE, look[j]);
				delay(100); //slow it down a bit
			}
	}
}