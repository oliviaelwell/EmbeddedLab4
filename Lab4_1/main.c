#include <msp430.h>
int main(void)
{
    WDTCTL = WDT_ADLY_250;                      // WDT 250ms, SMCLK, interval timer
    P6OUT &= ~BIT6;                             //Assigns output 
    P6DIR |= BIT6;                              // Assigns output 
    PM5CTL0 &= ~LOCKLPM5;                     
    SFRIE1 |= WDTIE;                            //Enables the watchdog interupt 
    _enable_interrupts();                       //Enables the interrupt 
    while (1);
    }
    #pragma vector=WDT_VECTOR                   //Assign vector to timer 
    __interrupt void wdtled(void)               //Loop for checking if interupt 
    {
            P6OUT^=BIT6;                       // Turns on LED 
    }
