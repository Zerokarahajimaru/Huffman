#include "../adt_emir/bintree.h"
#include <stdio.h>
#include <stdlib.h>

/*selektor*/
esu Getakar(BinTree P){
    return InfoTree(P);
}
BinTree GetLeft(BinTree P){
    if(IsUnerLeft(P) !=false )return LeftTree(P);
    return NULL;
}

BinTree GetRight(BinTree P){
    if(IsUnerRight(P) !=false)return RightTree(P);
    return NULL;
}
/*selektor*/

/*konstsruktor*/
pnode Alokasi_Tree(esu X,int frekuensi){
    pnode T=(pnode)malloc(sizeof(Node));
    if(T != NULL){
        //bagian yang harus diubah apabila infotype dirubah
        InfoTree(T)=X;
        T->frekuensi=frekuensi;

        LeftTree(T)=NULL;
        RightTree(T)=NULL;
        return T;
    }else return NULL;
}

//mengembalikan root yang LeftTree dan RightTree nya bisa costumisasi
BinTree Tree(esu Akar,int frekuensi, BinTree L, BinTree R){
    BinTree P=Alokasi_Tree(Akar,frekuensi);
    if(P != NULL){
        LeftTree(P)=L;
        RightTree(P)=R;
        return P;
    }else return NULL;
}
//omak 
void MakeTree (esu Akar,int frekuensi, BinTree L, BinTree R, BinTree *P){
    *P=Tree(Akar,frekuensi,L,R);
}

//nilai di input oleh user 
void BuildTree(BinTree *P){
    
}
/*konstsruktor*/

/*predikat penting*/
boolean IsUnerLeft(BinTree P){
    if(LeftTree(P) != NULL) return true;
    return false;
}

boolean IsUnerRight(BinTree P){
    if(RightTree(P) != NULL) return true;
    return false;
}

boolean IsBiner(BinTree P){
    if(IsUnerLeft(P) == true  && IsUnerRight(P) == true) return true;
    return false;
}

boolean IsEmptyTree(BinTree P){
    if(IsUnerLeft(P) != true  && IsUnerRight(P) != true) return true;
    return false;
}


void PreOrder(BinTree P){
    /*alur algoritmanya*/
    //1.dia akan menelursui LeftTree son sampe habis dan sambil diproses
    // 2.kalo sudah engga ada LeftTree son dia akan ke RightTree son 
    // 3.dia akan check LeftTree son ada engga
    // 4.dan rekursif selesai saat berada di root tapi root nya engga di proses lagi
    if(P == NULL)return;
    
    int byte=1;
    unsigned char temp=P->bit;
    while(temp >8){
        temp -= 8;
        byte++;
    }

    printf("info = %d\n",P->info);//InfoTree(P);
    printf("frekuensi = %d\n",P->frekuensi);//InfoTree(P);
    printf("bit = %d\n",P->bit);//InfoTree(P);
    if(P->representasi != NULL){
        for(int i=0 ; i < byte; i++){
            printf("representasi = %d\n",(P->representasi[i]));//InfoTree(P);
        }
    }
    printf("\n\n");//InfoTree(P);
    
    PreOrder(LeftTree(P));
    PreOrder(RightTree(P));
}

void PostOrder(BinTree P){
    /*alur algoritmanya*/
    // 1.LeftTree son 
    // 2.RightTree son 
    // 3.parent
    // 4.apabila saat mengunjungi parent masih memililki anak maka lakkukan step 1-4
    if(P == NULL)return;
    PostOrder(LeftTree(P));
    PostOrder(RightTree(P));
    printf("info=%d\n",InfoTree(P));//InfoTree(P);
    printf("frekuensi=%d\n",P->frekuensi);//InfoTree(P);
}

void InOrder(BinTree P){
     /*alur algoritmanya*/
    // 1.LeftTree son 
    // 2.parent
    // 3.RightTree son 
    // 4.apabila saat mengunjungi parent masih memililki anak maka lakkukan step 1-4
    if(P == NULL)return;

    if(IsUnerLeft(P) != false)InOrder(LeftTree(P));
    printf("%d\n",InfoTree(P));//melakukan aksi bebas aksi nya mau tambah print dan lain lain
    if(IsUnerRight(P) != false)InOrder(RightTree(P));
}
/*predikat penting*/


boolean Search_Tree(BinTree P,esu X){
    if(P == NULL)return false;
    boolean status=false;

    if(X == InfoTree(P))status=true;

    if(IsUnerLeft(P) !=false && status == false) status=Search_Tree(LeftTree(P),X);
    if(IsUnerRight(P) != false && status == false)status=Search_Tree(RightTree(P),X);
    return status; 
}

int nbElmt(BinTree P){//masih belum di optimasi
    //memakai pre order
    if(P == NULL)return 0;
    int i=1;
    if(IsUnerLeft(P) != false) i=i+nbElmt(LeftTree(P));
    if(IsUnerRight(P) != false)i=i+nbElmt(RightTree(P));
    return i;
}

void LevelOrder (BinTree root){
    if(root == NULL)return;

    BinTree *parent_current=NULL;
    BinTree *parent_next=NULL;
    /*dikarenakan root nya ada maka parent count =1*/
    int current_parent=1,next_parent=0;
    int loop=0;

    /*****************rootnya di proses ********************/
    printf("%d\n",InfoTree(root));
    /*****************rootnya di proses ********************/
    parent_current=(BinTree*)malloc(current_parent*sizeof(struct tElmtTree));
    *parent_current=root;
        while(current_parent > 0){
        for(int i=0;i<current_parent;i++){
            if (parent_current[i]->left != NULL){
                /*************son di proses ***************/
                printf("%d\n",(parent_current[i])->left->info);
                
                /*************son di proses ***************/
                next_parent++;
            }
            if (parent_current[i]->right != NULL){
                /*************son di proses ***************/
                printf("%d\n",(parent_current[i])->right->info);
                
                /*************son di proses ***************/
                next_parent++;
            }
        }
        parent_next=(BinTree*)malloc(current_parent*sizeof(struct tElmtTree));
        for(int i=0;i<current_parent;++i){
            parent_next[i]=parent_current[i]; 
        }
        free(parent_current);
        parent_current=NULL;

        if(next_parent > 0)parent_current=(BinTree*)malloc (next_parent*sizeof(struct tElmtTree));
        
        for(int i=0;i<next_parent;i++){
            if (parent_next[i]->left != NULL){
                parent_current[loop] =parent_next[i]->left;
                loop++;
            }
            if (parent_next[i]->right != NULL){
                 parent_current[loop] =parent_next[i]->right;
                 loop++;
            }
        }
        free(parent_next);
        parent_next=NULL;
        current_parent=next_parent;
        next_parent=0;
        loop=0;
    }
}

void input_bs_tree(BinTree *root,esu value){
    BinTree suc=NULL;
    boolean leaf=false;
    if(*root == NULL){
        *root= Alokasi(value);
    }else{
        suc = *root;
        //binary tree with sorting alias binary search tree
        while(leaf == false){
            /*memastikan agar value node tidak sama dengan node yang sudah ada*/
            if(value == InfoTree(suc))return;//nanti diganti dengan fungsi search agar time complexity berkurang dikarenakan apabila tidak memakai fungsi search dia akan mengcompare 2 kali dan apabila pakai fungsi search hanya sekali apabila value nya itu sama dengan info root
            
            /*untuk operasi mode kiri*/
            if(value < InfoTree(suc) ){
                if(IsUnerLeft(suc) == true){
                    suc=GetLeft(suc);
                }else{
                LeftTree(suc)=Alokasi(value);
                leaf =true;
                }
            }else{
                /*operasi node kanan*/
                if(IsUnerRight(suc) == true){
                    suc=GetRight(suc);
                }else{
                    RightTree(suc)=Alokasi(value);
                    leaf = true;
                }
            }
        }
    }
}

void input_bs_tree_rekursif(BinTree *root,esu value){
    if(*root == NULL){
        *root=Alokasi(value);/*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/
        return;
    }
    //tipe data
    BinTree seeker=*root;

    //kondisi apa bila sudah ada di leaf siap untuk di tancapkan dan mengalokasikan yang baru;
    if(LeftTree(seeker) == NULL && value < InfoTree(seeker) ){ LeftTree(seeker) = Alokasi(value); return;} /*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/
    if(RightTree(seeker) == NULL && value > InfoTree(seeker) ){ RightTree(seeker) = Alokasi(value); return;}/*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/ 

    //algoritma
    if(LeftTree(seeker) != NULL && value < InfoTree(seeker) ) { seeker=LeftTree(seeker); input_bs_tree_rekursif(&seeker,value);}/*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/
    if(RightTree(seeker) != NULL && value > InfoTree(seeker) ) {seeker=RightTree(seeker); input_bs_tree_rekursif(&seeker,value);}/*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/
}

//  void PrintTree(BinTree root){
//     if(root == NULL)return;

//     BinTree *parent_current=NULL;
//     BinTree *parent_next=NULL;
//     /*dikarenakan root nya ada maka parent count =1*/
//     int current_parent=1,next_parent=0;
//     int loop=0;

//     /*****************rootnya di proses ********************/
//     printf("%d\n",Info(root));
//     /*****************rootnya di proses ********************/
//     parent_current=(BinTree*)malloc(current_parent*sizeof(struct tElmtTree));
//     *parent_current=root;
//         while(current_parent > 0){
//         for(int i=0;i<current_parent;i++){
//             if (parent_current[i]->left != NULL){
//                 /*************son di proses ***************/
//                 printf("%d\n",(parent_current[i])->left->info);
                
//                 /*************son di proses ***************/
//                 next_parent++;
//             }
//             if (parent_current[i]->right != NULL){
//                 /*************son di proses ***************/
//                 printf("%d\n",(parent_current[i])->right->info);
                
//                 /*************son di proses ***************/
//                 next_parent++;
//             }
//         }
//         parent_next=(BinTree*)malloc(current_parent*sizeof(struct tElmtTree));
//         for(int i=0;i<current_parent;++i){
//             parent_next[i]=parent_current[i]; 
//         }
//         free(parent_current);
//         parent_current=NULL;

//         if(next_parent > 0)parent_current=(BinTree*)malloc (next_parent*sizeof(struct tElmtTree));
        
//         for(int i=0;i<next_parent;i++){
//             if (parent_next[i]->left != NULL){
//                 parent_current[loop] =parent_next[i]->left;
//                 loop++;
//             }
//             if (parent_next[i]->right != NULL){
//                  parent_current[loop] =parent_next[i]->right;
//                  loop++;
//             }
//         }
//         free(parent_next);
//         parent_next=NULL;
//         current_parent=next_parent;
//         next_parent=0;
//         loop=0;
//     }
// }

int nbDaun(BinTree P){
    if(P == NULL)return 0;
    int leaf=0;

    if(IsUnerLeft(P) == false && IsUnerRight(P) == false) ++leaf;

    if(IsUnerLeft(P) != false)leaf += nbDaun(LeftTree(P));
    if(IsUnerRight(P) != false)leaf += nbDaun(RightTree(P));

    return leaf;
}


/*lebih ke height engga sih*/
int Depth(BinTree P){
    if(P == NULL)return -1;

    int left_depth=0;
    int right_depth=0;

    if(IsUnerLeft(P) != false)left_depth = 1 + Depth(LeftTree(P));
    if(IsUnerRight(P) != false)right_depth = 1 + Depth(RightTree(P));

    if(left_depth >= right_depth)return left_depth; //  kita memakai (>=) dikarenakan apabila LeftTree dan right depth nya itu sama maka akan terjadi ub dikarenakan fungsi tidak tau ingin mengembalikan nilai apa 
    if(right_depth >left_depth)return right_depth;
    
}