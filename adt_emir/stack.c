/* File        : stack.cpp */
/* Deskripsi   : Body ADT stack yang diimplementasikan dgn linked list */
/* Dibuat oleh : Ade Chandra Nugraha*/

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
/**** Perubahan nilai komponen struktur ****/
void SetTop (Stack *S, Stack NewTop )
/* Memberi Nilai TOP yang baru dengan NewTop */
{
	// *S = NewTop;	ini dipakai apabila pointer ke pointer node bukan LIST
}

/*    PROTO TYPE    */
/**** Konstruktor/Kreator ****/
void CreateEmpty (Stack *S)
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */
/* Ciri stack kosong : TOP bernilai NULL */
{
	(*S).First = NULL;
}

/**** Predikat untuk test keadaan KOLEKSI ****/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack Kosong */
{
	if(S.First == NULL){
		return true;
	}else {return false;}
}

/**** Menambahkan sebuah elemen ke Stack ****/
void Push (Stack *S, infotype X,int frekuensi)
/* Menambahkan X sebagai elemen stack S */
/* IS : S mungkin kosong */
/* FS : X menjadi TOP yang baru */
{
	InsVFirst(S,X,frekuensi);
}

/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X,int *frekuensi)
/* Menghapus X dari Stack S */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen TOP yang lama */
{
	DelVFirst(S,X,frekuensi);
}
