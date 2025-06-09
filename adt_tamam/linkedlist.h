#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>

// Doubly linked list node structure
typedef struct DLLNode {
    unsigned char data;       // Data byte
    struct DLLNode *prev;     // Previous node pointer
    struct DLLNode *next;     // Next node pointer
} DLLNode;

// Linked list operations
DLLNode* create_dll_node(unsigned char data);                 // Create new node
void append_dll(DLLNode **head, DLLNode **tail, unsigned char data);  // Append node
void write_dll_to_file(DLLNode *head, FILE *output);          // Write list to file
void free_dll(DLLNode *head);                                 // Free entire list

#endif