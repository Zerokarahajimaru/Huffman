#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

// Create a new doubly linked list node
DLLNode* create_dll_node(unsigned char data) {
    DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));
    if (!node) return NULL;
    
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

// Append a new node to the end of the list
void append_dll(DLLNode **head, DLLNode **tail, unsigned char data) {
    DLLNode *new_node = create_dll_node(data);
    if (!new_node) return;
    
    if (!*head) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}

// Write all list data to output file
void write_dll_to_file(DLLNode *head, FILE *output) {
    while (head) {
        fputc(head->data, output);
        head = head->next;
    }
}

// Free all nodes in the list
void free_dll(DLLNode *head) {
    while (head) {
        DLLNode *temp = head;
        head = head->next;
        free(temp);
    }
}