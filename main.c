/**
 * LunOS - Luan Operating System
 */

#include <xc.h>
#include "kernel.h"
#include "tasks.h"
#include "int0_test.h"
#include "semaphore.h"

#pragma config PBADEN = OFF
#pragma config WDT    = OFF


asm("GLOBAL _task_idle, _task_entrance_01, _task_entrance_02, _task_spot_01, _task_spot_02, _task_spot_03, _task_spot_04");



void main(void) {

  lunos_init();

  user_conf();
  config_INT0();
  config_timer0();

  // Cria tarefas de usuário
  lunos_createTask(5, &task_entrance_01);
  lunos_createTask(4, &task_entrance_02);
  
  lunos_createTask(5, &task_spot_01);
  lunos_createTask(5, &task_spot_02);
  lunos_createTask(5, &task_spot_03);
  lunos_createTask(5, &task_spot_04);
  
  dispatcher(READY);

  while (1);

  return;
}
