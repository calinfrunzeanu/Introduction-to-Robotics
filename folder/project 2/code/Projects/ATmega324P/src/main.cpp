#include <avr/io.h>
#include <util/delay.h>
 
int main() {
	DDRD |= (1 << PD5);
  DDRD |= (1 << PD7);

  DDRB &= ~(1 << PB2); 

  while ( 1 )
    {
    if ( DDRB & (1 << PB2) == 1 ) 
      {
        // PORTD ^= (1 << PD7);
        PORTD &~= PD5;
      }
    else
      { 
        // PORTD ^= (1 << PD5);
        PORTD &= ~(1 << PD7);
      }
    }
}