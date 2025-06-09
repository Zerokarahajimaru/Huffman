    #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../adt_emir/queue.h"
#include "../adt_emir/link_list.h"
#include "../adt_emir/stack.h"
#include "encode.h"
#include <unistd.h>

void main(int argc, char *argv[]){
    //init variable
    List head_dll;
    Stack S;
    Queue Q;
    BinTree T;
    FILE *encoding_target = NULL;
    FILE *decoding_target=NULL;
    int choice=0;
    char file_name[100]={0};
    char clear_buffer[2];
    //set adt ke NULL syarat dapat menjalankan adt yang telang dibuat
    S.First=NULL;
    head_dll.First = NULL;
    T=NULL;
        for(int i=0;i<41;i++){
        file_name[i]=0;
    }
    while(1){
        main_menu();
        scanf("%d",&choice);
        switch (choice)
    {
        case 1:

        fgets(clear_buffer,2,stdin);
        printf("masukan nama file:\n");
        fgets(file_name,100,stdin);
        file_name[strcspn(file_name, "\n")] = '\0';
    encoding_target= fopen(file_name,"rb");


    if(encoding_target == NULL) {printf("file tidak ada");return;}
    input_to_ll(&head_dll,encoding_target);
    CreateQueue(&Q);

        address temp=head_dll.First;
        selection_sort((head_dll.First));
        while(temp != NULL){
            printf("info from dll =%d\n",temp->info);
            printf("frekuensi from dll=%d\n",temp->frekuensi);
            temp=temp->next;
        }

        input_dll_to_queue(head_dll,&Q);
        temp=Q.Front;
        while(temp != NULL){
            printf("Q info =%d\n",temp->info);
            printf("Q frekuensi=%d\n",temp->frekuensi);
            temp=temp->next;
        } 
         T=build_tree_from_queue(&Q);
         if(T != NULL)PreOrder(T);
        DelAll(&head_dll);

        break;
      
    case 2:
    printf("program ditutup\n");
    return;
        break;
        default:
        break;
    }
    
}
}
