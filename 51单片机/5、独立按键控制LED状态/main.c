#include <REGX52.H>
#include<INTRINS.h>
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
	if(P3_4==0){
		Delay1ms(20);
		while(P3_4==0);
		Delay1ms(20);
		P1_0=~P1_0;
	}
	}
}