#ifndef DECODE_H
#define DECODE_H
// #include "../adt_emir/bintree.h"
#include "../adt_emir/link_list.h"
#include "../adt_emir/stack.h"
#include "../adt_emir/Queue.h"
#include "../adt_emir/bintree.h"

typedef struct HuffmanHeader{
    unsigned char extension[5];
    int sum;
    unsigned char info;
    unsigned char *repesentation;
}huffmanheader;

void main_menu();

void input_to_ll(List *head,FILE *zip_target);

Queue input_dll_to_queue(List dll,Queue *Q);

BinTree build_tree_from_queue(Queue *q);

void selection_sort(address p);

// void traversal_untuk_mencari_info_dan_representation_dan_masukan_ke_file(BinTree T,FILE * huffman_append_mode);

// void input_header(BinTree T,char * namefile,char * EncodedFileName)

// void conversion_of_image_to_text(BinTree T,unsigned char **representation/*mengambil representasi dari node*/,unsigned char *bit/*dia representasinya berapa bit*/,unsigned char info/*info yang dicari*/);

// void insert_bit_and_representation(BinTree T,unsigned char *representasi/*buat mengambil nilai untuk representasi bukan untuk dipasangkan di next*/,unsigned char bit /*jumlah bit si representasinya*/);
#endif


