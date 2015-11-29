#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<cstring>
#include<windows.h>

#define nil NULL
#define info(p) (p)->info
#define prev(p) (p)->prev
#define next(p) (p)->next
#define first(l) (l).first
#define last(l) (l).last
#define firstchild(p) (p)->firstchild

using namespace std;


//Child
struct infotype_child{
    string id,nama;
    int harga,terjual;
};
typedef struct elmchild*addressc;

struct elmchild{
    infotype_child info;
    addressc next,prev;
};
struct list_child{
    addressc first,last;
};


//Parent
struct infotype_parent{
    string id,nama,alamat,tanggal;
    int pajak;
};

typedef struct elmparent*addressp;

struct elmparent{
    infotype_parent info;
    addressp next,prev;
    list_child firstchild;
};
struct list_parent{
    addressp first,last;
};



//Basic Procedure and Function
//Parent
void createListParent(list_parent &);
addressp alokasiParent(infotype_parent );
void insertFirstParent(list_parent &, addressp );
void insertLastParent(list_parent &, addressp );
void insertAfterParent(list_parent &, addressp, addressp );
void deleteFirstParent(list_parent &, addressp &);
void deleteLastParent(list_parent &, addressp &);
void deleteAfterParent(list_parent &, addressp &, addressc &);

//Child
void createListChild(list_child &);
addressc alokasiChild(infotype_child );
void insertFirstChild(list_child &, addressc );
void insertLastChild(list_child &, addressc );
void insertAfterChild(list_child &, addressc, addressc );
void deleteFirstChild(list_child &, addressc &);
void deleteLastChild(list_child &, addressc &);
void deleteAfterChild(list_child &, addressc , addressc );

//Fungsionalitas
void inputMenu (infotype_child &);
void printIdRumahMakan (list_parent );
void printinfo(list_parent );
void lihatMenuRumahMakan(list_parent );
addressp CariRumahMakan (list_parent , infotype_parent );
void TambahRumahMakan (infotype_parent &);
void editRumahMakan (list_parent &, addressp );
void TambahMenuSuatuRumahMakan (list_parent &, infotype_child );
addressc cariMenu (list_parent , infotype_child );
addressc cariMenu2(list_parent , addressp , infotype_child );
void hapusRumahMakan(list_parent &);
void hapusMenuRumahMakan(list_parent &);
void insertbyid (list_parent &, addressp );
void sortRumahMakanById (list_parent &);
addressc menuFavorit (list_parent , addressp );
int profitRumahMakan (list_parent , addressp );
int MenuTerbanyak (list_parent , addressp &);



void gotoxy(int x, int y);
#endif // LIST_H_INCLUDED
