#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void KEY_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Pin= GPIO_Pin_6|GPIO_Pin_8;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure); 
}



Direction Key_GetDirection(){
	Direction keyNum=Direction.None;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0){
	
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0);
		Delay_ms(20);
		keyNum=Direction.Up;
	
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==0){
	
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==0);
		Delay_ms(20);
		keyNum=Direction.Down;
	
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0){
	
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0);
		Delay_ms(20);
		keyNum=Direction.Left;
	
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0){
	
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0);
		Delay_ms(20);
		keyNum=Direction.Right;
	
	}
	return keyNum;

}
