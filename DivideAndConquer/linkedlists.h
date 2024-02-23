#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct NodesList {
    struct Node *start;
    struct NodesList *next;
} NodesList;

Node* throughList(Node* head, int n);
NodesList* throughNodesList(NodesList* head, int n);
void appendNode(Node** head, Node* node);
void appendNewNode(Node** head, int value);
void appendNodesList(NodesList** head, Node* start);
Node* searchNodes(Node* head, int target);

#endif