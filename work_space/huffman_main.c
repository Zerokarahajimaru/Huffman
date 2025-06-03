#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char* input_dinamis() {
    int ch, len = 0;
    int kapasitas = 10;
    char *str = malloc(kapasitas);

    if (!str) return NULL;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        str[len++] = ch;
        if (len >= kapasitas) {
            kapasitas *= 2;
            str = realloc(str, kapasitas);
            if (!str) return NULL;
        }
    }
    str[len] = '\0';
    return str;
}

int main(){
    char *test =input_dinamis();
    printf("%s",test);
}