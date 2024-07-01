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



uint8_t Key_GetNum(){
	uint8_t keyNum=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0){
	
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0);
		Delay_ms(20);
		keyNum=1;
	
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0){
	
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0);
		Delay_ms(20);
		keyNum=2;
	
	}
	
	return keyNum;

}
