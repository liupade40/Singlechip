#include <REGX52.H>
#include "UART.h"
#include "Delay.h"


void main(){

	UartInit();
	while(1){
		
	}
} 
void Uart_Routine() interrupt 4
{
	if(RI==1){ 
		P1=SBUF;
		Uart_SendByte(SBUF);
		RI=0;
	}	
	
		
}