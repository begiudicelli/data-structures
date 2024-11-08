#ifndef GRAPH_GRAPH_H_
#define GRAPH_GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Graph{
	int numVertices;
	int numArestas;
	int **adjacencia;
	int **incidencia;
}Graph;

Graph* initGraph(int vertices, int arestas);
void fillAdjacencia(Graph* g);
void fillIncidencia(Graph* g);
void printAdjacencia(Graph* g);
void printIncidencia(Graph* g);
void calculateDegree(Graph* g);
void displayGraphMenu();

#endif
