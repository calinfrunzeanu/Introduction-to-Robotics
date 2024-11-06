#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "usart.h"
#include "timers.h"
#include "colors.h"
#include "sound.h"
// Function prototype for convert_HSV_to_RGB


/* Configuration constants: */
#define PM_BAUD 28800

#define RGB_PULSE  1
#define RGB_HSV    2

#define LED_ANIMATION  RGB_HSV
#define SPEAKER_ENABLED 0


/**
 * Initialize the GPIOs of LEDs / speaker etc.
 */
int GPIO_init() {
    /* RGB led directions & default PORTs to 1 (OFF state) */
    DDRB |= (1 << PB3);
    DDRD |= (1 << PD5) | (1 << PD7)| (1 << PD4);
    PORTB |= (1 << PB3);
    PORTD |= (1 << PD5) | (1 << PD7) ;
    
}

int main() {
    /* initialize peripheral modules: */
    GPIO_init();
    USART0_init(CALC_USART_UBRR(PM_BAUD));
    USART0_use_stdio();

    if (SPEAKER_ENABLED) {
        Timer1_init_ctc();
    } else {
        Timer1_init_pwm();
        Timer0_init_pwm();
    }
    Timer2_init_systicks();
    /* TODO add more init() calls here? */

    sei(); /* activate global interrupts */

    printf("It's timer hammer!\n");

    unsigned int last_ping = 0;

    while (1) {
        /* Print alive message */
        if (SYSTICKS_PASSED(last_ping, 3000)) {
            last_ping = systicks;
            printf("Stayin' alive! [ticks=%i]\n", systicks);
        }
        if (LED_ANIMATION == RGB_PULSE) {
            /*
             * Pulse de LEDs based on a triangle wave:
             * y = (P - abs(t % (2*P) - P) )
             * Note: outputs values between [0, 3000]!
             */
          
            // /* rescale [0, 3000] to [0, 255] using ceil(3000 / 255) */
            // OCR1A = (wave / 12);
            // OCR0A = (wave / 12);
            // OCR2B = (wave/  16);
            /* TODO task 1 & 2: do the same for other LEDs */

        } else if (LED_ANIMATION == RGB_HSV) {
    uint8_t rgb_values[3];
    int color_wave = (systicks % 12000 < 6000) ? (systicks % 6000) : (12000 - systicks % 12000);
    float hue = (color_wave * 360.0) / 6000.0;
    convert_HSV_to_RGB(hue, 1.0, 1.0, rgb_values);
    OCR0A = rgb_values[0];
    OCR1A = (rgb_values[1] * 200) / 188;
    OCR2B = rgb_values[2];
}

        if (SPEAKER_ENABLED) {
            /* TODO task 4 (bonus): you know what you have to do ;) */
        }
    }
return 0;
}