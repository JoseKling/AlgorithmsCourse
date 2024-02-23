#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

Vertex* getNth(VertexList *head, int n) {
    VertexList *current = head;
    for (int i = 0; (current != NULL) && (i < n); i++) {
        current = current->next;
    }
    if (current == NULL) {
        return NULL;
    } else {
        return current->v;
    }
}

Vertex* searchID(VertexList *head, int ID) {
    VertexList *current = head;
    while ((current != NULL) && (current->v->ID != ID)) {
        current = current->next;
    }
    if (current == NULL) {
        return NULL;
    } else {
        return current->v;
    }
}

void appendID(VertexList **vList, int ID) {
    if (searchID(*vList, ID) == NULL) {
        Vertex *v = (Vertex*)malloc(sizeof(Vertex));
        v->ID = ID;
        v->sources = NULL;
        appendVertex(vList, v);
    }
    return;
}

void appendVertex(VertexList **head, Vertex *vertex) {
    VertexList *new_item = (VertexList*)malloc(sizeof(VertexList));
    if (new_item == NULL) {
        printf("Memory allocation failed\n");
        freeVertex(vertex);
        return;
    }
    if (*head == NULL) {
        new_item->v = vertex;
        new_item->next = NULL;
        *head = new_item;
        return;
    }
    VertexList *last = NULL;
    VertexList *current = *head;
    while (current != NULL) {
        if (vertex->ID < current->v->ID) {
            new_item->v = vertex;
            new_item->next = last->next;
            if (last == NULL) {
                *head = new_item;
                return;
            } else {
                last->next = new_item;
                return;
            }
        } else {
            last = current;
            current = current->next;
        }
    }
    new_item->v = vertex;
    new_item->next = NULL;
    last->next = new_item;
    return;
}

void dropVertex(VertexList **head, Vertex *v) {
    int ID = v->ID;
    dropID(head, ID);
    return;
}

void dropID(VertexList **head, int ID) {
    if (*head == NULL) {
        return;
    }
    VertexList *temp;
    VertexList *last = NULL;
    VertexList *current = *head;
    while (current != NULL) {
        if (current->v->ID == ID) {
            if (last == NULL) {
                *head = current->next;
            } else {
                last->next = current->next;
            }
            temp = current->next;
            current = temp;
        } else {
            last = current;
            current = current->next;
        }
    }
    return;
}

void redirectSources(VertexList *sources, Vertex* v1, Vertex *v2) {
    VertexList *current = sources;
    while (current != NULL) {
        if (current->v->ID == v1->ID) {
            current->v = v2;
        }
        current = current->next;
    }
}

void redirect(Vertex* v1, Vertex* v2) {
    VertexList *last = v2->sources;
    VertexList *current = v1->sources;
    int currentID = 0;
    while (current != NULL) {
        if (current->v->ID != currentID) {
            redirectSources(current->v->sources, v1, v2);
            currentID = current->v->ID;
        }
        current = current->next;
    }
    if (last != NULL) {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = v1->sources;
    } else {
        v2->sources = v1->sources;
    }
    v1->sources = NULL;
    return;
}

void contract(VertexList **vList, int ID1, int ID2) {
    Vertex *v1 = searchID(*vList, ID1);
    Vertex *v2 = searchID(*vList, ID2);
    dropID(&v1->sources, ID2);
    dropID(&v2->sources, ID1);
    redirect(v1, v2);
    dropVertex(vList, v1);
    free(v1);
    return;
}

int countVertices(VertexList *head) {
    int count = 0;
    VertexList *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void freeVertex(Vertex *v) {
    freeSourceList(v->sources);
    free(v);
}

void freeSourceList(VertexList *head) {
    VertexList *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeGraph(VertexList *graph) {
    VertexList *temp;
    // Free all source lists
    for (VertexList *v = graph; v != NULL; v = v->next) {
        freeSourceList(v->v->sources);
    }
    // Free all vertices and the graph list
    while (graph != NULL) {
        temp = graph;
        graph = graph->next;
        free(temp->v);
        free(temp);
    }
}