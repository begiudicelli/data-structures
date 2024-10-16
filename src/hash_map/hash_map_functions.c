#include "hash_map.h"

HashNode** getHashtable(){
	HashNode** hashtable = calloc(HASHTABLE_SIZE, sizeof(HashNode*));
	return hashtable;
}

unsigned int hash(char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) hash = ((hash << 5) + hash) + c;
    return hash % HASHTABLE_SIZE;
}

void insertIntoTable(HashNode** hashtable, char *str){
	int index = hash(str);
	HashNode* newHashNode = malloc(sizeof(HashNode));
    strncpy(newHashNode->data, str, MAX_DATA - 1);
    newHashNode->data[MAX_DATA - 1] = '\0';
    newHashNode->next = hashtable[index];
    hashtable[index] = newHashNode;
}

void displayNode(HashNode* current) {
    if (current == NULL) return;
    printf("[%s] End: %p", current->data, (void*)current);
    if (current->next != NULL) printf(" -> ");
    displayNode(current->next);
}

void displayTable(HashNode** hashtable) {
    printf("\nTabela Hash:\n");
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        printf("%2d: ", i);
        HashNode *current = hashtable[i];
        if (current != NULL) {
            displayNode(current);
            printf("\n");
        } else printf("NULL\n");
    }
}

void searchHashNode(HashNode** hashtable, char *str){
	int index = hash(str);
	HashNode* current = hashtable[index];
	while(current != NULL){
		if(strcmp(str, current->data) == 0){
			printf("Nome encontrado.\n");
			printf("Nome: %s\n", current->data);
			printf("Indice hash: %d\n", index);
			printf("Endereco do nome: %p\n", (void*)current);
			return;
		}
		current = current->next;
	}
	printf("Not found!");
}

void displayHashMenu(){
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(NULL));

    HashNode **table = getHashtable();
    char opt;
    char str[MAX_DATA];
    do {
        printf("\nMenu Principal: \n");
        printf("A - Inserir elemento\n");
        printf("B - Pesquisar elemento\n");
        printf("C - Imprimir\n");
        printf("D - Inserir em massa\n");
        printf("E - Finalizar\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opt);

        switch (opt) {
        case 'A':
            printf("Digite o nome para ser inserido: ");
            scanf(" %[^\n]", str);
            insertIntoTable(table, str);
            break;
        case 'B':
        	printf("Digite o nome para ser pesquisado: ");
        	scanf(" %[^\n]", str);
        	searchHashNode(table, str);
            break;
        case 'C':
            displayTable(table);
            break;
        case 'D':
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (opt != 'E');
}

