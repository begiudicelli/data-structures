#ifndef LINKED_LIST_LINKED_LIST_H_
#define LINKED_LIST_LINKED_LIST_H_

typedef struct Node {
    int cod;
    struct Node* next;
} Node;

Node* createLinkedListNode(int cod);

void insertAtBeginning(Node** head, int data);
void printList(Node* head);

#endif
