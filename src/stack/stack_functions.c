#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

StackNode* pushStackNode(StackNode* head, int cod){
	StackNode* newStackNode = (StackNode*) malloc (sizeof(StackNode));
	newStackNode->cod = cod;
	newStackNode->next = head;
	return newStackNode;
}

bool popStackNode(){

}

void printStack(StackNode* head){
	StackNode* current = head;
	while(current != NULL){
        printf("%d -> ", current->cod);
        current = current->next;
	}
	printf("NULL");
}

void displayStackMenu(){
	setvbuf(stdout, NULL, _IONBF, 0);
	char opt;
	int value;

	StackNode* stack = NULL;
	do{
        printf("\nMenu Principal: \n");
        printf("A - Push Pilha\n");
        printf("B - Pop Pilha\n");
        printf("C - Imprimir Pilha\n");
        printf("D-  Finalizar\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opt);

		switch (opt){
		case 'A' :
			printf("Digite o valor a ser inserido na stack: ");
			scanf("%d", &value);
			stack = pushStackNode(stack, value);
			break;
		case 'B' :
			break;
		case 'C' :
			printStack(stack);
			break;
		case 'D' :
			printf("\nPrograma finalizado.");
			break;
		default:
			printf("\nOpção inválida.");
			break;
		}

	} while (opt != 'D');
}

