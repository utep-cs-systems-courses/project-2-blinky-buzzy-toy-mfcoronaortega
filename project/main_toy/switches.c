#include <msp430.h>
#include "switches.h"
#include "led.h"

char sw1_down, sw2_down, sw3_down, sw4_down , switch_state_changed; /* effectively boolean added remaining switches to demo file*/

static char switch_update_interrupt_sense(){
  char p1val = P1IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void switch_init(){			/* setup switch */  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler(){
  
  char p1val = switch_update_interrupt_sense();
  sw1_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  sw2_down = (p1val & SW2) ? 0 : 1;
  sw3_down = (p1val & SW3) ? 0 : 1;
  sw4_down = (p1val & SW4) ? 0 : 1;
  switch_state_changed = 1;
  led_update();

  //switch actions
  if(sw1_down){ //if sw1 is down plays the song from buzzer
    reset_state();
    play_song = 1;

  }
  else if(sw2_down){
    //do something
  }
  else if(sw3_down){
    //do something different
  }
  else if(sw4_down){
    //do something different
  }
}
