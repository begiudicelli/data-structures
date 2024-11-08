#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

Graph* initGraph(int vertices, int arestas) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->numVertices = vertices;
    g->numArestas = arestas;
    g->adjacencia = NULL;
    g->incidencia = NULL;
    return g;
}

void fillMatrix(Graph* g) {
    g->adjacencia = (int**) malloc(g->numVertices * sizeof(int*));
    for (int i = 0; i < g->numVertices; i++) g->adjacencia[i] = (int*) calloc(g->numVertices, sizeof(int));

    g->incidencia = (int**) malloc(g->numArestas * sizeof(int*));
    for (int i = 0; i < g->numArestas; i++) g->incidencia[i] = (int*) calloc(g->numVertices, sizeof(int));

    for (int i = 0; i < g->numArestas; i++) {
        printf("Digite os vértices (u, v) da aresta %d (0 a %d): ", i + 1, g->numVertices - 1);
        int u, v;
        scanf("%d %d", &u, &v);

        if (u >= 0 && u < g->numVertices && v >= 0 && v < g->numVertices) {
            g->adjacencia[u][v] = 1;
            g->adjacencia[v][u] = 1; // nao direcionado

            g->incidencia[i][u] = 1;
            g->incidencia[i][v] = 1;
        } else {
            printf("Vertices invalidos!\n");
            i--;
        }
    }
}

void printAdjacencia(Graph* g) {
    printf("\nMatriz de Adjacencia:\n");
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->adjacencia[i][j]);
        }
        printf("\n");
    }
}

void printIncidencia(Graph* g) {
    printf("\nMatriz de Incidencia:\n");
    for (int j = 0; j < g->numVertices; j++) {
        for (int i = 0; i < g->numArestas; i++) {
            printf("%d ", g->incidencia[i][j]);
        }
        printf("\n");
    }
}

void calculateDegree(Graph* g) {
    printf("\nGrau de cada vértice:\n");
    for (int i = 0; i < g->numVertices; i++) {
        int grau = 0;
        for (int j = 0; j < g->numVertices; j++) {
            grau += g->adjacencia[i][j];
        }
        printf("Vértice %d: Grau = %d\n", i, grau);
    }
}

void displayGraphMenu() {
    setvbuf(stdout, NULL, _IONBF, 0);
    char opt;
    int numVertices, numArestas;
    Graph* g = NULL;
    do {
        printf("\nA - Inicializar grafo\n");
        printf("B - Preencher matrizes\n");
        printf("C - Imprimir matriz de incidência\n");
        printf("D - Imprimir matriz de adjacência\n");
        printf("E - Imprimir grau dos vertices\n");
        printf("F - Finalizar\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opt);

        opt = toupper(opt);

        switch(opt) {
            case 'A':
                printf("Digite o número de vértices: ");
                scanf("%d", &numVertices);
                printf("Digite o número de arestas: ");
                scanf("%d", &numArestas);

                if (g != NULL) {
                    free(g->adjacencia);
                    free(g->incidencia);
                    free(g);
                }
                g = initGraph(numVertices, numArestas);
                break;
            case 'B':
                g != NULL ? fillMatrix(g) : printf("Grafo não inicializado.\n");
                break;
            case 'C':
                g != NULL ? printIncidencia(g) : printf("Grafo não inicializado.\n");
                break;
            case 'D':
                g != NULL ? printAdjacencia(g) : printf("Grafo não inicializado.\n");
                break;
            case 'E':
            	g != NULL ? calculateDegree(g) : printf("Grafo não inicializado.\n");
                break;
            default:
                printf("Opçao invalida! Tente novamente.\n");
        }
    } while (opt != 'F');
}

