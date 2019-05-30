/**
 * LunOS - Luan Operating System
 */

#ifndef PIPE_H
#define	PIPE_H

#include "semaphore.h"

#define PIPE_SIZE 2

typedef struct pipe {
  unsigned int pipe_data[PIPE_SIZE];
  unsigned int index_write;
  unsigned int index_read;
  unsigned int p_size;
  sem_t *s;
} pipe_t;

void pipe_create(pipe_t *p, sem_t *s);
void pipe_write(pipe_t *p, unsigned int data);
void pipe_read(pipe_t *p, unsigned int *data);
unsigned int pipe_size(pipe_t p);


#endif	/* PIPE_H */

