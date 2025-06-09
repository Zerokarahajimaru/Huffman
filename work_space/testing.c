#include <stdio.h>

int main(){
    unsigned char a = 0 | 11;
    unsigned char b = 0 | 3;
    unsigned char c=  0 |14;  
    FILE * test=fopen("emir.txt","ab");
    if(test == NULL) {fwrite("gagal",m);return 999;}

    fprintf(test,"\nnah ini append boy '19'%c %c %c %c",a,b,c,89);
}