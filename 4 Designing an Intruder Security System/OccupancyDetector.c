/*
 * OccupancyDetector.c
 *
 *  Created on: Jan 31, 2023
 *      Author: John Schiede
 */
#include <msp430.h>

int main(void){
    #define ARMED_STATE 0
    #define WARNING_STATE 1
    #define ALERT_STATE 2

    // Put some initialization here
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    // Configure GPIO
    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P6OUT &= ~BIT6;                         // Clear P6.6 output latch for a defined power-on state
    P6DIR |= BIT6;                          // Set P6.6 to output direction

    P2DIR &= ~BIT1;                        // Set 2.1 as an input
    P4DIR &= ~BIT1;                        // set button 4.1 as an input

    char state = ARMED_STATE;              //initialize variables
    int i =0;
    int num = 0;
    while(1)
    {


        switch (state) {
        case ARMED_STATE:
        {
            // Do something in the ARMED state
            // If something happens, you can move into the WARNING_STATE
            // state = WARNING_STATE
            if(i>10000)
                P6OUT ^= BIT6;           //set Green LED to 1
                i =0;
            else
                i++;                    //set increment i
            if(P2IN & BIT1)
            {
                state = WARNING_STATE;

                break;
            }
            else
                break;
        }
        case WARNING_STATE:
        {

            // Do something in the WARNING_STATE
            P6OUT = ~BIT6;          //Turn off green LED
            if(i>5000)
            {
                P1OUT ^= BIT0;           // blink RED LED once every second 500ms on 500 ms off
                i=0;
                num++;
            }
            else
                i++;
            if(P2IN & BIT1 && num>=10) // go to Alert state if it has been more than 10 seconds and sensor is still high
            {
                state = ALERT_STATE;
                num = 0;
                break;
            }
            else if(!(P2IN & BIT1)) // go to armed state if sensor is low
            {
                state = ARMED_STATE;
                break;
            }
            else
                break;
        }
        case ALERT_STATE:
        {
            P1OUT = BIT0;//RED LED on
            if(P4IN & BIT1){
                state = ARMED_STATE;
                break;
            }

            else
                break;
        }

        }

    }

}


