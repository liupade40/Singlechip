#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h" 
#include "Encoder.h"
int main(void){
  uint16_t num=0;
	uint16_t num2=1;
	OLED_Init(); 
	while(1){
		 
		OLED_ShowString(1,1,"Score:");
		OLED_ShowNum(1,7,999,3);
		OLED_ShowString(1,11,"Snake");
		 OLED_ShowNum(2,7,1,3);
		OLED_ShowNum(3,7,2,3);
		OLED_ShowNum(4,7,3,3);
		
		Delay_s(1);
	}
}

