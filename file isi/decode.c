#include "decode.h"
#include "huffman.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
    char magic[4];
    uint8_t char_count;
    uint16_t tree_size;
} HuffHeader;

// Read Huffman tree from file
HuffmanNode* read_huffman_tree(FILE *input) {
    int bit = fgetc(input);
    if (bit == '1') {
        return new_node(fgetc(input), 0);
    } else {
        HuffmanNode *node = new_node('$', 0);
        if (!node) return NULL;
        
        node->left = read_huffman_tree(input);
        node->right = read_huffman_tree(input);
        return node;
    }
}

// Decompress data using Huffman tree
void read_compressed_data(FILE *input, FILE *output, HuffmanNode *root, long data_end, int valid_bits) {
    HuffmanNode *current = root;
    int byte;
    DLLNode *dll_head = NULL, *dll_tail = NULL;
    StackNode *stack = NULL;

    while ((byte = fgetc(input)) != EOF && ftell(input) <= data_end) {
        int bit_count = (ftell(input) == data_end) ? valid_bits : 8;

        for (int i = 0; i < bit_count; ++i) {
            int bit = (byte >> (7 - i)) & 1;
            current = bit ? current->right : current->left;
            push(&stack, current);

            if (is_leaf(current)) {
                append_dll(&dll_head, &dll_tail, current->data);
                clear_stack(&stack);
                current = root;
            }
        }
    }

    write_dll_to_file(dll_head, output);
    free_dll(dll_head);
    clear_stack(&stack);
}

// Main decompression function
void decompress_file(const char *input_filename, const char *output_filename) {
    FILE *input = fopen(input_filename, "rb");
    if (!input) {
        perror("Failed to open input file");
        return;
    }

    // Read and validate file header
    HuffHeader header;
    if (fread(&header, sizeof(HuffHeader), 1, input) != 1) {
        fprintf(stderr, "Error reading file header\n");
        fclose(input);
        return;
    }

    if (strncmp(header.magic, "HUFF", 4) != 0) {
        fprintf(stderr, "Invalid file format\n");
        fclose(input);
        return;
    }

    // Read Huffman tree
    HuffmanNode *root = read_huffman_tree(input);
    if (!root) {
        fprintf(stderr, "Error building Huffman tree\n");
        fclose(input);
        return;
    }

    // Find compressed data end position
    fseek(input, -1, SEEK_END);
    int valid_bits = fgetc(input);
    long data_end = ftell(input) - 1;

    // Position to start of compressed data
    fseek(input, sizeof(HuffHeader) + header.tree_size, SEEK_SET);

    // Open output file
    FILE *output = fopen(output_filename, "wb");
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        free_tree(root);
        return;
    }

    // Decompress data
    read_compressed_data(input, output, root, data_end, valid_bits);

    // Cleanup
    fclose(input);
    fclose(output);
    free_tree(root);
}