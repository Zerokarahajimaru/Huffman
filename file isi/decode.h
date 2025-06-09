#ifndef DECODE_H
#define DECODE_H

#include "huffman.h"
#include "stack.h"
#include "linkedlist.h"

// Decompression functions
void decompress_file(const char *input_filename, const char *output_filename);
HuffmanNode* read_huffman_tree(FILE *input);
void read_compressed_data(FILE *input, FILE *output, HuffmanNode *root, long data_end, int valid_bits);
void print_usage();
#endif