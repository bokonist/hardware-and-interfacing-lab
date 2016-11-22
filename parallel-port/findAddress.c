#include <conio.h>
#include <dos.h>

unsigned int far *ptraddr; //In a segmented architecture computer, a far pointer is a pointer
// which includes a segment selector, making it possible to point to addresses outside of the default segment.

unsigned int addr;
int a;

int main()
{
	clrscr();
	ptraddr = (unsigned int far*) 0x00000408; //0x00000408 is the location of port addresses
	for (a = 0; a < 3; ++a)
	{
		addr= *ptraddr;
		if(addr ==0)
			printf("no port found for LPT %d\n",a+1);
		else
			printf("address assigned to LPT %d is %x\n", a+1, addr);
		ptraddr++;
	}
	return 0;
}