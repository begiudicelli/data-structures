#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

NodeLinkedList* createLinkedListNode(int cod) {
	NodeLinkedList* newNode = (NodeLinkedList*)malloc(sizeof(NodeLinkedList));
    newNode->cod = cod;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(NodeLinkedList** head, int cod) {
	NodeLinkedList* newNode = createLinkedListNode(cod);
    newNode->next = *head;
    *head = newNode;
}
void printList(NodeLinkedList* head) {
	NodeLinkedList* current = head;
    while (current != NULL) {
        printf("%d -> ", current->cod);
        current = current->next;
    }
    printf("NULL\n");
}


