//
// Created by weston on 3/30/24.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"

struct node {
    Task *task;
    struct node *next;
};

typedef struct {
    struct node* head;
    struct node* tail;
    int size;
} Queue;

Queue* createQueue();
void enqueue(Queue *queue, Task *task);
Task* delete(Queue *queue, struct node *node);
Task* pop(Queue *queue);
Task *popFirst(Queue *queue);
int isEmpty(Queue *queue);
void traverse(Queue *queue);
