#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h" 
#include "Encoder.h"
int main(void){
  uint16_t num=0;
	OLED_Init();
	OLED_ShowChar(1,1,'A'); 
	Encoder_Init();
	while(1){
		
		num+=Encoder_Get();
	 OLED_ShowSignedNum(1,7,num,5);
		 
	}
}

