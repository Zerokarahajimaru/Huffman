#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
    unsigned char bit=255;
    printf("%d\n",bit );
    bit = bit >> 4;
    printf("%d\n",bit );
    bit = bit << 4;
    printf("%d\n",bit );
    bit = bit >> 4;
    printf("%d\n",bit );
}