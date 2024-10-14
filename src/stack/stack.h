#ifndef STACK_STACK_H_
#define STACK_STACK_H_

typedef struct Stack{
	int cod;
	struct Stack* next;
}Stack;

Stack** createStack();
Stack* pushStackNode(Stack* head, int cod);
Stack* popStackNode(Stack** head);
void displayStackMenu();
#endif
