/**
 * @file seatheating.c
 * @author Akriti D
 * @brief
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

/**
 * @brief this function is responsible for the execution
 *
 * @return int 0, if executed succesfully
 */


int main()
{
    uint16_t temp_recorded=0;
    int temp_display;

    while(1)
    {
        int led_configuration;
        led_configuration=led_on();
        if (led_configuration==1)
        {
           temp_recorded=read_temp();
           temp_display=temperature(temp_recorded);
           display_temp(temp_display);
        }
    }

    return 0;
}
