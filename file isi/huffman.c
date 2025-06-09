#include "huffman.h"

HuffmanNode* new_node(unsigned char data, unsigned freq) {
    HuffmanNode* node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    if (!node) return NULL;
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

int is_leaf(HuffmanNode *node) {
    return !(node->left) && !(node->right);
}

void free_tree(HuffmanNode *root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}