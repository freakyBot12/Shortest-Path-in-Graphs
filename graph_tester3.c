#include "algo.h"

int main()
{
    FILE* file = fopen("./test.in", "r");
    int n, m, source;
    fscanf(file, "%d%d%d", &n, &m, &source);

    list_graph_t* lg = lg_create(n);

    int src, dest, weight;

    for (int i = 0; i < m; i++) {
        fscanf(file, "%d%d%d", &src, &dest, &weight);
        lg_add_edge(lg, src, dest, weight);
    }
    
    MostEfficientAlgorithmInDAG(lg, n, source);

    lg_free(lg);

    fclose(file);
}