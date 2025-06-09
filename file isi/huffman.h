#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct HuffmanNode {
    unsigned char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
} HuffmanNode;

// Deklarasikan sebagai extern (bisa diimplementasikan di file .c manapun)
HuffmanNode* new_node(unsigned char data, unsigned freq);

int is_leaf(HuffmanNode *node);
void free_tree(HuffmanNode *root);

#endif