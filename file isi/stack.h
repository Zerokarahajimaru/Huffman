#ifndef STACK_H
#define STACK_H

#include "huffman.h"

// Stack node structure
typedef struct StackNode {
    HuffmanNode *tree_node;   // Pointer to Huffman tree node
    struct StackNode *next;   // Pointer to next stack node
} StackNode;

// Stack operations
void push(StackNode **top, HuffmanNode *node);    // Push node onto stack
HuffmanNode* pop(StackNode **top);               // Pop node from stack
void clear_stack(StackNode **top);               // Clear entire stack

#endif