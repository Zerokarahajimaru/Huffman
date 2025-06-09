#include "decode.h" // Hanya perlu decode.h
#include <stdio.h>
#include <string.h>

void print_usage() {
    printf("Usage:\n");
    printf("  Decompress: huffman -d input.huf output.bmp\n"); // Hapus opsi kompresi
}

int main(int argc, char *argv[]) {
    if (argc != 4 || strcmp(argv[1], "-d") != 0) { // Hanya cek opsi -d
        print_usage();
        return 1;
    }

    printf("Decompressing %s to %s...\n", argv[2], argv[3]);
    decompress_file(argv[2], argv[3]);
    
    printf("Operation completed successfully.\n");
    return 0;
}