#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

Graph* initGraph(int vertices, int arestas) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->numVertices = vertices;
    g->numArestas = arestas;

    g->adjacencia = (GraphNode**) malloc(vertices * sizeof(GraphNode*));
    for (int i = 0; i < vertices; i++) {
        g->adjacencia[i] = NULL;
    }

    g->incidencia = (int**) malloc(arestas * sizeof(int*));
    for (int i = 0; i < arestas; i++){
    	g->incidencia[i] = (int*) malloc(2 * sizeof(int));  // 2 vertices
    }

    return g;
}

void addAdjacencia(Graph* g, int u, int v) {
    GraphNode* novoNode = (GraphNode*) malloc(sizeof(GraphNode));
    novoNode->vertice = v;
    novoNode->prox = g->adjacencia[u];
    g->adjacencia[u] = novoNode;
}

void fillGraph(Graph* g) {
    for (int i = 0; i < g->numArestas; i++) {
        printf("Digite os vértices (u, v) da aresta %d (0 a %d): ", i + 1, g->numVertices - 1);
        int u, v;
        scanf("%d %d", &u, &v);

        if (u >= 0 && u < g->numVertices && v >= 0 && v < g->numVertices && u != v) {

        	addAdjacencia(g, u ,v);
        	addAdjacencia(g, v ,u); // nao direcionado

            g->incidencia[i][0] = u;
            g->incidencia[i][1] = v;
        } else {
            printf("Vértices inválidos ou iguais! Digite novamente.\n");
            i--;
        }
    }
}

void printAdjacencia(Graph* g) {
    printf("\nLista de Adjacência:\n");
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vértice %d: ", i);
        GraphNode* temp = g->adjacencia[i];
        while (temp != NULL) {
            printf("%d ", temp->vertice);
            temp = temp->prox;
        }
        printf("\n");
    }
}

void printIncidencia(Graph* g) {
    printf("\nLista de Incidência:\n");
    for (int i = 0; i < g->numArestas; i++) {
        printf("Aresta %d: %d - %d\n", i + 1, g->incidencia[i][0], g->incidencia[i][1]);
    }
}

void calculateDegree(Graph* g) {
    printf("\nGrau de cada vertice:\n");
    for (int i = 0; i < g->numVertices; i++) {
        int grau = 0;
        GraphNode* temp = g->adjacencia[i];
        while (temp != NULL) {
            grau++;
            temp = temp->prox;
        }
        printf("Vertice %d: Grau = %d\n", i, grau);
    }
}

void freeGraph(Graph* g) {
    if (g != NULL) {
        for (int i = 0; i < g->numVertices; i++) {
            GraphNode* temp = g->adjacencia[i];
            while (temp != NULL) {
                GraphNode* aux = temp;
                temp = temp->prox;
                free(aux);
            }
        }
        for (int i = 0; i < g->numArestas; i++) {
            free(g->incidencia[i]);
        }
        free(g->adjacencia);
        free(g->incidencia);
        free(g);
    }
}

void displayGraphMenu() {
    setvbuf(stdout, NULL, _IONBF, 0);
    char opt;
    int numVertices, numArestas;
    Graph* g = NULL;
    do {
        printf("\nA - Inicializar grafo\n");
        printf("B - Preencher grafo\n");
        printf("C - Imprimir lista de adjacência\n");
        printf("D - Imprimir lista de incidência\n");
        printf("E - Imprimir grau dos vértices\n");
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

                if (g != NULL) freeGraph(g);
                g = initGraph(numVertices, numArestas);
                break;
            case 'B':
                if (g != NULL) fillGraph(g);
                else printf("Grafo não inicializado.\n");
                break;
            case 'C':
                if (g != NULL) printAdjacencia(g);
                else printf("Grafo não inicializado.\n");
                break;
            case 'D':
                if (g != NULL) printIncidencia(g);
                else printf("Grafo não inicializado.\n");
                break;
            case 'E':
                if (g != NULL) calculateDegree(g);
                else printf("Grafo não inicializado.\n");
                break;
            case 'F':
                if (g != NULL) freeGraph(g);
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opt != 'F');
}
