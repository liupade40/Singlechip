#include <REGX52.H>
#include <INTRINS.h>

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

 unsigned char LEDNum;
void main(){
	//P1=~0x01;
	while(1){
		if(P3_4==0){
		 Delay1ms(20);
			while(P3_4==0){
			
			};
			Delay1ms(20);
			
			if(LEDNum>=8){
			LEDNum=0;
			}
			P1=~(0x01<<LEDNum);
			LEDNum++;
		}
		if(P3_5==0){
		 Delay1ms(20);
			while(P3_5==0){
			
			};
			Delay1ms(20);
			
			if(LEDNum==0){
			LEDNum=7;
			}
			else{ 
			LEDNum--;
			}
			P1=~(0x01<<LEDNum);
		}
	}
}
