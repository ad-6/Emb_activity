/**
 * @file main.c
 * @author AD
 * @brief To turn on an LED when both switch inputs are 1
 * @version 0.1
 * @date 2021-04-24
 *
 * @copyright Copyright (c) 2021
 *
 */


#include <avr/io.h>

/**
 * @brief main function for the process of turning on the LED
 *
 * @return return 0 if the program executes successfully
 */


int main(void)
{

    /**
     * @brief Setting the direction of the pins D0 and D1 as input
     *
     * @note for driver's detection on seat , D0 is set as input
     *
     * @note for detection of heater, D1 is set as input
     *
     */



    DDRD&=~(1<<PD0);
    DDRD&=~(1<<PD1);

    /**
     * @brief internal supply of 5V to D0 and D1 (default pull-up)
     *
     */

    PORTD|=(1<<PD0);
    PORTD|=(1<<PD1);

    /**
     * @brief Setting the direction of the pin B0 as output (LED)
     *
     */

    DDRB|=(1<<PB0);



    while(1)
    {
        /* LED turns on only when both the switches are pressed */
        if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD1)))
            PORTB|=(1<<PB0);


        else
            PORTB&=~(1<<PB0);

    }

    return 0;
}
