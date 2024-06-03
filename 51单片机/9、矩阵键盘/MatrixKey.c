#include <REGX52.H>
#include "Delay.h"
unsigned char MatrixKey(){

	unsigned char KeyNumber=0;
	P0=0xff;
	P3_4=0;
	if(P3_0==0){
		Delay1ms(20);
		while(P3_0==0);
		Delay1ms(20);
		KeyNumber=1;
	}
	if(P3_1==0){
		Delay1ms(20);
		while(P3_1==0);
		Delay1ms(20);
	KeyNumber=5;
	}
	if(P3_2==0){
		Delay1ms(20);
		while(P3_2==0);
		Delay1ms(20);
		KeyNumber=9;
	}
	if(P3_3==0){
		Delay1ms(20);
		while(P3_3==0);
		Delay1ms(20);
		KeyNumber=13;
	}
	return KeyNumber;
}