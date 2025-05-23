#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

/*selektor*/
infotype Getakar(BinTree P){
    return Info(P);
}
BinTree GetLeft(BinTree P){
    if(IsUnerLeft(P) !=false )return Left(P);
    return NULL;
}

BinTree GetRight(BinTree P){
    if(IsUnerRight(P) !=false)return Right(P);
    return NULL;
}
/*selektor*/

/*konstsruktor*/
address Alokasi(infotype X){
    address T=(address)malloc(sizeof(Node));
    if(T != NULL){
        Info(T)=X;//bagian yang harus diubah apabila infotype dirubah
        Left(T)=NULL;
        Right(T)=NULL;
        return T;
    }else return NULL;
}

//mengembalikan root yang left dan right nya bisa costumisasi
BinTree Tree(infotype Akar, BinTree L, BinTree R){
    BinTree P=Alokasi(Akar);
    if(P != NULL){
        Left(P)=L;
        Right(P)=R;
        return P;
    }else return NULL;
}
//omak 
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P){
    *P=Tree(Akar,L,R);
}

//nilai di input oleh user 
void BuildTree(BinTree *P){
    
}
/*konstsruktor*/

/*predikat penting*/
boolean IsUnerLeft(BinTree P){
    if(Left(P) != NULL) return true;
    return false;
}

boolean IsUnerRight(BinTree P){
    if(Right(P) != NULL) return true;
    return false;
}

boolean IsBiner(BinTree P){
    if(IsUnerLeft(P) == true  && IsUnerRight(P) == true) return true;
    return false;
}

boolean IsEmpty(BinTree P){
    if(IsUnerLeft(P) != true  && IsUnerRight(P) != true) return true;
    return false;
}


void PreOrder(BinTree P){
    /*alur algoritmanya*/
    //1.dia akan menelursui left son sampe habis dan sambil diproses
    // 2.kalo sudah engga ada left son dia akan ke right son 
    // 3.dia akan check left son ada engga
    // 4.dan rekursif selesai saat berada di root tapi root nya engga di proses lagi
    if(P == NULL)return;
    
    printf("%d\n",Info(P));//info(P);
    PreOrder(Left(P));
    PreOrder(Right(P));
}

void PostOrder(BinTree P){
    /*alur algoritmanya*/
    // 1.left son 
    // 2.right son 
    // 3.parent
    // 4.apabila saat mengunjungi parent masih memililki anak maka lakkukan step 1-4
    if(P == NULL)return;
    PostOrder(Left(P));
    PostOrder(Right(P));
    printf("%d\n",Info(P));//info(P)
}

void InOrder(BinTree P){
     /*alur algoritmanya*/
    // 1.left son 
    // 2.parent
    // 3.right son 
    // 4.apabila saat mengunjungi parent masih memililki anak maka lakkukan step 1-4
    if(P == NULL)return;

    if(IsUnerLeft(P) != false)InOrder(Left(P));
    printf("%d\n",Info(P));//melakukan aksi bebas aksi nya mau tambah print dan lain lain
    if(IsUnerRight(P) != false)InOrder(Right(P));
}
/*predikat penting*/


boolean Search(BinTree P,infotype X){
    if(P == NULL)return false;
    boolean status=false;

    if(X == Info(P))status=true;

    if(IsUnerLeft(P) !=false && status == false) status=Search(Left(P),X);
    if(IsUnerRight(P) != false && status == false)status=Search(Right(P),X);
    return status; 
}

int nbElmt(BinTree P){//masih belum di optimasi
    //memakai pre order
    if(P == NULL)return 0;
    int i=1;
    if(IsUnerLeft(P) != false) i=i+nbElmt(Left(P));
    if(IsUnerRight(P) != false)i=i+nbElmt(Right(P));
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
    printf("%d\n",Info(root));
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

void input_bs_tree(BinTree *root,infotype value){
    BinTree suc=NULL;
    boolean leaf=false;
    if(*root == NULL){
        *root= Alokasi(value);
    }else{
        suc = *root;
        //binary tree with sorting alias binary search tree
        while(leaf == false){
            /*memastikan agar value node tidak sama dengan node yang sudah ada*/
            if(value == Info(suc))return;//nanti diganti dengan fungsi search agar time complexity berkurang dikarenakan apabila tidak memakai fungsi search dia akan mengcompare 2 kali dan apabila pakai fungsi search hanya sekali apabila value nya itu sama dengan info root
            
            /*untuk operasi mode kiri*/
            if(value < Info(suc) ){
                if(IsUnerLeft(suc) == true){
                    suc=GetLeft(suc);
                }else{
                Left(suc)=Alokasi(value);
                leaf =true;
                }
            }else{
                /*operasi node kanan*/
                if(IsUnerRight(suc) == true){
                    suc=GetRight(suc);
                }else{
                    Right(suc)=Alokasi(value);
                    leaf = true;
                }
            }
        }
    }
}

void input_bs_tree_rekursif(BinTree *root,infotype value){
    if(*root == NULL){
        *root=Alokasi(value);/*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/
        return;
    }
    //tipe data
    BinTree seeker=*root;

    //kondisi apa bila sudah ada di leaf siap untuk di tancapkan dan mengalokasikan yang baru;
    if(Left(seeker) == NULL && value < Info(seeker) ){ Left(seeker) = Alokasi(value); return;} /*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/
    if(Right(seeker) == NULL && value > Info(seeker) ){ Right(seeker) = Alokasi(value); return;}/*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/ 

    //algoritma
    if(Left(seeker) != NULL && value < Info(seeker) ) { seeker=Left(seeker); input_bs_tree_rekursif(&seeker,value);}/*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/
    if(Right(seeker) != NULL && value > Info(seeker) ) {seeker=Right(seeker); input_bs_tree_rekursif(&seeker,value);}/*alokasinya bisa dibenerin sesuai kebutuhannanti input parameternya apa*/
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

    if(IsUnerLeft(P) != false)leaf += nbDaun(Left(P));
    if(IsUnerRight(P) != false)leaf += nbDaun(Right(P));

    return leaf;
}


/*lebih ke height engga sih*/
int Depth(BinTree P){
    if(P == NULL)return -1;

    int left_depth=0;
    int right_depth=0;

    if(IsUnerLeft(P) != false)left_depth = 1 + Depth(Left(P));
    if(IsUnerRight(P) != false)right_depth = 1 + Depth(Right(P));

    if(left_depth >= right_depth)return left_depth; //  kita memakai (>=) dikarenakan apabila left dan right depth nya itu sama maka akan terjadi ub dikarenakan fungsi tidak tau ingin mengembalikan nilai apa 
    if(right_depth >left_depth)return right_depth;
    
}