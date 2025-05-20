/* File        : stack.cpp */
/* Deskripsi   : Body ADT stack yang diimplementasikan dgn linked list */
/* Dibuat oleh : Ade Chandra Nugraha*/

#include "stack.h"
#include <stdlib.h>

/**** Perubahan nilai komponen struktur ****/
void SetTop (Stack *S, Stack NewTop )
/* Memberi Nilai TOP yang baru dengan NewTop */
{
	*S = NewTop;
}

/*    PROTO TYPE    */
/**** Konstruktor/Kreator ****/
void CreateEmpty (Stack *S)
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */
/* Ciri stack kosong : TOP bernilai NULL */
{
	*S = NULL;
}

/**** Predikat untuk test keadaan KOLEKSI ****/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack Kosong */
{
	return (S == NULL);
}

/**** Menambahkan sebuah elemen ke Stack ****/
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen stack S */
/* IS : S mungkin kosong */
/* FS : X menjadi TOP yang baru */
{
	Stack NewNode = (Stack) malloc(sizeof(ElmtList));
	if  (NewNode != NULL){
		NewNode-> info = X;
		NewNode-> next = *S;
		*S = NewNode;
	}
	
}
void DeAlokasi(address P) {
    free(P);
}
/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen TOP yang lama */
{
	if (*S != NULL) { 
        Stack Temp = *S; 
        *X = Temp->info; 
        *S = Temp->next;
        DeAlokasi(Temp);
}
}
void DecimaltoBiner(int n)
{
	Stack S;
	infotype bit;
	int temp = n ;
	
	CreateEmpty(&S);
	
	if (n == 0) {
        printf("0");
        return;
    }
    
     printf("%d", n); 
    while (n > 0) {
        bit = n % 2; 
        Push(&S, bit); 
        n /= 2; 
        if (n > 0) {
            printf(" -> %d", n); 
        }
    }
    printf(" -> 0\n");
    
    printf("Bilangan biner dari %d: ", temp);
    while (!IsEmpty(S)) {
        Pop(&S, &bit);
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    int number;

    printf("Masukkan bilangan desimal: ");
    scanf("%d", &number);

    DecimaltoBiner(number);

    return 0;
}

