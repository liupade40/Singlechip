#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void){
//RCC->APB2ENR=0x00000010;
//GPIOC->CRH=0x00300000;
//GPIOC->ODR=0x00002000;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_Initstructure;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstructure); 
	 
	while(1){
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
		Delay_ms(500);
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		Delay_ms(500);
}
}
