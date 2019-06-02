/*
 * File:   seven_seg.c
 * Author: luan
 *
 * Created on May 30, 2019, 3:07 PM
 */
#include <xc.h>

void seven_seg_init(void) {
    // seta os tris maluku
    TRISC = 0b11000000;
    PORTC = 0b00000000;
}

void seven_seg_set(int display, int number) { // entrada 7 por exemplo

    if(display == 1) {
        // AND com um valor que é 0, sempre vai resultar em 0
        // para 1, ele vai manter o valor comparado
        PORTC = PORTC & 0b11111000; 
        //  OR com um valor 0 manterá o valor comparado
        //  os valores zerados serão trocados pelo número que pode
        //  ser até 7
        PORTC = PORTC | number;     
    } else if (display == 2) {
        PORTC = PORTC & 0b11000111;  // reseta as os pinos
        PORTC = PORTC | number << 3; //  modifica o valor para o n�mero do display
    }
}
