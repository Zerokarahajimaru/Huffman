#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../adt_emir/queue.h"
#include "../adt_emir/link_list.h"
#include "../adt_emir/stack.h"
#include "decode.h"


// unsigned char buffer[8];
// FILE *kancil=fopen("checker.png","rb");
// if(kancil == NULL) return 100;
// while (fgets(buffer,8,kancil) != NULL){
//     for(int i=0;i<8;i++){
//         if(buffer[i] != '\0')
//         printf("%d\n",buffer[i]);
//     }
// }
// unsigned char bit=255;
// printf("%d\n",bit );
// bit = bit >> 4;
// printf("%d\n",bit );
// bit = bit << 4;
// printf("%d\n",bit );
// bit = bit >> 4;
// printf("%d\n",bit );



/*test untuk stack que dll*/

// infotype temp_info;
// int temp_frekuensi;
// List Q;
// Q.First=NULL;
// for(int i=10;i>=0;i--){
//     Push(&Q,i,i);
// }
// for(int i=0;i<20;i++){
    //     Pop(&Q,&temp_info,&temp_frekuensi);
    //     printf("%d\n",temp_frekuensi);
    //     printf("%d\n",temp_info);
    //     if(Q.First== NULL){
        //         printf("ewean\n");
        //         break;
        //     }
        // }

void main(){
    //init variable
    List head_dll;
    Stack S;
    Queue Q;
    FILE *encoding_target = NULL;

    int choice=0;
    char file_name[40];

    //set adt ke NULL syarat dapat menjalankan adt yang telang dibuat
    S.First=NULL;
    head_dll.First = NULL;
    CreateQueue(&Q);

        encoding_target= fopen("../misc/Wallpaper-Steinsgate-Anime-Girls-Makise-Kurisu-Tie-St4.jpg","rb");
        if(encoding_target == NULL) return;
        input_to_ll(&head_dll,encoding_target);

        
        address temp=head_dll.First;
        selection_sort((head_dll.First));
        while(temp != NULL){
            printf("info =%d\n",temp->info);
            printf("frekuensi=%d\n",temp->frekuensi);
            temp=temp->next;
        }

        input_dll_to_queue(head_dll,&Q);
        temp=Q.Front;
                while(temp != NULL){
            printf("Q info =%d\n",temp->info);
            printf("Q frekuensi=%d\n",temp->frekuensi);
            temp=temp->next;
        }   
    }



    // FILE *makise=fopen("../misc/checker.png","rb");
    // if(makise == NULL)return 1;
    // char buffer[3];
    // while( fgets(buffer,3,makise) != NULL){
    //     for(int i=0; i<3 ; i++){
    //         printf("%d",buffer[i]);
    //     }
    // }