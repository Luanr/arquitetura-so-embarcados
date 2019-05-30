/**
 * LunOS - Luan Operating System
 */

#include <pic18f4520.h>
#include "tasks.h"
#include <xc.h>
#include "semaphore.h"
#include "kernel.h"
#include "pipe.h"
#include "sralloc.h"

unsigned char* mem;

sem_t teste_1, teste_2, s_pipe;
pipe_t p;

void user_conf() {
  TRISB = 0b00000001;
  sem_init(&teste_1, 1);
  sem_init(&teste_2, 0);
  pipe_create(&p, &s_pipe);
  mem = SRAMalloc(5);
}

void task_0() {
  for (;;) {
    pipe_write(&p, 1);
    //sem_wait(&teste_1);    
    PORTBbits.RB3 = ~PORTBbits.RB3;
    //sem_post(&teste_2);
    lunos_delayTask(1000);
  }

}

void task_1() {
  unsigned int dado;
  for (;;) {    
    pipe_read(&p, &dado);
    if (dado == 1)
      PORTBbits.RB4 = ~PORTBbits.RB4;  
    lunos_delayTask(3000);
  }
}

void task_2() {
  for (;;) {
    PORTBbits.RB5 = ~PORTBbits.RB5;
    lunos_delayTask(1000);
  }

}

void task_bozo() {
  while (1) {
    int i;
    sem_wait(&teste_1);
    for (i = 0; i < 5; i++) {
      mem[i] = i+1;
    }
    sem_post(&teste_2);
  }
}

void task_xuxa() {
  int i;
  while (1) {
    sem_wait(&teste_2);
    for (i = 0; i < 5; i++) {
      if (mem[i] % 2 == 0) 
        PORTBbits.RB3 = ~PORTBbits.RB3;
      else
        PORTBbits.RB5 = ~PORTBbits.RB5;
      lunos_delayTask(1000);
    }
    sem_post(&teste_1);
  }
}
