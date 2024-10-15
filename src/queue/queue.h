#ifndef QUEUE_QUEUE_H_
#define QUEUE_QUEUE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct QueueNode{
	int cod;
	struct QueueNode* next;
}QueueNode;


void pushQueueNode(QueueNode** head, QueueNode** tail, int cod);
bool popQueueNode(QueueNode** head);
void printQueue(QueueNode* head);
void displayQueueMenu();

#endif
