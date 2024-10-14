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

void displayLinkedListMenu(){
	char opt;

	do{
        printf("\nMenu Principal: \n");
        printf("A - Push Pilha\n");
        printf("B - Pop Pilha\n");
        printf("C - Imprimir Pilha\n");
        printf("D - Push Fila\n");
        printf("E -	Pop Fila\n");
        printf("F -	Imprimir Fila\n");
        printf("G -	Finalizar\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opt);

		switch (opt){
		case 'A' :
			break;
		case 'B' :
			break;
		case 'C' :
			break;
		case 'D' :
			break;
		case 'E' :
			break;
		case 'F' :
			break;
		case 'G' :
			printf("\nPrograma finalizado.");
			break;
		default:
			printf("\nOpção inválida.");
			break;
		}

	} while (opt != 'G');
}
