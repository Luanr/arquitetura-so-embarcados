/*
 * File:   seven_seg.c
 * Author: luan
 *
 * Created on May 30, 2019, 3:07 PM
 */
#include <xc.h>

void seven_seg_init(void) {
    // seta os tris maluku
    TRISA = 0b11000000;
    PORTA = 0b00000000;
}

void seven_seg_set(int display, int number) { // entrada 7 por exemplo

    if(display == 1) {
        PORTA = PORTA & 0b11111000; // reseta as os pinos
        PORTA = PORTA | number;         //  modifica o valor para o número do display
    } else if (display == 2) {
        PORTA = PORTA & 0b11000111;
        PORTA = PORTA | number << 3;
    }
}
