/**
 * LunOS - Luan Operating System
 */

#include "pipe.h"
#include "kernel.h"
#include "semaphore.h"

void pipe_create(pipe_t *p, sem_t *s) {
  p->index_write = 0;
  p->index_read = 0;
  p->p_size = 0;
  p->s = s;
  sem_init(p->s, 0);
}

void pipe_write(pipe_t *p, unsigned int data) {
  DISABLE_ALL_INTERRUPTS();
 
  if (p->p_size < PIPE_SIZE) {
    p->pipe_data[p->index_write] = data;
    p->index_write = (p->index_write + 1) % PIPE_SIZE;
    p->p_size++;
    if (sem_get_value(*p->s) < 0) sem_post(p->s);
  } else {
    sem_wait(p->s);
  }
  
  ENABLE_ALL_INTERRUPTS();
}

void pipe_read(pipe_t *p, unsigned int *data) {
  DISABLE_ALL_INTERRUPTS();

  if (p->p_size > 0) {
    *data = p->pipe_data[p->index_read];
    p->index_read = (p->index_read + 1) % PIPE_SIZE;
    p->p_size--;
    if (sem_get_value(*p->s) < 0) sem_post(p->s);
  } else {
    sem_wait(p->s);
  }
  
  ENABLE_ALL_INTERRUPTS();
}

unsigned int pipe_size(pipe_t p) {
  return p.p_size;
}
