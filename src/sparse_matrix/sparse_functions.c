#include "sparse.h"

void initMatrix(Matrix *m, int lin, int col) {
	m->linhas = lin;
	m->colunas = col;
	m->arrange = malloc(lin * sizeof(SparseNode*));
	for (int i = 0; i < lin; i++)
		m->arrange[i] = NULL;
}

bool insertValue(Matrix *m, int lin, int col, int value) {
	if (lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
		return false;
	SparseNode *previous = NULL;
	SparseNode *current = m->arrange[lin];
	while (current != NULL && current->coluna < col) {
		previous = current;
		current = current->next;
	}

	if (current != NULL && current->coluna == col) {
		if (value == 0) {
			if (previous == NULL)
				m->arrange[lin] = current->next;
			else
				previous->next = current->next;
			free(current);
		} else {
			current->value = value;
		}
	} else {
		SparseNode *new = malloc(sizeof(SparseNode));
		new->coluna = col;
		new->value = value;
		new->next = current;
		if (previous == NULL) {
			m->arrange[lin] = new;
		} else {
			previous->next = new;
		}
	}
	return true;
}

int acessNode(Matrix *m, int lin, int col) {
	if (lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
		return 0;
	SparseNode *current = m->arrange[lin];

	while (current != NULL) {
		if (current->coluna == col) {
			return current->value;
		}
		current = current->next;
	}
	return 0;
}
void printMatrix(Matrix *m) {
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            int value = acessNode(m, i, j);
            printf("%d ", value);
        }
        printf("\n");
    }
}
void massInsertionMatrix(Matrix *m, int amount) {
	int lin, col, value;
	for (int i = 0; i < amount; i++) {
		printf("Digite a linha, coluna e valor do elemento %d a ser inserido: ",
				i + 1);
		scanf("%d %d %d", &lin, &col, &value);
		insertValue(m, lin, col, value);
	}
}

void destroyMatrix(Matrix *m) {
	for (int i = 0; i < m->linhas; i++) {
		SparseNode *current = m->arrange[i];
		while (current != NULL) {
			SparseNode *next = current->next;
			free(current);
			current = next;
		}
	}
	free(m->arrange);
}

void displaySparseMatrixMenu() {
	setvbuf(stdout, NULL, _IONBF, 0);

	Matrix m;
	char opt;
	int lin, col, value, amount;

	int numRows, numCols;
	printf("Digite o numero de linhas e colunas da matriz esparsa: ");
	scanf("%d %d", &numRows, &numCols);
	initMatrix(&m, numRows, numCols);

	do {
		printf("\nMenu Principal da Matriz Esparsa: \n");
		printf("A - Inserir elemento\n");
		printf("B - Acessar elemento\n");
		printf("C - Imprimir matriz\n");
		printf("D - Inserir em massa\n");
		printf("E - Finalizar\n");
		printf("Escolha uma opcao: ");
		scanf(" %c", &opt);

		switch (opt) {
		case 'A':
			printf("Digite o numero da linha e da coluna do elemento a ser inserido: ");
			scanf("%d %d", &lin, &col);
			printf("Digite o valor do elemento a ser inserido: ");
			scanf("%d", &value);
			insertValue(&m, lin, col, value);
			break;

		case 'B':
			printf(
					"Digite o numero da linha e da coluna do elemento a ser acessado: ");
			scanf("%d %d", &lin, &col);
			value = acessNode(&m, lin, col);
			printf("Valor do elemento na linha %d e coluna %d: %d\n", lin, col,
					value);
			break;

		case 'C':
			printf("Imprimindo a matriz:\n");
			printMatrix(&m);
			break;

		case 'D':
			printf("Digite o numero de valores a serem inseridos: ");
			scanf("%d", &amount);
			//massInsertion(&m, amount);
			break;

		default:
			printf("Opcao invalida.\n");
			break;
		}
	} while (opt != 'E');

	destroyMatrix(&m);
}

