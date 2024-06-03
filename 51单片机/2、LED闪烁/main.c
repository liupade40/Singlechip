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


sbit d1=P1^0;
void main(){
	while(1){
		d1=0;
		Delay500ms();
		d1=1;
		Delay500ms();
	}
}
