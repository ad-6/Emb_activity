/**
 * @file activity4.h
 * @author Akriti D
 * @brief header file for function declarations of activity 4
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED

/**
 * @brief function declarations
 *
 */
void USARTInit(uint16_t);
char USARTReadChar();
void USARTWriteChar(int);
void display_temp(int);

#endif // ACTIVITY4_H_INCLUDED
