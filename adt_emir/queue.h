/*File header untuk ADT Queue*/

#ifndef queue_h
#define queue_h
#include "BOOLEAN.H"
#include "link_list.h"
#define NBElement 10


typedef struct {
    address Front;
    address rear;
    } List_queue;

typedef List_queue Queue;


/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *L);

/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue L);

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue *L);

/*Melekukan insertion pada queue*/
void EnQueue (Queue *L, infotype X,int frekuensi);

/*Melakukan deletion pada queue*/
void deQueue (Queue *L, infotype *X,int *frekuensi);

#endif

