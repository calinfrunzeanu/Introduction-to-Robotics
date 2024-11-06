#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define FREQ0 100
#define FREQ1 200
#define FREQ2 300

volatile uint8_t freq = 0; // Variabila pentru frecvență
volatile uint8_t btn2 = 0; // Variabila pentru starea butonului 2

ISR(TIMER1_COMPA_vect) {
    /* Alternarea valorii buzzer-ului */
    if (btn2) {
        PORTD ^= (1 << PD4); // Activează/dezactivează buzzer-ul
    }
}

ISR(INT2_vect) {
    // Schimbăm frecvența la fiecare apăsare a butonului PD6
    freq = (freq + 1) % 3; // Incrementăm și ne asigurăm că rămânem între 0 și 2

    // Setăm frecvența corespunzătoare
    switch (freq) {
        case 0:
            OCR1A = (uint16_t)(F_CPU / (8 * FREQ0) - 1);
            PORTD |= (1 << PD5); // Aprindem LED-ul roșu pentru 100Hz
            PORTD &= ~(1 << PD7); // Stingem LED-ul verde
            break;
        case 1:
            OCR1A = (uint16_t)(F_CPU / (8 * FREQ1) - 1);
            PORTD &= ~(1 << PD5); // Stingem LED-ul roșu
            PORTD |= (1 << PD7); // Aprindem LED-ul verde pentru 200Hz
            break;
        case 2:
            OCR1A = (uint16_t)(F_CPU / (8 * FREQ2) - 1);
            PORTD |= (1 << PD5) | (1 << PD7); // Aprindem ambele LED-uri pentru 300Hz
            break;
    }
}

int main() {
    /* Setup LEDs */
    DDRD |= (1 << PD5); // LED roșu
    DDRD |= (1 << PD7); // LED verde
    DDRB |= (1 << PB3); // LED albastru

    /* Aprindem LED-ul roșu */
    PORTD &= ~(1 << PD5);
    PORTD |= (1 << PD7);
    PORTB |= (1 << PB3);

    /* Setup buttons */
    DDRB &= ~(1 << PB2); // PB2 ca intrare
    PORTB |= (1 << PB2); // Activăm rezistența de pull-up

    DDRD &= ~(1 << PD6); // PD6 ca intrare
    PORTD |= (1 << PD6); // Activăm rezistența de pull-up

    /* Setup Buzzer */
    DDRD |= (1 << PD4); // Pinul buzzer-ului ca ieșire

    /* Set timer1 on mode CTC */
    TCCR1B |= (1 << WGM12);

    /* Init frequency */
    freq = 0; // Frecvența inițială
    OCR1A = (uint16_t)(F_CPU / (8 * FREQ0) - 1); // Setăm frecvența inițială

    /* Set timer1 prescaler to 8 */
    TCCR1B |= (1 << CS11);

    /* Enable compare with OCR1A interrupt */
    TIMSK1 |= (1 << OCIE1A);
    sei();

    /* Set INT2 to activate on falling edge */
    EICRA |= (1 << ISC21);  // Corect: doar flanc descendent
    EIMSK |= (1 << INT2); // Activăm întreruperea externă INT2

    while (1) {
        // Verificăm starea butonului 2 pentru a activa/dezactiva buzzerul
        if (!(PINB & (1 << PB2))) { // Verificăm dacă butonul PB2 este apăsat
            btn2 = 1; // Activăm buzzer-ul
            _delay_ms(50); // Debouncing simplu
        } else {
            btn2 = 0; // Dezactivăm buzzer-ul
        }
    }

    return 0;
}
