/**
 * @file activity1.h
 * @author Akriti D
 * @brief header file for activity 1 for defining macros and the declarations of functions
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED
/**
 * @brief defining macros for activity1
 * 
 */
#define driverseat (PORTD0)
#define heater (PORTD1)
#define driverseat_switch_close !(PIND&(1<<PD0))
#define heater_switch_close !(PIND&(1<<PD1))
#define LED (PORTB0)

/**
 * @brief declarations of function
 * 
 */

void port_assignment();
int led_on();

#endif // ACTIVITY1_H_INCLUDED