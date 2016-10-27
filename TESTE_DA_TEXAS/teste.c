#include <msp430g2452.h>
#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>

#define LED1_MASK       0x01
#define LED2_MASK       0x40
#define TIME_START 300//100 //160/3
/*
TIME_START 500 --> 6,51 seg
TIME_START 300 --> 3,53 seg
TIME_START 100 --> 0,55 seg
*/


void delay_ms(unsigned int delay);

int main(void)
{
    volatile int i = 0;
    float a=9.5;
    int *j=NULL;
    a*=5;
    j = (int *) malloc(1000*sizeof(int));
    if(j!=NULL || j!=0){
           free(j);
    }
//     stop watchdog timer
    WDTCTL = WDTPW | WDTHOLD;

//     set P1 direction 
    P1DIR = LED1_MASK | LED2_MASK;

//     leds off 
    P1OUT = 0x00;

    while(1){
//        toggle leds 
        P1OUT = (LED1_MASK);

//       delay 
    delay_ms(TIME_START);


//        toggle leds 
        P1OUT = (LED2_MASK);

//       delay 
    delay_ms(TIME_START);



//        for (i = 0; i < 10000; i++);
    }
}



/**
* Takes a value in parameter in order to have a delay.
* 16,000 is equal to 16,000,000 / 1,000.
* -> 16,000,0000 = 16MHz (the CPU clock speed).
*/
void delay_ms(unsigned int delay)
{
    while (delay--)
    {
        __delay_cycles(16000);
    }
}
