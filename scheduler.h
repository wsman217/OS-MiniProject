#include "queue.h"
#include "cpu.h"

// add a task to the list
void add(Queue *queue, char *name, int arrivalTime, int burst);

// invoke the scheduler
void schedule(Queue *queue, int scheduleAlgorithmSwitch);
