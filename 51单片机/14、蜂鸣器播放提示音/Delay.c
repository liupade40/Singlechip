#include <INTRINS.h>
void Delay1ms(unsigned int ms)		//@11.0592MHz
{
	unsigned char i, j;
	while(ms--){ 
	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
	
}

