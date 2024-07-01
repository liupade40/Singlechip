#include "stm32f10x.h" 
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"
#include "OLED.h"
 
int main(void){
		 OLED_Init();
		Buzzer_Init();
		LightSensor_Init();
		uint8_t s=0;
		while(1){
			s=LightSensor_Get();
			OLED_ShowNum(2,1,s,1);
		if(s==1){
		Buzzer_ON();
		
		}
else{

Buzzer_OFF();
}		
		}
	  
	}

