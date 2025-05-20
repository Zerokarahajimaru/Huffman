/*File body untuk ADT Queue*/
//Dibuat tanggal 28-3-2013

#include "queue.h"
#include <stdlib.h>
address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

void DeAlokasi(address P) {
    free(P);
}

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q)
{
	*Q = NULL;
}


/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q)
{
	 return (Q == NULL);
}

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q)
{
	 int i = 0;
	 while (Q == NULL){
	 	i++;
	 	Q = Q -> next;
	 }
	 if (i == NBElement) return true ;
	 return false;
}

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype X)
{
	address P = Alokasi(X);
    if (P == NULL) {
        printf("Gagal mengalokasikan memori\n");
        return;
    }

    // Tidak perlu pengecekan penuh jika menggunakan linked list
    printf("masuk \n");
    if (is_Empty(*Q)) {
        *Q = P; // Jika kosong, langsung jadikan elemen pertama
    } else {
        address temp = *Q;
        while (temp->next != NULL) { // Cari elemen terakhir
            temp = temp->next;
        }
        temp->next = P; // Tambahkan di belakang
    }
}


/*Melakukan deletion pada queue*/
void deQueue (Queue *Q, infotype *X)
{
	 address cursor;
	
	cursor = *Q;
	
	if(is_Empty(*Q)) {
		printf("List Kosong\n");
		return;
	}
	
	 while(cursor != NULL) {
	 	if(cursor->next == NULL) {
	 		DeAlokasi(*Q);
	 		*Q = NULL;
	 		
	 		break;
		}
		
		if(cursor->next->next == NULL) {
			DeAlokasi(cursor->next);
			cursor->next = NULL;
			
			break;	
		}
		
	 	cursor = cursor->next;
	 }
}

void PrintQueue (Queue Q) {
	while(Q != NULL) {
		if(Q->next == NULL) {
			printf("[%d]-|", Q->info);
		} else {
			printf("[%d]->", Q->info);
		}
		Q = Q->next;
	}
	printf("\n");
}

/* Fungsi utama */
int main() {
	
	Queue Q;
	
	CreateQueue(&Q);
	
	infotype isi;
	
	int selection;
	
	while (true) {
		printf("Selamat datang di BANK, layanan kami:\n");
		printf("1. Ambil Antrian\n");
		printf("2. Proses Antrian\n");
		printf("3. Tampil antrian\n");
		printf("Input angka untuk memilih layanan: ");
		scanf("%d", &selection);
		
		if(selection == 1) {
			if(is_Empty(Q)) {
				EnQueue(&Q, 1);
				continue;
			}
			
			if (is_Empty(Q)) {
    		EnQueue(&Q, 1);
			} else {
   			 address temp = Q;
    		while (temp->next != NULL) {
        	temp = temp->next;
    		}
    		EnQueue(&Q, temp->info + 1);
			}
			
			continue;
		}
		
		if(selection == 2) {
			deQueue(&Q, &isi);
			
			continue;
		}
		
		if(selection == 3) {
			PrintQueue(Q);
			
			continue;
		}
		
		printf("Layanan tidak tersedia\n");
	}
	
	return 0;
}

