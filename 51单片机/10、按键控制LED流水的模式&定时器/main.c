#include <REGX52.H>


void Timer0_Init(){
	
	TMOD=0x01;
	//TMOD=TMOD&0xf0;//把TMOD的第四位清零，高四位保持不变
	//TMOD=TMOD&0x01;//把tmod的最低位置1，高四位保持不变
	TF0=0;
	TR0=1;
	TH0=64535/256;
	TL0=64535%256;
	ET0=1;
	EA=1;
	PT0=0;
	
	 	//定时器时钟12T模式
//	TMOD &= 0xF0;		//设置定时器模式
//	TMOD |= 0x01;		//设置定时器模式
//	TL0 = 0x66;		//设置定时初始值
//	TH0 = 0xFC;		//设置定时初始值
//	TF0 = 0;		//清除TF0标志
//	TR0 = 1;		//定时器0开始计时
//	ET0=1;
//	EA=1;
//	PT0=0;
} 
void Timer0Init(void)		//1毫秒@11.0592MHz
{
	TMOD=0x01; 
	//TMOD &= 0xF0;		//设置定时器模式
	TH0=64535/256;
	TL0=64535%256;
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
		ET0=1;
	EA=1;
	PT0=0;
}

void main(){

 Timer0Init();
	while(1){
	
		
	}
}
unsigned int T0Count;
void Timer0() interrupt 1 {
	TH0=64535/256;
	TL0=64535%256;
	T0Count++;
	if(T0Count>=1000){
	T0Count=0;
		
	P1_0=~P1_0;
	P1_1=~P1_1;
	P1_2=~P1_2;
	P1_3=~P1_3;
	}
	
}