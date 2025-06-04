/* File        : stack.cpp */
/* Deskripsi   : Body ADT stack yang diimplementasikan dgn linked list */
/* Dibuat oleh : Ade Chandra Nugraha*/

#include "stack.h"
#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>
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
	if(S == NULL){
		return true;
	}else {return false;}
}

/**** Menambahkan sebuah elemen ke Stack ****/
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen stack S */
/* IS : S mungkin kosong */
/* FS : X menjadi TOP yang baru */
{
	List L;
	L.First=*S; ///dikarenakan insVfirstMemakai List
	InsVFirst(&L,X);
}

/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen TOP yang lama */
{
	address Del;
	if(*S !=NULL){
		if((*S)->next == NULL){
			Del = *S;
			*S=NULL;
			*X=Del->info;
			printf("%d",Del->info);
			free(Del);
		}else{
			Del =*S;
			*S = (*S)->next;
			Del->next=NULL;
			*X=Del->info;
			printf("%d",Del->info);
			free(Del);
		}
	}else{
		printf("UnderFlow Detected\n");
	}
	
}
