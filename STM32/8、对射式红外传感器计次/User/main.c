#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h" 
#include "CountSensor.h"
int main(void){
 
	OLED_Init();
	OLED_ShowChar(1,1,'A'); 
	CountSensor_Init();
	while(1){
	 OLED_ShowNum(1,7,CountSensor_Get(),5);
		 
	}
}

