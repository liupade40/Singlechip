#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "KEY.h"
#include "Delay.h"
 uint8_t keyNum=0;
int main(void){
//RCC->APB2ENR=0x00000010;
//GPIOC->CRH=0x00300000;
//GPIOC->ODR=0x00002000;

	 LED_Init();
	 KEY_Init();
	while(1){
	
	keyNum = Key_GetNum();
		if(keyNum==1){
	LED1_Turn();
		}
		
		if(keyNum==2){
	LED2_Turn();
		}
		 
	}
}

