#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char sec;
void main(){
	
	UartInit();
	
	while(1){
		Uart_SendByte(sec);
		sec++;
		Delay1ms(1000);
	}
}