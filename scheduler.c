/**
 * Implementation of various scheduling algorithms.
 *
 * FCFS scheduling
 */

#include <stdlib.h>

#include "scheduler.h"

// sequence counter of next available thread identifier
int nextTid = 0;

Task *selectNextTask(Queue *queue);

// add a new task to the list of tasks
void add(Queue *queue, char *name, int arrivalTime, int burst) {
    // first create the new task
    Task *newTask = (Task *) malloc(sizeof(Task));

    newTask->name = name;
    newTask->tid = nextTid++;
    newTask->arrivalTime = arrivalTime;
    newTask->burst = burst;

    // insert the new task into the list of tasks
    enqueue(queue, newTask);
}

/**
 * Run the FCFS scheduler
 */
void schedule(Queue *queue) {
    Task *current;

    // sanity checker
    traverse(queue);

    while (!isEmpty(queue)) {
        current = selectNextTask(queue);

        run(current, current->burst);
    }
}

/**
 * Returns the next task selected to run.
 *
 * @param Queue queue
 * @param int scheduleAlgorithmSwitch - 0 for FCFS, 1 for SJF
 */
Task *selectNextTask(Queue *queue, int scheduleAlgorithmSwitch) {
    if (scheduleAlgorithmSwitch == 0) {
        return popFirst(queue);
    } else if (scheduleAlgorithmSwitch == 1) {
        return popShortestFirst(queue);
    }
    return NULL;
}
