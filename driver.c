/**
 * Driver.c
 *
 * From input file: Schedule is in the format
 *
 *  [name] [arrivalTime] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "driver.h"

#define SIZE    100

int main(int argc, char *argv[]) {
    Queue *queue = createQueue();
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int arrivalTime;
    int burst;

    if (argc != 3) {
        printf("Not enough arguments.\n");
        return -1;
    }

    in = fopen(argv[1], "r");

    if (in == NULL) {
        printf("File was not found.\n");
        return -1;
    }

    while (fgets(task, SIZE, in) != NULL) {
        temp = strdup(task); //understand this built-in function
        name = strsep(&temp, ","); //understand this built-in function
        arrivalTime = atoi(strsep(&temp, ",")); //understand this built-in function
        burst = atoi(strsep(&temp, ","));

        // add the task to the scheduler's list of tasks
        add(queue, name, arrivalTime, burst);

        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule(queue, atoi(argv[2]));

    return 0;
}
