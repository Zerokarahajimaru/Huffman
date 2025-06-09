#include "stack.h"
#include <stdlib.h>

// Push a Huffman tree node onto the stack
void push(StackNode **top, HuffmanNode *node) {
    StackNode *new_node = (StackNode*)malloc(sizeof(StackNode));
    if (!new_node) return;
    
    new_node->tree_node = node;
    new_node->next = *top;
    *top = new_node;
}

// Pop a Huffman tree node from the stack
HuffmanNode* pop(StackNode **top) {
    if (!*top) return NULL;
    
    StackNode *temp = *top;
    HuffmanNode *node = temp->tree_node;
    *top = temp->next;
    free(temp);
    
    return node;
}

// Clear all nodes from the stack
void clear_stack(StackNode **top) {
    while (*top) {
        pop(top);
    }
}