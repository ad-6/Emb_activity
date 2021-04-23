#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

unsigned volatile FLAG = 0;
unsigned volatile FLAG1 = 0;

int main(void)
{
DDRB|=(1<<PB0);

DDRD&=~(1<<PD2);
PORTD|=(1<<PD2);
DDRD&=~(1<<PD3);
PORTD|=(1<<PD3);

EICRA|=(1<<ISC01)|(1<<ISC11);
EIMSK|=(1<<INT0)|(1<<INT1);

sei();

    while(1)
    {
            if(FLAG==1 && FLAG1==1)
            {
            PORTB|=(1<<PB0);
            _delay_ms(4000);
            FLAG = 0;
            FLAG1 = 0;
            }
            else
            {
            PORTB&=~(1<<PB0);
            _delay_ms(1000);
            }
    }

    return 0;
}

ISR(INT0_vect)
{
    FLAG = 1;
}

ISR(INT1_vect)
{
    FLAG1 = 1;
}
