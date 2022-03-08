#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_NAME_SIZE 300
#define TEST_NUMBER_SIZE 5


void graph_generator (int n, int test_number, int source, int null_matrix,
                      int sparse_matrix, int dense_matrix, int random_matrix) {
    char *test_name = malloc(TEST_NAME_SIZE);
    strcpy(test_name,"in/test");

    char *number = malloc(TEST_NUMBER_SIZE);
    sprintf(number, "%d", test_number);
    strcat(test_name,number);
    strcat(test_name,".in");

    FILE* file;
    file = fopen(test_name,"w+");

    int** graph_matrix = calloc(n , sizeof(int*));
    for (int i = 0; i < n; i++)
        graph_matrix[i] = calloc(n , sizeof(int));

    if (null_matrix == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph_matrix[i][j] = 0;
            }
        }
    } else if (sparse_matrix == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j) {
                    if (rand() % 15 == 0)
                        graph_matrix[i][j] = rand() % 5000;
                    else
                        graph_matrix[i][j] = 0;
                }
                else
                    graph_matrix[i][j] = 0;
            }
        }
    } else if (dense_matrix == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j) {
                    graph_matrix[i][j] = 0;
                }
                else
                    graph_matrix[i][j] = rand() % 5000 + 1;
            }
        }
    } else if (random_matrix == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= j)
                    graph_matrix[i][j] = 0;
                else
                graph_matrix[i][j] = rand() % 5000;
            }
        }
    } else
        printf("You have to choose between a null, sparse, dense or random matrix!\n");

    int muchii = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph_matrix[i][j] != 0)
                muchii++;

    fprintf(file, "%d %d %d\n", n, muchii, source);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph_matrix[i][j] != 0) {
                fprintf(file, "%d %d %d\n", i, j, graph_matrix[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        free(graph_matrix[i]);
    free(graph_matrix);

    fclose(file);

    free(number);
    free(test_name);
}

int main()
{
    // Matrice nule
    graph_generator(50, 8, 0, 1, 0, 0, 0);
    graph_generator(100, 9, 0, 1, 0, 0, 0);
    graph_generator(250, 10, 5, 1, 0, 0, 0);
    graph_generator(500, 11, 10, 1, 0, 0, 0);
    graph_generator(1000, 12, 0, 1, 0, 0, 0);

    // Matrice sparse
    graph_generator(20, 13, 0, 0, 1, 0, 0);
    graph_generator(100, 14, 0, 0, 1, 0, 0);
    graph_generator(150, 15, 0, 0, 1, 0, 0);
    graph_generator(250, 16, 0, 0, 1, 0, 0);
    graph_generator(500, 17, 0, 0, 1, 0, 0);
    graph_generator(750, 18, 4, 0, 1, 0, 0);
    graph_generator(750, 19, 0, 0, 1, 0, 0);
    graph_generator(1000, 20, 0, 0, 1, 0, 0);
    graph_generator(1500, 21, 0, 0 , 1, 0, 0);

    //Matrice dense
    graph_generator(20, 22, 0, 0, 0, 1, 0);
    graph_generator(100, 23, 0, 0, 0, 1, 0);
    graph_generator(100, 24, 10, 0, 0, 1, 0);
    graph_generator(150, 25, 0, 0, 0, 1, 0);
    graph_generator(250, 26, 5, 0, 0, 1, 0);
    graph_generator(500, 27, 0, 0, 0, 1, 0);
    graph_generator(750, 28, 1, 0, 0, 1 ,0);
    graph_generator(1000, 29, 0, 0, 0, 1, 0);
    graph_generator(1500, 30, 0, 0, 0, 1, 0);

    // Matrice random
    graph_generator(20, 31, 3, 0, 0, 0, 1);
    graph_generator(70, 32, 6, 0, 0, 0, 1);
    graph_generator(100, 33, 15, 0, 0, 0, 1);
    graph_generator(150, 34, 78, 0, 0, 0, 1);
    graph_generator(250, 35, 8, 0, 0, 0, 1);
    graph_generator(500, 36, 0, 0, 0, 0, 1);
    graph_generator(800, 37, 0, 0, 0, 0, 1);
    graph_generator(1000, 38, 0, 0, 0, 0, 1);
    graph_generator(1200, 39, 0, 0, 0, 0, 1);
    graph_generator(1350, 40, 1000, 0, 0, 0, 1);
    graph_generator(1500, 41, 0, 0, 0, 0, 1);
}