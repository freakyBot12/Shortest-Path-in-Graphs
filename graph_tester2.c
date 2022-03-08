#include "algo.h"

int main()
{
    FILE* file = fopen("./test.in", "r");
    int n, m, source;
    fscanf(file, "%d%d%d", &n, &m, &source);

    Edge* edgeVector = malloc(m * sizeof(*edgeVector));
    int edgeCounter = 0;

    int src, dest, weight;

    for (int i = 0; i < m; i++) {
        fscanf(file, "%d%d%d", &src, &dest, &weight);
        edgeVector[edgeCounter].source = src;
        edgeVector[edgeCounter].dest = dest;
        edgeVector[edgeCounter].weight = weight;
        edgeCounter++;
    }
    
    BellmanFord(edgeVector, n, m, source);

    free(edgeVector);

    fclose(file);
}