#ifndef GRAPHS_H 
#define GRAPHS_H

struct Vertex;

typedef struct VertexList {
    struct Vertex *v;
    struct VertexList *next;
} VertexList;

typedef struct Vertex {
    int ID;
    struct VertexList *sources;
} Vertex;

void appendID(VertexList **vList, int ID);
void appendVertex(VertexList **head, Vertex *vertex);
void dropVertex(VertexList **head, Vertex *v);
void dropID(VertexList **head, int ID);
Vertex* searchID(VertexList *head, int ID);
void redirect(Vertex* v1, Vertex* v2);
void contract(VertexList **vList, int ID1, int ID2);
void freeVertex(Vertex *v);
VertexList* parse_undirected(char *filename);
Vertex* getNth(VertexList *head, int n);
int countVertices(VertexList *head);
void redirectSources(VertexList *sources, Vertex* v1, Vertex *v2);
void freeSourceList(VertexList *head);
void freeGraph(VertexList *graph);

#endif