#ifndef SPARSE_MATRIX_SPARSE_H_
#define SPARSE_MATRIX_SPARSE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct SparseNode{
	int value;
	int coluna;
	struct SparseNode *next;
}SparseNode;

typedef struct Matrix{
	SparseNode** arrange;
	int linhas;
	int colunas;
}Matrix;

#endif
