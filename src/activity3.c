/**
 * @file activity3.c
 * @author Akriti D
 * @brief Finding the temparature that will be displayed
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include "activity3.h"

/**
 * @brief Set the pwm object
 * 
 */
void set_pwm()
{
    TCCR0A |=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    TCCR0B|=(1<<CS00)|(1<<CS01);
}

/**
 * @brief generates the PWM corresponfing to the temparature recorded.
 * 
 * @param temp_recorded - the output of temperature sensor i.e activity 2
 * @return uint8_t temperature output for display
 */
uint8_t temperature(uint16_t temp_recorded)
{
    set_pwm();
    if (0<=temp_recorded && temp_recorded<=200)
    {
        OCR1A=205;
        return 20;
    }

    else if (210<=temp_recorded && temp_recorded<=500)
    {
        OCR1A=410;
        return 25;
    }

    else if (510<=temp_recorded && temp_recorded<=700)
    {
        OCR1A=716;
        return 29;
    }

    else
    {
        OCR1A=972;
        return 33;
    }

}