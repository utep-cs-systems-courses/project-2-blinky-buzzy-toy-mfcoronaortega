#include <msp430.h>
#include buzzer.h
#include libTimer.h

void main(void){
  configureClocks();
  
  buzzer_init();
  enableWDTInterrupts();
  
  or_sr(0x18);//CPU OFF GIE ON
}

