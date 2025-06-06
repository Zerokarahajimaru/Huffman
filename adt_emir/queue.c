/*File body untuk ADT Queue*/
//Dibuat tanggal 28-3-2013

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *L)
{
        L->Front=NULL;
        L->rear=NULL;
    
}


/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue L)
{
    if(L.Front == NULL && L.rear == NULL){
        return true;
    }else{
        return false;
    }
}

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue *L)
{
    int buffer=0;
    address P;
    if(L->Front !=NULL && L->rear != NULL){
    P=L->rear;
    do{
    P=P->next;
    buffer++;
    }while(P->next !=NULL);
}else{
    return false;
}

    if(buffer == 10){
        return true;

    }else{
        return false;
    }
}

/*Melekukan insertion pada queue*/
void EnQueue (Queue *L, infotype X,int frekuensi)
{
    if(is_Full(L)) {    printf("stack sudah penuh\n"); return; }

    address temp=NULL;

    temp=(address)malloc(sizeof(ElmtList));

    //apabila alokasinya gagal
    if(temp == NULL)return;

	if(L->Front == NULL && L->rear == NULL){
        temp->info=X;
        temp->frekuensi=frekuensi;
        temp->next=NULL;
        temp->prev=NULL;
        L->rear=temp;
        L->Front=temp;
    }
    else{
        temp->info=X;
        temp->frekuensi=frekuensi;
        temp->next=NULL;
        
        temp->prev = L->rear;
        L->rear->next=temp;
        L->rear=temp;
    }
}
    



/*Melakukan deletion pada queue*/
void deQueue (Queue *L, infotype *X,int *frekuensi)
{
    address P;

    if(L->rear == NULL && L->Front ==NULL){
        printf("underflow\n");
        return;
    }else{
        if(L->rear == L->Front){
            *X=L->Front->info;
            *frekuensi=L->Front->frekuensi;
            L->Front->next=NULL;
            L->Front->prev=NULL;
            L->Front=NULL;
            L->rear=NULL;
            free(L->Front);
        }else{
            P=L->Front->next;
            P->prev=NULL;
            *X=L->Front->info;
            *frekuensi=L->Front->frekuensi;
            L->Front->next=NULL;
            L->Front->prev=NULL;
            free(L->Front);
            L->Front=P;
        }
    }
}