#include <stdio.h>
#include <stdlib.h>


void main_menu(){
    printf("1.encode\n");
    printf("2.decode\n");
    printf("3.help\n");
    printf("4.exit\n");
}

void input_file(){

}



char convert_biner_to_hexa(char *biner){
    int i=4;
    char hexa=0;
    char hexa_temp=0;
    while(i >0){
        if(*biner == 1){
            hexa_temp=2;
            for(int x =1;x<=i-1;x++){
                hexa_temp += hexa_temp;
            }
            hexa += hexa_temp;
            i++;   
        }
        if(*biner == 1 && i ==1 )hexa += 1;
    }
    return hexa;
}




char * biner_to_hexa_in_file(char *input_file){
    FILE *decode_file=fopen(input_file,"rb");
    FILE *output_hexa;
    char biner[4];
    char hexa=0;
    char temp_biner;
    STACK convert_to_hexa;
    int decimal;

    while( biner = (fgets(biner,4,decode_file)) != NULL){
        for(int i=0;i<4;i++){
            push(convert_to_hexa , biner[i]);
        }

        for(int i=0;i<4;i++){
            biner[i] = pop(convert_to_hexa ,  biner[i]);
        }
        /*fprint di file cok*/convert_biner_to_hexa(biner);
    }
}

void info_to_linkedlist(FILE *hexa){
    infotype info;
    dll head_dll;
    dll temp;
    while(fgets(&info,1,"hexa") != NULL ){
        //linked list 
        if(search_linked_list(head_dll,info) == true ){
            temp=search_linked_list_return_address(head_dll,info);
            temp->frekuensi += 1;
        }else{
            insertfirst(head_dll,info);
        }
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
    signed char adult = 150;
    printf("%d\n",adult);
}