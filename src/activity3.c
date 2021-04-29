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
#include "activity2.h"

/**
 * @brief Set the pwm object
 *
 */
void set_pwm()
{
    TCCR1A |=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB|=(1<<PB1);
}

/**
 * @brief generates the PWM corresponfing to the temparature recorded.
 *
 * @param temp_recorded - the output of temperature sensor i.e activity 2
 * @return uint8_t temperature output for display
 */
int temperature(uint16_t temp_recorded)
{
    set_pwm();
    if ((temp_recorded>=0) && (temp_recorded<=200))
    {
        OCR1A=205;
        return 20;
    }

    else if ((temp_recorded>=210) && (temp_recorded<=500))
    {
        OCR1A=410;
        return 25;
    }

    else if ((temp_recorded>=510) && (temp_recorded<=700))
    {
        OCR1A=717;
        return 29;
    }

    else
    {
        OCR1A=972;
        return 33;
    }

}
