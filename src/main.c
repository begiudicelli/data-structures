#include <stdio.h>
#include <stdlib.h>
#include "linked_list/linked_list.h"

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    printList(head);

    return 0;
}
