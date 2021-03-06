/**
 * @file activity2.c
 * @author Akriti D
 * @brief ADC driver for temperature sensor; conveting analod output to binary number
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include "activity2.h"

/**
 * @brief Initializing ADC registers
 *
 */
void InitADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
/**
 * @brief to call the ADC when led is turned on in the acrivity 1
 *
 * @param ch
 * @return uint16_t
 */

uint16_t ReadADC(uint8_t ch)
{
    ADMUX&= 0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|= (1<<ADSC);
    while(!(ADCSRA & (1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

/**
 * @brief function to generate the duty cycle 
 * 
 * @return int 
 */
int read_temp(void)
{
    InitADC();
    uint16_t temp;
    while(1)
    {
        temp= ReadADC(0);
        return (temp);

    }
}

