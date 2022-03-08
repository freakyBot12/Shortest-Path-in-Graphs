#include "algo.h"
#include "Stack.h"
#include "ListGraph.h"
#include "time.h"

// Function write the calculated shortest distances
// in a file in out/best folder
void fprintArrBest(int dist[], int n)
{
    FILE* file = fopen("./test.out", "w");

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            fprintf(file,"INF ");
        else
            fprintf(file, "%d ", dist[i]);
    }
    
    fclose(file);
}

// Recursive function used to get topological sorting of a given graph
void TopologicalSort(list_graph_t* graph, int v, bool visited[], stack_t* Stack) {

    // Make the current node as visited
    visited[v] = true;

    // Visit the adjacent vertices of the current vertex (if they haven't been
    // visited already)
    ll_node_t* iterator = graph->neighbors[v]->head;
    while (iterator != NULL) {
        if (!visited[*(int*)iterator->data])
            TopologicalSort(graph, *(int*)iterator->data, visited, Stack);

        iterator = iterator->next;
    }

    // Push the current vertex to stack if it has no adjacent vertices that
    // have not been visited; the stack stores the the vertices in
    // topological order
    st_push(Stack, &v, 0);
}

void MostEfficientAlgorithmInDAG (list_graph_t* graph, int n, int source) {

    double time = 0;
    clock_t start = clock();
    stack_t* Stack = st_create(sizeof(int));

    // Mark all vertices as not visited
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Get the topological sort of the graph
    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            TopologicalSort(graph, i, visited, Stack);

    int dist[n];

    // Initialize distances to all vertices as infinite and distance
    // to source as 0
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;

    // Process vertices in topological order
    while(st_is_empty(Stack) == 0) {
        
        // Get vertex in topological order
        int u = *(int*)st_peek(Stack);
        st_pop(Stack);

        // Update distances of all adjacent vertices 
        if (dist[u] != INT_MAX) {
            ll_node_t* iterator = graph->neighbors[u]->head;
            while (iterator != NULL) {
                int weight = iterator->weight;
                int v = *(int*)iterator->data;
                if (dist[v] > dist[u] + weight)
                    dist[v] = dist[u] + weight;

                iterator = iterator->next;
            }
        }
        
    }
    clock_t end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("MEAInDAG time: %lf", time);
    st_free(Stack);

    fprintArrBest(dist, n);
}
