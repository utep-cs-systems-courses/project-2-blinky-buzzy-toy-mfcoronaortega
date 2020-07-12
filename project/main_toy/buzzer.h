#ifndef buzzer_included
#define buzzer_included

//defining notes and their corresponding frequency
#define f 370 
#define F 349
#define d 311
#define D 294
#define g 415
#define G 392
#define A 440

//declaring variables used in .c file
extern char play;
extern int notes [32];
extern int duration [32];
extern int delay [32];

void buzzer_init();
void buzzer_set_period(short cycles);

#endif // included
