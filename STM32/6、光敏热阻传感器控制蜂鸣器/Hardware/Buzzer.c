#include "stm32f10x.h"                  // Device header

void Buzzer_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin= GPIO_Pin_6;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure); 
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
}

void Buzzer_ON(){

GPIO_ResetBits(GPIOA,GPIO_Pin_6);
}

void Buzzer_OFF(){

GPIO_SetBits(GPIOA,GPIO_Pin_6);
}

void Buzzer_Turn(){
if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_6)==0){
GPIO_SetBits(GPIOA,GPIO_Pin_6);
}else{
GPIO_ResetBits(GPIOA,GPIO_Pin_6);
}
}