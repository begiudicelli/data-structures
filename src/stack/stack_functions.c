#include "stack.h"

StackNode* pushStackNode(StackNode* head, int cod){
	StackNode* newStackNode = (StackNode*) malloc (sizeof(StackNode));
	newStackNode->cod = cod;
	newStackNode->next = head;
	return newStackNode;
}

bool popStackNode(StackNode** head){
	if(*head == NULL){
		printf("Stack vazia.\n");
		return false;
	}else{
		StackNode* tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return true;
	}
}

void stackMassInsertion(StackNode** stack, int amount){
	for(int i = 0; i < amount; i++){
		int value =  rand() % 100;
		*stack = pushStackNode(*stack, value);
	}
	printf("%d valores inseridos com sucesso.\n", amount);
}

void printStack(StackNode* head){
	StackNode* current = head;
	while(current != NULL){
        printf("%d -> ", current->cod);
        current = current->next;
	}
	printf("NULL\n");
}

void displayStackMenu(){
	setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(NULL));
	char opt;
	int value, amount;

	StackNode* stack = NULL;
	do{
        printf("\nMenu Principal: \n");
        printf("A - Push Pilha\n");
        printf("B - Pop Pilha\n");
        printf("C - Push em massa\n");
        printf("D - Imprimir Pilha\n");
        printf("E-  Finalizar\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opt);

		switch (opt){
		case 'A' :
			printf("Digite o valor a ser inserido na stack: ");
			scanf("%d", &value);
			stack = pushStackNode(stack, value);
			break;
		case 'B' :
			popStackNode(&stack);
			break;
		case 'C' :
			printf("Digite a quantidade de valores a serem inseridos na stack: ");
			scanf("%d", &amount);
			stackMassInsertion(&stack, amount);
			break;
		case 'D' :
			printStack(stack);
			break;
		case 'E':
			printf("\nPrograma finalizado.");
			break;
		default:
			printf("\nOpção inválida.");
			break;
		}

	} while (opt != 'E');
}

