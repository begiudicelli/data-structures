#ifndef STACK_STACK_H_
#define STACK_STACK_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct StackNode{
	int cod;
	struct StackNode* next;
}StackNode;

StackNode* pushStackNode(StackNode* head, int cod);
bool popStackNode(StackNode** head);
void printStack(StackNode* head);
void stackMassInsertion(StackNode** stack, int value);
void displayStackMenu();


#endif
