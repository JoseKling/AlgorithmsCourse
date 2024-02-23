#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<string.h>
#include <stdlib.h>
#include "graphs.h"

VertexList* parse_undirected(char *filename) {
    FILE *fp;
    char buffer[512];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file. Not found?\n");
        return NULL;
    }
    VertexList *graph = NULL;
    int ID;
    Vertex* v;
    Vertex* vs;
    while (fgets(buffer, sizeof(buffer), fp)) {
        char *token = strtok(buffer, " ");
        ID = atoi(token);
        appendID(&graph, ID);
        v = searchID(graph, ID);
        token = strtok(NULL, " ");
        while (token != NULL) {
            ID = atoi(token);
            appendID(&graph, ID);
            vs = searchID(graph, ID);
            appendVertex(&v->sources, vs);
            token = strtok(NULL, " ");
        }
    }
    return graph;
}
