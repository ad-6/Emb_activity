/**
 * @file activity4.c
 * @author Akriti D
 * @brief Sending the microcontroller data using USART
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <avr/io.h>
#include "activity4.h"

/**
 * @brief USART is being initialised
 * 
 * @param temp 
 */
void USARTInit(uint16_t temp)
{
    UBRR0H=(temp>>8)&(0x00FF);
    UBRR0L=temp;

    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

/**
 * @brief Function to read the character received by USART
 * 
 * @return char 
 */
char USARTReadChar()
{
    while(!(UCSR0A&(1<<RXC0))){}
    return UDR0;
}

/**
 * @brief Function to send the data bythe USART
 * 
 * @param data 
 */
void USARTWriteChar(int data)
{
    while(!(UCSR0A&(1<<UDRE0))){}
    UDR0=data;
}

/**
 * @brief Approriate temperature is displayed 
 * 
 * @param temp 
 */
void display_temp(int temp)
{
    USARTInit(103);
    USARTWriteChar(temp);
}
