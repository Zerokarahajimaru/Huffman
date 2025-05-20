/*File header untuk ADT Queue*/

#ifndef queue.h
#define queue.h
#include "boolean.h"
#include "linked.h"
#define NBElement 10


typedef address Queue;

typedef struct tNode {
    infotype info;
    struct tNode *next;
} Node;



/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q);

/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q);

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q);

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype X);

/*Melakukan deletion pada queue*/
void deQueue (Queue *Q, infotype *X);

void PrintQueue (Queue Q);

#endif

