#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../adt_emir/queue.h"
#include "../adt_emir/link_list.h"
#include "../adt_emir/stack.h"

int main(){
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
    infotype temp_info;
    int temp_frekuensi;
    List Q;
    Q.First=NULL;
    for(int i=10;i>=0;i--){
        Push(&Q,i,i);
    }
    for(int i=0;i<20;i++){
        Pop(&Q,&temp_info,&temp_frekuensi);
        printf("%d\n",temp_frekuensi);
        printf("%d\n",temp_info);
        if(Q.First== NULL){
            printf("ewean\n");
            break;
        }
    }
}