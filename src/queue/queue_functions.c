#include "queue.h"

void pushQueueNode(QueueNode** head, QueueNode** tail, int cod){
	QueueNode* newQueueNode = (QueueNode*) malloc (sizeof(QueueNode));
	newQueueNode->cod = cod;
	newQueueNode->next = NULL;

	if(*tail == NULL){
		*head = *tail = newQueueNode;
	}
	else{
		(*tail)->next= newQueueNode;
		*tail = newQueueNode;
	}
}

bool popQueueNode(QueueNode** head){
	if(*head == NULL){
		printf("Fila vazia.\n");
		return false;
	}else{
		QueueNode* tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return true;
	}
}

void printQueue(QueueNode* head){
	QueueNode* current = head;
	while(current != NULL){
        printf("%d -> ", current->cod);
        current = current->next;
	}
	printf("NULL\n");
}

void massPush(QueueNode** head, QueueNode** tail, int amount){
	for(int i = 0; i < amount; i++){
		int value = rand() % 100;
		pushQueueNode(head, tail, value);
	}
	printf("%d valores inseridos com sucesso.\n", amount);
}

void displayQueueMenu(){
	setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(NULL));
	char opt;
	int value, amount;

	QueueNode* head = NULL;
	QueueNode* tail = NULL;

	do{
        printf("\nMenu Principal: \n");
        printf("A - Push Fila\n");
        printf("B - Pop Fila\n");
        printf("C - Push em massa\n");
        printf("D - Imprimir Fila\n");
        printf("E-  Finalizar\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opt);

		switch (opt){
		case 'A' :
			printf("Digite o valor a ser inserido na stack: ");
			scanf("%d", &value);
			pushQueueNode(&head, &tail, value);
			break;
		case 'B' :
			popQueueNode(&head);
			break;
		case 'C' :
			printf("Digite a quantidade de valores a serem inseridos na stack: ");
			scanf("%d", &amount);
			massPush(&head, &tail, amount);
			break;
		case 'D' :
			printQueue(head);
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
