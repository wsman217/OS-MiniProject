/**
 * "Virtual" CPU that also maintains track of system time.
 */

#include "cpu.h"

// run this task for the specified time howLong
void run(Task *task, int howLong) {
    printf("Running task = [%s] [%d] [%d] for %d units.\n",task->name, task->arrivalTime, task->burst, howLong);
}
