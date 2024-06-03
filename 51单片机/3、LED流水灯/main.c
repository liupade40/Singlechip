#include <REGX52.H>
#include <INTRINS.h>
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms){
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
	
}

 
void main(){
	while(1){
		P1=0xfe;
		Delay1ms(500);
		P1=0xfd;
		Delay1ms(500);
		P1=0xfb;
		Delay1ms(500);
		P1=0xf7;
		Delay1ms(500);
	}
}
