#include <REGX52.H>
#include "Delay.h"

sbit Buzzer=P2^3;
unsigned int i;
void main(){
	
	while(1){
		if(P3_4==0){
		for(i=0;i<50;i++){
		
		Buzzer=!Buzzer;
			Delay1ms(1);
		}
		}
	}
}