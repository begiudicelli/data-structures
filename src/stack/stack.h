#ifndef STACK_STACK_H_
#define STACK_STACK_H_

#include <stdbool.h>

typedef struct StackNode{
	int cod;
	struct StackNode* next;
}StackNode;

StackNode** createStack();
StackNode* pushStackNode(StackNode* head, int cod);
bool popStackNode(StackNode* head);
void printStack(StackNode* head);
void displayStackMenu();

#endif
