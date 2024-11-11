#ifndef GRAPH_GRAPH_H_
#define GRAPH_GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct GraphNode {
    int vertice;
    struct GraphNode* prox;
} GraphNode;

typedef struct Graph {
    int numVertices;
    int numArestas;
    GraphNode** adjacencia;
    int** incidencia;
} Graph;

Graph* initGraph(int vertices, int arestas);
void addAdjacencia(Graph* g, int u, int v);
void fillGraph(Graph* g);
void printAdjacencia(Graph* g);
void printIncidencia(Graph* g);
void calculateDegree(Graph* g);
void freeGraph(Graph* g);
void displayGraphMenu();

#endif
