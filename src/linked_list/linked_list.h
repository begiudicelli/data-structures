#ifndef LINKED_LIST_LINKED_LIST_H_
#define LINKED_LIST_LINKED_LIST_H_

typedef struct NodeLinkedList {
    int cod;
    struct NodeLinkedList* next;
} NodeLinkedList;

NodeLinkedList* createLinkedListNode(int cod);

void insertAtBeginning(NodeLinkedList** head, int data);
void printList(NodeLinkedList* head);

#endif
