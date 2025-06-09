#include <stdio.h>
#include <stdlib.h>
#include "encode.h"
#include <string.h>


void main_menu(){
    printf("1.encode\n");
    printf("2.exit\n");
}

void input_to_ll(List *head,FILE *zip_target){
    unsigned char bit[2],first_hex,second_hex;
    address temp=NULL;

    if(zip_target == NULL)return;
    
    while(fgets(bit,2,zip_target) != NULL){
        first_hex= 15 & bit[0];
        second_hex=bit[0] >> 4;
    
    //dimasukan ke dll
    temp=Search(*head,first_hex);
    if(temp == NULL)InsVFirst(head,first_hex,1);
    else{
        ++(temp->frekuensi);
    }
    temp=Search(*head,second_hex);
    if(temp == NULL)InsVFirst(head,second_hex,1);
    else{
        ++(temp->frekuensi);
    }
}

}

Queue input_dll_to_queue(List dll,Queue *Q){
    address temp = dll.First;
    while(temp != NULL){
        EnQueue(Q,temp->info,temp->frekuensi);
        temp=temp->next;
    }
}

BinTree build_tree_from_queue(Queue *q){
    BinTree temp=NULL;
    BinTree parent=NULL;
    BinTree temp_frekuensi_node= NULL;
    int frekuensi=0;
    esu info=0;
    na representasi= NULL;

    if(q->Front == NULL && q->rear == NULL)return NULL;
    
    //parameter dequeue dimasukan 
    parent=Alokasi_Tree(255/*info*/,0/*frekuensi*/); //apabila input to dll di ubah ini juga diubah
    if(parent != NULL){
        if(q->Front != NULL && q->rear != NULL){
            deQueue(q,&info,&frekuensi);
            parent->left= Alokasi_Tree(info,frekuensi);
        }
        if(q->Front != NULL && q->rear != NULL){
            deQueue(q,&info,&frekuensi);
            parent->right= Alokasi_Tree(info,frekuensi);
        }
        //TODO berikan selection apabila parent nya itu tidak punya left son atau right son
        parent->frekuensi = parent->left->frekuensi + parent->right->frekuensi;
    }
        
    while(parent != NULL && q->Front != NULL && q->rear != NULL){
        temp = parent;
        deQueue(q,&info,&frekuensi);
        temp_frekuensi_node = Alokasi_Tree(info,frekuensi);
        if(temp->frekuensi > temp_frekuensi_node->frekuensi ){
            parent=Tree(255,(temp_frekuensi_node->frekuensi + temp->frekuensi),temp_frekuensi_node,temp);
        }else{
            parent=Tree(255,(temp_frekuensi_node->frekuensi + temp->frekuensi),temp,temp_frekuensi_node);
        }
    }
    return parent;
}

// TODO sorting ini dia time complexnya  sigam n

void selection_sort(address p){
    if(p == NULL) return;
    address next_node=p->next;
    int frekuensi;
    infotype info;

        while(p !=NULL && p->prev != NULL && p->frekuensi < p->prev->frekuensi ){
            frekuensi=p->frekuensi;
            info=p->info;

            p->frekuensi=p->prev->frekuensi;
            p->info=p->prev->info;

            p->prev->frekuensi=frekuensi;
            p->prev->info=info;

            p=p->prev;
        }
        selection_sort(next_node);
}
    
// void insert_bit_and_representation(BinTree T,unsigned char *representasi/*buat mengambil nilai untuk representasi bukan untuk dipasangkan di next*/,unsigned char bit /*jumlah bit si representasinya*/){
//     if(T == NULL)return;

//     const unsigned char left=0;
//     const unsigned char right=1;

//     unsigned char byte = 1;
//     unsigned char temp = 0;
//     unsigned char *r = NULL; //tipe datanya nanti diganti dengan linked list:

//     T->bit=bit;
//     if(bit >0){

//         while(bit > 8){
//             ++byte;
//             bit=bit-8;
//         }
//     }else byte =0;

    
//     if(T->left != NULL){
//         if(byte > 0) r = (unsigned char *)calloc(byte* sizeof(unsigned char));
//         for (int i=0;byte >= 1; --byte ){
//             r[i]=representasi[i];
//             i++;
//         }
//         temp=left << (8 - bit );
//         *r = temp | *representasi;
//         T->representasi = r;
//         insert_bit_and_representation(T->left,r,bit+1);
//     }

//     if(T->right != NULL){
//         if(byte > 0) r = (unsigned char *)calloc(byte * sizeof(unsigned char));
//         temp=right << (8 - bit );
//         *representasi = temp | *representasi;
//         insert_bit_and_representation(T->right,,bit+1);    
//     }
// }



// void input_header(BinTree T,char * namefile,FILE * NotEncodeFile){
//     if(T != NULL) return NULL;

//     const unsigned char newline ='\n';
//     unsigned char NotEncoded_buffer[2]; //untuk menganmbil isi dari image
//     unsigned char *P_representation=NULL; // untuk mengambil memory dinamis field node tree representasi
//     unsigned char representasinya_berapa_bit=0;//berapa bit representasi dari node
//     unsigned char bit_position=8;//posisi bit nya
//     unsigned char representation_i=0;//apabila bit > 8 maka dia itu akan menambah dan 1 representasi ini itu dia 8 bit
//     unsigned char representasi_buffer_to_file=0;//variable ini digunakan untuk menyimpan nilai buffer dan apabila udah penuh masukin ke file
//     int bit_YangTersisa=0; //variable yang menunjukan sisa tempat di bit 
//     unsigned char byte=0;
//     unsigned char geser=0;
//     int temp=0; //digunakan untuk menyimpan hasil dari bit yang tersisa
//     unsigned char P_representation_bit_position=8;
//     unsigned char sisa=0;
//     huffmanheader hfh;

//     FILE * EncodedFile =fopen(namefile,"wb");
    
//     strcpy(hfh.extension ,".hfm");//ini benerin oy
//     hfh.sum=nbElmt(T);

//     //1.masukin ekstensi 2. sumnya terus close file bukan dengan append untuk memasukan info dan representasinya
//     fclose(EncodedFile);
//     EncodedFile=fopen(namefile,"ab");
//     traversal_untuk_mencari_info_dan_representation_dan_masukan_ke_file(T,EncodedFile);

//     //bagian convert image to bit representation
//     fwrite((unsigned char *)&newline,sizeof(unsigned char),1,EncodedFile);
//     while(fgets(NotEncoded_buffer,2,NotEncodeFile != NULL)){
//         conversion_of_image_to_text(T,&P_representation,&representasinya_berapa_bit,NotEncoded_buffer[0]);
//         bit_YangTersisa = bit_position - representasinya_berapa_bit;

//         if(bit_YangTersisa >=0){
//             representasi_buffer_to_file =  P_representation[i] << bit_YangTersisa;
//             if(bit_YangTersisa == 0)bit_position=8;
//             else{
//                 bit_position -=representasinya_berapa_bit;
//             }
//         }else{
//             sisa=8-bit_position;

//             representasi_buffer_to_file =P_representation[i] << P_representation_bit_position ;
//             P_representation_bit_position -= sisa;
            
//             representasinya_berapa_bit -= sisa;


            

//         }
        
//         bit_position -= representasinya_berapa_bit;//dipake setelah  bit_YangTersisa = bit_position - representasinya_berapa_bit;

        

//         //ngurusin representasinya_berapa_bit

            
//     }
// }

// void conversion_of_image_to_text(BinTree T,unsigned char **representation/*mengambil representasi dari node*/,unsigned char *bit/*dia representasinya berapa bit*/,unsigned char info/*info yang dicari*/){
    
//     if(T == NULL)return;

    
// }



//     void traversal_untuk_mencari_info_dan_representation_dan_masukan_ke_file(BinTree T,FILE * huffman_append_mode)/*nanti di input header opennya memakai append mode biner kalo ada*/{
//         huffmanheader hfh;
//         unsigned char byte = 1;
//         unsigned bit=T->bit;
//         const unsigned char space =' ';
//         const unsigned char newline ='\n';

//         if(bit == 0)byte =0;
//         else{
//             while(bit > 8){
//                 ++byte;
//                 bit=bit-8;
//             }
//         }

//         hfh.info=T->info;
//         //hfh.info dimasukin ke file
//         fwrite((unsigned char *)&newline,sizeof(unsigned char),1,huffman_append_mode);
//         fwrite((unsigned char *)&(T->info),sizeof(unsigned char),1,huffman_append_mode);
//         fwrite((unsigned char *)&space,sizeof(unsigned char),1,huffman_append_mode);
       
//         for(int i=0;i<byte;i++){
//             hfh.repesentation=&(T->representasi[i]);
//             //hfh.representation dimasukin ke file:
//             fwrite((unsigned char *)hfh.repesentation,sizeof(unsigned char),1,huffman_append_mode);
//         }

//         traversal_untuk_mencari_info_dan_representation_dan_masukan_ke_file(T->left);
//         traversal_untuk_mencari_info_dan_representation_dan_masukan_ke_file(T->right);
//     }
