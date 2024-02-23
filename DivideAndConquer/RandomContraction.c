#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "graphs.h"

int minCut(char* filename) {
    VertexList *graph = parse_undirected(filename);
    if (graph == NULL) {
        return -1;
    }
    Vertex* v1;
    Vertex *v2;
    int n1;
    int n2;
    int length = countVertices(graph);
        printf("Graph state\n");
        for ( int i = 0; i<length; i++) {
            printf("Vertex %d: ", getNth(graph, i)->ID);
            VertexList *current = getNth(graph, i)->sources;
            while (current != NULL) {
                printf("%d ", current->v->ID);
                current = current->next;
            }
            printf("\n");
        }
        printf("\n");
    while (length > 2) {
        n1 = rand() % length;
        n2 = rand() % length;
        while (n1 == n2) {
            n2 = rand() % length;
        }
        v1 = getNth(graph, n1);
        v2 = getNth(graph, n2);
        printf("Chosen vertices: %d %d\n", v1->ID, v2->ID);
        contract(&graph, v1->ID, v2->ID);
        length--;
        for ( int i = 0; i<length; i++) {
            printf("Vertex %d: ", getNth(graph, i)->ID);
            VertexList *current = getNth(graph, i)->sources;
            while (current != NULL) {
                printf("%d ", current->v->ID);
                current = current->next;
            }
            printf("\n");
        }
        printf("\n");
    }
    if ((graph==NULL) || (graph->v==NULL) || (graph->v->sources==NULL)) {
        printf("Fail\n");
        return -1;
    }
    int cut = countVertices(graph->v->sources);
    freeGraph(graph);
    printf("Cut: %d\n", cut);
    return cut;
}

int main() {
    srand(time(NULL));
    char *filename = "kargerMinCut.txt";
    int n_tries = 100;
    int min = 1000;
    int cut;
    for (int i = 0; i < n_tries; i++) {
        cut = minCut(filename);
        if (cut == -1) {
            printf("Error parsing file\n");
            return -1;
        } else if (cut < min) {
            min = cut;
        }
    }
    printf("Minimum cut: %d\n", min);
    return min;
}
    