#ifndef DECODE_H
#define DECODE_H
// #include "../adt_emir/bintree.h"
#include "../adt_emir/link_list.h"
#include "../adt_emir/stack.h"
#include "../adt_emir/Queue.h"

void main_menu();

void input_to_ll(List *head,FILE *zip_target);

Queue input_dll_to_queue(List dll,Queue *Q);

// BinTree build_tree_from_queue(Queue *q);

void selection_sort(address p);




// char convert_biner_to_hexa(char *biner){
//     int i=4;
//     char hexa=0;
//     char hexa_temp=0;
//     while(i >0){
//         if(*biner == 1){
//             hexa_temp=2;
//             for(int x =1;x<=i-1;x++){
//                 hexa_temp += hexa_temp;
//             }
//             hexa += hexa_temp;
//             i++;
//         }
//         if(*biner == 1 && i ==1 )hexa += 1;
//     }
//     return hexa;
// }

// char * biner_to_hexa_in_file(char *input_file){
//     FILE *decode_file=fopen(input_file,"rb");
//     FILE *output_hexa;
//     char biner[4];
//     char hexa=0;
//     char temp_biner;
//     STACK convert_to_hexa;
//     int decimal;

//     while( biner = (fgets(biner,4,decode_file)) != NULL){
//         for(int i=0;i<4;i++){
//             push(convert_to_hexa , biner[i]);
//         }

//         for(int i=0;i<4;i++){
//             biner[i] = pop(convert_to_hexa ,  biner[i]);
//         }
//         /*fprint di file cok*/convert_biner_to_hexa(biner);
//     }
// }

// void info_to_linkedlist(FILE *hexa){
//     infotype info;
//     address head_dll;
//     address temp;
//     while(fgets(&info,1,"hexa") != NULL ){
//         //linked list 
//         if(search_linked_list(head_dll,info) == true ){
//             temp=search_linked_list_return_address(head_dll,info);
//             temp->frekuensi += 1;
//         }else{
//             insertfirst(head_dll,info);
//         }
//     }
// }
    
#endif


