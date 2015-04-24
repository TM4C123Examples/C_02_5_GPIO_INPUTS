#include "TM4C123.h"   // Device header
int main(){
	SYSCTL->RCGCGPIO|=(0x1<<5);//Activamos Periferico GPIOF
	GPIOF->DEN|=0xFF;
	GPIOF->DIR|=(0x1<<1)|(0x1<<2)|(0x1<<3);//GPIO[3:1] as output
	GPIOF->PUR|=(0x1<<4);
	
	int estado=0;
	int color=0;
	
	while(1){
		if((GPIOF->DATA&(0x1<<4))){
			 GPIOF->DATA|=(color<<1)&0xE;
			 estado=0;
		}else{
			 GPIOF->DATA&=0xFFFFFFFF&(0x0<<1)&(0x0<<2)&(0x0<<3);
			 if(estado==0){
				 color++;
			 } 
			 estado=1;
		}
	}
	
	return 0;
}
