#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)		/*NOW INCLUDES ALL*/

void switch_init();
void switch_interrupt_handler();

extern char sw1_down, sw2_down, sw3_down, sw4_down, switch_state_changed; /* effectively boolean now includes all switch states*/

#endif // included
