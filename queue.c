#include "queue.h"

void printTask(Task *task);

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void enqueue(Queue *queue, Task *task) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->task = task;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->head = newNode;
    } else {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;

    queue->size++;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

Task *pop(Queue *queue) {
    if (isEmpty(queue)) {
        return NULL;
    }

    Task *task = queue->head->task;
    struct node *temp = queue->head;
    queue->head = queue->head->next;

    free(temp);
    queue->size--;
    return task;
}

Task *delete(Queue *queue, struct node *node) {
    struct node *current = queue->head;
    struct node *prev = NULL;

    while (current) {
        if (node != current) {
            prev = current;
            current = current->next;
            continue;
        }

        // The node to be deleted is the head.
        if (prev == NULL) {
            // The head is the only node in the queue
            if (current->next == NULL) {
                queue->head = NULL;
                queue->tail = NULL;
                queue->size--;

                return current->task;
            }

            queue->head = current->next;
            queue->size--;
            return current->task;
        }
        prev->next = current->next;
        queue->size--;
        return current->task;
    }

    return NULL;
}

Task *popFirst(Queue *queue) {
    struct node *current = queue->head;

    int lowestArriveTime = current->task->arrivalTime;
    struct node *lowestNode = current;
    while (current) {
        if (lowestArriveTime > current->task->arrivalTime) {
            lowestArriveTime = current->task->arrivalTime;
            lowestNode = current;
        }

        current = current->next;
    }

    return delete(queue, lowestNode);
}

Task *popShortestFirst(Queue *queue) {
    struct node *current = queue->head;

    int shortestTime = current->task->burst;
    struct node *lowestNode = current;
    while (current) {
        if (shortestTime > current->task->burst) {
            shortestTime = current->task->burst;
            lowestNode = current;
        }

        current = current->next;
    }

    return delete(queue, lowestNode);
}

void destroy(Queue *queue) {
    while (!isEmpty(queue)) {
        pop(queue);
    }

    free(queue);
}

void traverse(Queue *queue) {
    struct node *current = queue->head;

    while (current) {
        printTask(current->task);
        current = current->next;
    }
    printf("\n");
}

void printTask(Task *task) {
    printf("[%s] [%d] [%d]\n", task->name, task->arrivalTime, task->burst);
}

/*
int main() {
    Queue *queue = createQueue();

    for (int i = 8; i <= 14; i++) {
        Task *newTask = (Task *) malloc(sizeof(Task));

        newTask->name = "test";
        newTask->tid = i + 1;
        newTask->arrivalTime = i;
        newTask->burst = i + 1;

        enqueue(queue, newTask);
    }

    Task *fourthTask = (Task *) malloc(sizeof(Task));
    fourthTask->name = "fourthTask";
    fourthTask->tid = 4;
    fourthTask->arrivalTime = 4;
    fourthTask->burst = 5 + 1;

    enqueue(queue, fourthTask);

    Task *fifthTask = (Task *) malloc(sizeof(Task));
    fifthTask->name = "fifthTask";
    fifthTask->tid = 4;
    fifthTask->arrivalTime = 3;
    fifthTask->burst = 5 + 1;
    enqueue(queue, fifthTask);

    traverse(queue);

    printTask(popFirst(queue));
    printf("\n");
    traverse(queue);
    destroy(queue);
}*/
