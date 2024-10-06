#ifndef LINKED_LIST_LINKED_LIST_H_
#define LINKED_LIST_LINKED_LIST_H_

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void insertAtBeginning(Node** head, int data);
void printList(Node* head);

#endif
