

#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"
#include "stack.h"
#include "../adt_emir/bintree.h"


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
    
void main_menu(){
    printf("1.encode\n");
    printf("2.decode\n");
    printf("3.help\n");
    printf("4.exit\n");
}

char first_4_bit(char byte){
    byte = byte << 4;
    
}

void input_to_ll(List *head,FILE *zip_target){
    char bit[2],first_hex,second_hex;
    address temp=NULL;
    while(fgets(bit,2,zip_target) != NULL){
        first_hex=bit[1] << 4;
        first_hex= first_hex >> 4;
        second_hex=bit[1] >> 4;
    
    //dimasukan ke dll
    temp=Search(*head,first_hex);
    if(temp == NULL)InsVFirst(head,1/*untuk frekuensi*/,first_hex);
    else{
        ++(temp->frekuensi);
    }
    temp=Search(*head,second_hex);
    if(temp == NULL)InsVFirst(head,1/*untuk frekuensi*/,second_hex);
    else{
        ++(temp->frekuensi);
    }
}

}

queue input_dll_to_queue(List dll){
    address temp = dll.First;
    while(temp != NULL){
        queue(temp->info);
        temp=temp->next;
    }
}

BinTree build_tree_from_queue(queue *q){
    BinTree temp=NULL;
    BinTree parent=NULL;


    if(q == NULL)return NULL;
    
    //parameter dequeue dimasukan 
    parent=Alokasi();
    if(parent != NULL){
        parent->left = dequeue();
        parent->right = dequeue();
        parent->frekuensi = parent->left->frekuensi + parent->right->frekuensi;
    }
        
    while(parent != NULL && q != NULL){
        temp = parent;
        parent = Alokasi();
    } 
    
}

void selection_sort(Head p){
    if(p == NULL) return;
    next_node=p->next;
    infotype temp;
    while(p->info < p->prev->info || p !=NULL){
        if(p->info < p->prev->info){
            temp=p->info;
            p->info=p->prev->info;
            p->prev->info=temp;
        }
        p=p->prev;
    }
    selection_sort(next_node);
}


//TODO 
/*
1.buat atau perbaiki search_linked_list
2.convert biner to hexa seatching di internet
3.search_linked_list_return_version
*/

void main(){
    struct mahasiswa test;
    test_casting((struct mahasiswa)(&test));
    printf("%d",test.emir);

    unsigned char bit;
}