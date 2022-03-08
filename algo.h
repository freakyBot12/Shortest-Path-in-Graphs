#ifndef ALGO_H
#define ALGO_H

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListGraph.h"
#include <time.h>

typedef struct {
    int source;
    int dest;
    int weight;
}Edge;

void dijkstra(list_graph_t* graph, int V, int src);
void BellmanFord(Edge* edgeVector, int V, int edges, int src);
void MostEfficientAlgorithmInDAG (list_graph_t* graph, int n, int source);


#endif