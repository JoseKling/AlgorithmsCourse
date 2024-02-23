 #include "linkedlists.h"
 #include <stdio.h>
 #include <stdlib.h>

Node* throughList(Node* head, int n) {
    Node* current = head;
    if (current == NULL) {
        printf("Error: empty list.\n");
        return NULL;
    }
    if (n < 0) {
        while (current->next != NULL) {
            current = current->next;
        }
        return current;
    } else {
        for (int i = 0; i < n; i++) {
            if (current->next == NULL) {
                printf("Error: out of range.\n");
                return NULL;
            }
            current = current->next;
        }
        return current;
    }
}

NodesList* throughNodesList(NodesList* head, int n) {
    NodesList* current = head;
    if (current == NULL) {
        printf("Error: empty list.\n");
        return NULL;
    }
    if (n < 0) {
        while (current->next != NULL) {
            current = current->next;
        }
        return current;
    } else {
        for (int i = 0; i < n; i++) {
            if (current->next == NULL) {
                printf("Error: out of range.\n");
                return NULL;
            }
            current = current->next;
        }
        return current;
    }
}

void appendNewNode(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: out of memory.\n");
        return;
    }
    new_node->next = NULL;
    new_node->val = value;
    if (*head == NULL) {
        *head = new_node;
        return;
    } else {
        Node* last = throughList(*head, -1);
        last->next = new_node;
        return;
    }
}

void appendNode(Node** head, Node* node) {
    if (*head == NULL) {
        *head = node;
        return;
    } else {
        Node* last = throughList(*head, -1);
        last->next = node;
        return;
    }
}

void appendNodesList(NodesList** head, Node* start) {
    NodesList* new_node = (NodesList*)malloc(sizeof(NodesList));
    if (new_node == NULL) {
        printf("Error: out of memory.\n");
        return;
    }
    new_node->next = NULL;
    new_node->start = start;
    if (*head == NULL) {
        *head = new_node;
        return;
    } else {
        NodesList* last = throughNodesList(*head, -1);
        last->next = new_node;
        return;
    }
}

Node* searchNodes(Node* head, int target) {
    if (head == NULL) {
        printf("Error: empty list.\n");
        return NULL;
    }
    Node* current = head;
    while (current->next != NULL) {
        if (current->val == target) {
            return current;
        }
    }
    return NULL;
}