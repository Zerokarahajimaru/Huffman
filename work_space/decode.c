#include <stdio.h>
#include <stdlib.h>
#include "decode.h"



void main_menu(){
    printf("1.encode\n");
    printf("2.decode\n");
    printf("3.help\n");
    printf("4.exit\n");
}

void input_to_ll(List *head,FILE *zip_target){
    unsigned char bit[2],first_hex,second_hex;
    address temp=NULL;

    if(zip_target == NULL)return;
    
    while(fgets(bit,2,zip_target) != NULL){
        first_hex= 15 & bit[0];
        second_hex=bit[0] >> 4;
    
    //dimasukan ke dll
    temp=Search(*head,first_hex);
    if(temp == NULL)InsVFirst(head,first_hex,1);
    else{
        ++(temp->frekuensi);
    }
    temp=Search(*head,second_hex);
    if(temp == NULL)InsVFirst(head,second_hex,1);
    else{
        ++(temp->frekuensi);
    }
}

}

Queue input_dll_to_queue(List dll,Queue *Q){
    address temp = dll.First;
    while(temp != NULL){
        EnQueue(Q,temp->info,temp->frekuensi);
        temp=temp->next;
    }
}

BinTree build_tree_from_queue(Queue *q){
    BinTree temp=NULL;
    BinTree parent=NULL;


    if(q->Front == NULL && q->rear == NULL)return NULL;
    
    //parameter dequeue dimasukan 
    parent=Alokasi_tree(255/*info*/,0/*frekuensi*/,0/*representasi*/);
    if(parent != NULL){
        parent->left = deQueue(q,parent->left->info,parent->left->frekuensi);
        parent->right = deQueue(q,parent->right->info,parent->right->frekuensi);
        parent->frekuensi = parent->left->frekuensi + parent->right->frekuensi;
    }
        
    while(parent != NULL && q != NULL){
        temp = parent;
        parent = Alokasi_tree();
    } 
    
}

// TODO sorting ini dia time complexnya  sigam n

void selection_sort(address p){
    if(p == NULL) return;
    address next_node=p->next;
    int frekuensi;
    infotype info;

        while(p !=NULL && p->prev != NULL && p->frekuensi < p->prev->frekuensi ){
            frekuensi=p->frekuensi;
            info=p->info;

            p->frekuensi=p->prev->frekuensi;
            p->info=p->prev->info;

            p->prev->frekuensi=frekuensi;
            p->prev->info=info;

            p=p->prev;
        }
        selection_sort(next_node);
}
    

//TODO 
/*
1.buat atau perbaiki search_linked_list ---
2.convert biner to hexa seatching di internet
3.search_linked_list_return_version
*/

