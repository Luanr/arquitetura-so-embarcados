/**
 * LunOS - Luan Operating System
 */

#include <pic18f4520.h>
#include "tasks.h"
#include <xc.h>
#include "kernel.h"
#include "sralloc.h"
#include "seven_seg.h"

unsigned char* sem;

void user_conf() {
  TRISB = 0b1000000;

  sem = SRAMalloc(4);
  
  sem[0] =0;
  sem[1] =0;
  sem[2] =0;
  sem[3] =0;
  seven_seg_init();
}

void task_entrance_01() {
  for (;;) {
      if(PORTCbits.RC6) {
          if(!sem[0]) {
              seven_seg_set(1, 1);
              sem[0] = 1;
              
              PORTBbits.RB1 = 1;
              lunos_delayTask(2000);
              PORTBbits.RB1 = 0;
              
              PORTBbits.RB2 = 1;
          } else if(!sem[1]) {
              seven_seg_set(1, 2);
              sem[1] = 1;
              
              PORTBbits.RB1 = 1;
              lunos_delayTask(2000);
              PORTBbits.RB1 = 0;
              
              PORTBbits.RB3 = 1; 
          } else if(!sem[2]) {
              seven_seg_set(1, 3);
              sem[2] = 1;
              
              PORTBbits.RB1 = 1;
              lunos_delayTask(2000);
              PORTBbits.RB1 = 0;
              
              PORTBbits.RB4 = 1;
          } else if(!sem[3]) {
              seven_seg_set(1, 4);
              sem[3] = 1;
              
              PORTBbits.RB1 = 1;
              lunos_delayTask(2000);
              PORTBbits.RB1 = 0;
              
              PORTBbits.RB5 = 1;
          } else {
              seven_seg_set(1, 0);
          }
          lunos_delayTask(800);
      }
  }
}

void task_entrance_02() {
  for (;;) {
      if(PORTCbits.RC7) {
          if(!sem[0]) {
              seven_seg_set(2, 1);
              sem[0] = 1;
              
              PORTBbits.RB7 = 1;
              lunos_delayTask(2000);
              PORTBbits.RB7 = 0;
              
              PORTBbits.RB2 = 1;
          } else if(!sem[1]) {
              seven_seg_set(2, 2); 
              sem[1] =1;
              
              PORTBbits.RB7 = 1;
              lunos_delayTask(2000);
              PORTBbits.RB7 = 0;
              
              PORTBbits.RB3 = 1;
          } else if(!sem[2]) {
              seven_seg_set(2, 3);
              sem[2] =1;
              
              PORTBbits.RB7 = 1;
              lunos_delayTask(2000);
              PORTBbits.RB7 = 0;
              
              PORTBbits.RB4 = 1;
          } else if(!sem[3]) {
              seven_seg_set(2, 4);
              sem[3] =1;
              
              PORTBbits.RB7 = 1;
              lunos_delayTask(2000);
              PORTBbits.RB7 = 0;
              
              PORTBbits.RB5 = 1;
          } else {
              seven_seg_set(2, 0);
          }
          lunos_delayTask(800);
      }
  }
}

void task_spot_01() {
  while (1) {
    if(PORTBbits.RB2) {
        lunos_delayTask(4000);
        PORTBbits.RB2 = 0;
        sem[0] = 0;
        lunos_delayTask(500);
    }
    lunos_delayTask(100);
  }
}

void task_spot_02() {
  while (1) {
    if(PORTBbits.RB3) {
        lunos_delayTask(4000);
        PORTBbits.RB3 = 0;
        sem[1] = 0;
        lunos_delayTask(500);
    }
    lunos_delayTask(100);
  }
}

void task_spot_03() {
  while (1) {
     if(PORTBbits.RB4) {
        lunos_delayTask(4000);
        PORTBbits.RB4 = 0;
        sem[2] = 0;
        lunos_delayTask(500);
    }
     lunos_delayTask(100);
  }
}


void task_spot_04() {
  while (1) {
    if(PORTBbits.RB5) {
        lunos_delayTask(4000);
        PORTBbits.RB5 = 0;
        sem[3] = 0;
        lunos_delayTask(500);
    }
    lunos_delayTask(100);
  }
}