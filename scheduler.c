/**
 * Implementation of various scheduling algorithms.
 *
 * FCFS scheduling
 */

#include <stdlib.h>

#include "scheduler.h"

// sequence counter of next available thread identifier
int nextTid = 0;
int completionTime = 0;
int counter = -1;

Task *selectNextTask(Queue *queue, int scheduleAlgorithmSwitch);

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
void schedule(Queue *queue, int scheduleAlgorithmSwitch) {
    Task *current;

    int queueSize = queue->size;

    int completionTimeArray[queueSize];
    int burstTimes[queueSize];
    int arrivalTimes[queueSize];
    char pids[queueSize][2];

    while (!isEmpty(queue)) {
        counter++;

        current = selectNextTask(queue, scheduleAlgorithmSwitch);

        if (current == NULL) {
            return;
        }

        int arrivalTime = current->arrivalTime;
        if (arrivalTime > completionTime) {
            completionTime = current->arrivalTime + current->burst;
            completionTimeArray[counter] = completionTime;
        } else {
            completionTime += current->burst;
            completionTimeArray[counter] = completionTime;
        }
        burstTimes[counter] = current->burst;
        arrivalTimes[counter] = arrivalTime;
        pids[counter][0] = current->name[0];
        pids[counter][1] = current->name[1];
        run(current, current->burst);
    }

    printf("\n\n\n");
    printf("PID | %15s | %13s | %12s | %14s", "Turnaround Time", "Response Time", "Waiting Time", "Response Ratio\n");

    double rTT = 0;
    double rWT = 0;
    double rBT = 0;

    for (int i = 0; i < queueSize; i++) {
        double tt = completionTimeArray[i] - arrivalTimes[i];
        double rt = (completionTimeArray[i] - burstTimes[i]) - arrivalTimes[i];
        double wt = tt - burstTimes[i];
        double rr = (wt + burstTimes[i]) / burstTimes[i];

        rTT += tt;
        rWT += wt;
        rBT += burstTimes[i];

        char name[3];
        name[0] = pids[i][0];
        name[1] = pids[i][1];

        printf("%3s | %15.0f | %13.0f | %12.0f | %14.2f\n", name, tt, rt, wt, rr);
    }

    printf("\n\n%23s | %20s | %10s", "Average Turnaround Time", "Average Waiting Time", "Throughput\n");
    printf("%23.2f | %20.2f | %10.2f\n", rTT / queueSize, rWT / queueSize, rBT / queueSize);
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
