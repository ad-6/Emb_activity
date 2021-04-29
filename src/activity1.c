/**
 * @file activity1.c
 * @author Akriti D
 * @brief To turn on the LED on when the driver seat is occupied and heater is turned on
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include "activity1.h"

/**
 * @brief function for port assigments (creating library)
 *
 */
void port_assignment()
{


    DDRD&=~(1<<driverseat);
    DDRD&=~(1<<heater);
    PORTD|=(1<<driverseat);
    PORTD|=(1<<heater);


    DDRB|=(1<<LED);
}

/**
 * @brief Initiating Activity1
 *
 * @return int 1 when the condition of both driver seat and heater switch are closed
 */
int led_on()
{

    port_assignment();
    while(1)
    {
        /* return 1 and turn on the led when both driverseat and heater switch are close */
        if((driverseat_switch_close) && (heater_switch_close))
        {
            PORTB|=(1<<LED);
            return 1;
        }

        /* return 0 and turn off the led/ keep the led turned off */
        else
        {
            PORTB&=~(1<<LED);
            return 0;

        }

    }

}
