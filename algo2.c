#include "algo.h"
#include "time.h"
// Function write the calculated shortest distances
// in a file in out/best folder
void fprintArr2 (int dist[], int V)
{
    FILE* file = fopen("./test.out", "w");

    for (int i = 0; i < V; i++)
        if (dist[i] == INT_MAX)
            fprintf(file,"INF ");
        else
            fprintf(file, "%d ", dist[i]);
    
    fclose(file);
}

// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
void BellmanFord(Edge* edgeVector, int V, int edges, int src)
{
    double time;
    clock_t start = clock();
    int dist[V];
  
    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
  
    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at most |V| - 1
    // edges
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int u = edgeVector[j].source;
            int v = edgeVector[j].dest;
            int weight = edgeVector[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
  
    // Step 3: check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.

    for (int j = 0; j < edges; j++) {
        int u = edgeVector[j].source;
        int v = edgeVector[j].dest;
        int weight = edgeVector[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return;
        }
    }
    clock_t end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bellman-Ford time: %lf", time);
    fprintArr2(dist, V);
    return;
}