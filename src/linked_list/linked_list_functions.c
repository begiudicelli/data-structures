#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* createLinkedListNode(int cod) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->cod = cod;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int cod) {
    Node* newNode = createLinkedListNode(cod);
    newNode->next = *head;
    *head = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->cod);
        current = current->next;
    }
    printf("NULL\n");
}
