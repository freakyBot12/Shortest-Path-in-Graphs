#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "algo.h"
#include "ListGraph.h"
#define OUTPUT_NAME_SIZE 300

int main()
{
    for (int i = 1; i < 42; i++) {

        char* input = malloc(OUTPUT_NAME_SIZE);
        sprintf(input,"in/test%d.in", i);
        FILE* file = fopen(input, "r");
        int n, m, source;
        fscanf(file, "%d%d%d", &n, &m, &source);

        Edge* edgeVector = malloc(m * sizeof(*edgeVector));
        int edgeCounter = 0;

        list_graph_t* lg = lg_create(n);

        int src;
        int dest;
        int weight;

        for (int i = 0; i < m; i++) {
            fscanf(file, "%d%d%d", &src, &dest, &weight);
            lg_add_edge(lg, src, dest, weight);
            edgeVector[edgeCounter].source = src;
            edgeVector[edgeCounter].dest = dest;
            edgeVector[edgeCounter].weight = weight;
            edgeCounter++;
        }
        
        dijkstra(lg, n, source, i);
        BellmanFord(edgeVector, n, m, source, i);
        
        MostEfficientAlgorithmInDAG(lg, n, source, i);
        printf("\n");

        free(edgeVector);

        lg_free(lg);

        fclose(file);
        free(input);
    }
}
