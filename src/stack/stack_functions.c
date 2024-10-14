#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void displayStackMenu(){
	char opt;

	do{
        printf("\nMenu Principal: \n");
        printf("A - Push Pilha\n");
        printf("B - Pop Pilha\n");
        printf("C - Imprimir Pilha\n");
        printf("D -	Finalizar\n");
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
			printf("\nPrograma finalizado.");
			break;
		default:
			printf("\nOpção inválida.");
			break;
		}

	} while (opt != 'D');
}

