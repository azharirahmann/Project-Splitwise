#include "list.h"

//Basic Procedure and Function
//Child
void createListChild(list_child &L){
    first(L)=nil;
    last(L)=nil;
}

addressc alokasiChild(infotype_child x){
    addressc p;
    p=new elmchild;
    info(p)=x;
    next(p)=nil;
    prev(p)=nil;
    return p;
}

void insertFirstChild(list_child &L, addressc P){
    if (first(L)==nil){
        first(L)=P;
        last(L)=P;
    }
    else{
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertLastChild(list_child &L, addressc P){
    if(first(L) == nil){
        insertFirstChild(L,P);
    }
    else{
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }
}

void insertAfterChild(list_child &L, addressc P, addressc Prec){
    if(last(L)==Prec){
        insertLastChild(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P)=Prec;
        prev(next(Prec)) = P;
        next(Prec)=P;
    }
}

void deleteFirstChild(list_child &L, addressc &P){
    if (first(L)==(last(L))){
        P=first(L);
        first(L)=nil;
        last(L)=nil;
    }
    else{
        P = first(L);
        first(L) = next(P);
        next(P) = nil;
        prev(P) = nil;
    }
}

void deleteLastChild(list_child &L, addressc &P){
        P=last(L);
        last(L)=prev(last(L));
        next(last(L))=nil;
        prev(P)=nil;
        next(P)=nil;

}

void deleteAfterChild(list_child &L, addressc P, addressc Prec){

    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P)=nil;
    next(P)=nil;
}



//Parent
void createListParent(list_parent &L){
    first(L)=nil;
    last(L)=nil;
}

addressp alokasiParent(infotype_parent x){
    addressp p;
    p=new elmparent;
    info(p)=x;
    next(p)=nil;
    prev(p)=nil;
    first(firstchild(p))=nil;
    last(firstchild(p))=nil;
    return p;
}

void insertFirstParent(list_parent &L, addressp P){
    if (first(L)==nil){
        first(L)=P;
        last(L)=P;
    }
    else{
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertLastParent(list_parent &L, addressp P){
    if(first(L) == nil){
        insertFirstParent(L,P);
    }
    else{
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }
}

void insertAfterParent(list_parent &L, addressp P, addressp Prec){
    if(last(L)==Prec){
        insertLastParent(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P)=Prec;
        prev(next(Prec)) = P;
        next(Prec)=P;
    }
}

void deleteFirstParent(list_parent &L, addressp &P){
    if (first(L)==(last(L))){
        P=first(L);
        first(L)=nil;
        last(L)=nil;
    }
    else{
        P = first(L);
        first(L) = next(P);
        prev(first(L))=nil;
        next(P) = nil;
        prev(P) = nil;
    }
}

void deleteLastParent(list_parent &L, addressp &P){
    if(first(L) == last(L)){
        P=last(L);
        first(L)=nil;
        last(L)=nil;
    }
    else{
        P=last(L);
        last(L)=prev(last(L));
        next(last(L))=nil;
        prev(P)=NULL;
        next(P)=NULL;
    }
}

void deleteAfterParent(list_parent &L, addressp &P, addressp &Prec){
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P)=NULL;
    next(P)=NULL;
}

//Fungsionalitas

void TambahRumahMakan (infotype_parent &x){
    string dd,mm,yyyy;

    cout << "   ID Rumah Makan     : ";
    getline(cin,x.id);
    cout << "   Nama Rumah Makan   : ";
    getline(cin,x.nama);
    cout << "   Alamat Rumah Makan : ";
    getline(cin,x.alamat);
    cout << "   Tanggal Pembuatan  : ";
    cin >> dd; cin.ignore();
    cout << "   Bulan              : ";
    cin >> mm; cin.ignore();
    cout << "   Tahun              : ";
    cin >> yyyy; cin.ignore();
    x.tanggal= dd + "-" + mm + "-" + yyyy;
    cout << "   Pajak Rumah Makan  : ";
    cin >> x.pajak;
    cin.ignore();
}

addressp CariRumahMakan (list_parent L, infotype_parent x){
    addressp p=first(L);
    if (p==nil){
        return nil;
    }
    else{
        while (p!=nil){
            if (info(p).id==x.id){
                return p;
            }
            p=next(p);
        }
    }
    return nil;
}

void editRumahMakan (list_parent &L, addressp p){
    infotype_parent x;
    addressp q;

    TambahRumahMakan(x);
    q=CariRumahMakan(L,x);

    if (q==nil){
        info(p)=x;
        cout << endl;
        cout << "    EDIT RUMAH MAKAN SUKSES ! \n";
    }
    else if (info(q).id!=x.id || info(p).id==x.id){
        info(p)=x;
        cout << endl;
        cout << "    EDIT RUMAH MAKAN SUKSES ! \n";
    }
    else if (q!=nil){
        cout << "    ID SAMA ! \n";
    }
}

void inputMenu (infotype_child &x){
    cout << "    Id Menu    : ";
    getline(cin,x.id);
    cout << "    Nama Menu  : ";
    getline(cin,x.nama);
    cout << "    Harga Menu : ";
    cin >> x.harga;
    cin.ignore();
    cout << "    Terjual    : ";
    cin >> x.terjual;
    cin.ignore();
}

void TambahMenuSuatuRumahMakan (list_parent &L, infotype_child x){
    infotype_parent cari;
    addressp p;
    addressc q,r;
    cout << "    Masukkan ID Rumah Makan : ";
    getline(cin,cari.id);

    p=CariRumahMakan(L,cari);

    if (p==nil){
        cout << "    Rumah Makan Tidak Tersedia \n";
    }
    else{
        cout << "    Rumah Makan Tersedia \n \n";
        inputMenu(x);

        r=cariMenu2(L,p,x);

        if (r!=nil){
            cout << endl;
            cout << "    ID MENU SAMA ! \n";
        }
        else{
            q=alokasiChild(x);
            insertLastChild(firstchild(p),q);
            cout << endl;
            cout << "    INSERT MENU SUKSES ! \n";
        }
    }
}

addressc cariMenu (list_parent L, infotype_child x){
    addressp p=first(L);
    addressc q;
    if (p!=nil){
        while (p!=nil){
            q=first(firstchild(p));
            while (q!=nil){
                if (info(q).id==x.id){
                    return q;
                }
                q=next(q);
            }
            p=next(p);
        }
    }
    return nil;
}

addressc cariMenu2(list_parent L, addressp p, infotype_child x){
    addressc q;
    if (p!=nil){

        q=first(firstchild(p));
        while (q!=nil){
            if (info(q).id==x.id){
                return q;
            }
            q=next(q);
        }
    }
    return nil;
}

void printinfo(list_parent L){
    if (first(L)==nil){
        cout << "    KOSONG";
    }
    else{
        addressp p=first(L);
        while (p!=nil){
            cout << "    ID Rumah Makan     : " << info(p).id << endl;
            cout << "    Nama Rumah Makan   : " << info(p).nama << endl;
            cout << "    Alamat Rumah Makan : " << info(p).alamat << endl;
            cout << "    Tanggal Pembuatan  : " << info(p).tanggal << endl;
            cout << "    Pajak Rumah Makan  : " << info(p).pajak << endl << endl << endl;
            p=next(p);
        }
    }
}

void lihatMenuRumahMakan(list_parent L){
    infotype_parent cari1;
    addressp p;
    addressc q;

    cout << "    Masukkan ID :  ";
    getline(cin,cari1.id);

    p=CariRumahMakan(L,cari1);
    if (p==nil){
        cout << endl << endl;
        cout << "    ID RUMAH MAKAN TIDAK DITEMUKAN \n";
    }
    else{
        cout << endl;
        cout << "    RUMAH MAKAN DITEMUKAN \n \n";

        cout << "    ID Rumah Makan     : " << info(p).id << endl;
        cout << "    Nama Rumah Makan   : " << info(p).nama << endl;
        cout << "    Alamat Rumah Makan : " << info(p).alamat << endl;
        cout << "    Tanggal Pembuatan  : " << info(p).tanggal << endl;
        cout << "    Pajak Rumah Makan  : " << info(p).pajak << endl << endl << endl;

        q=first(firstchild(p));

        cout << "    DAFTAR MENU \n";

        if (q==nil){
            cout << "    KOSONG \n";
        }
        else{
            while (q!=nil){
                cout << "    ID Menu            : " << info(q).id << endl;
                cout << "    Nama Menu          : " << info(q).nama << endl;
                cout << "    Harga              : " << info(q).harga << endl;
                cout << "    Terjual            : " << info(q).terjual << endl << endl;
                q=next(q);
            }
        }
    }
}

void hapusRumahMakan(list_parent &L){
    infotype_parent x;
    cout << "    Masukkan Id Rumah Makan : ";
    getline(cin,x.id);

    addressp n1=CariRumahMakan(L,x);
    if (n1!=nil){
        addressp p=first(L);

        if(info(p).id==x.id){
            deleteFirstParent(L,p);
        }
        else if (info(last(L)).id==x.id){
            deleteLastParent(L,p);
        }
        else{
            while(p!=nil){
                if (info(next(p)).id==x.id){
                    break;
                }
                p=next(p);
            }
            addressp q=next(p);

            deleteAfterParent(L,q,p);
        }
        cout << "    DELETE RUMAH MAKAN SUKSES ! \n";
    }
    else{
        cout << "    RUMAH MAKAN TIDAK DITEMUKAN ! " << endl;
    }
}

void hapusMenuRumahMakan(list_parent &L){
    infotype_parent x1;
    infotype_child x2;

    cout << "    Masukkan Id Rumah Makan : ";
    getline(cin,x1.id);

    addressp p=CariRumahMakan(L,x1);

    if (p==nil){
        cout << endl;
        cout << "    RUMAH MAKAN TIDAK DITEMUKAN \n";
    }
    else{
        cout << endl;
        cout << "    Rumah Makan Ditemukan \n \n";
        cout << "    Masukkan id menu : ";
        getline(cin,x2.id);
        cin.ignore();

        addressc r=cariMenu(L,x2);

        if (r==nil){
            cout << endl;
            cout << "    MENU TIDAK DITEMUKAN \n";
        }
        else{

            addressc q=first(firstchild(p));
            if (info(q).id==x2.id){
                deleteFirstChild(firstchild(p),q);
            }
            else if(info(last(firstchild(p))).id==x2.id){
                deleteLastChild(firstchild(p),last(firstchild(p)));
            }
            else{
                addressc r;
                while (p!=nil){
                    r=first(firstchild(p));
                    while(q!=nil){
                        if (info(next(r)).id==x2.id){
                            deleteAfterChild(firstchild(p),next(r),r);
                            break;
                        }
                        r=next(r);
                    }
                    p=next(p);
                }
            }
            cout << "    HAPUS MENU SUKSES ! \n \n";
        }
    }
}

void insertbyid (list_parent &L, addressp p){
    addressp q;
    q=first(L);

    if (q==nil){
        insertFirstParent(L,p);
    }
    else if (info(p).id < info(q).id){
        insertFirstParent(L,p);
    }
    else{
        while (info(p).id>info(q).id && next(q)!=nil){
            if (info(next(q)).id > info(p).id){
                break;
            }
            q=next(q);
        }
        insertAfterParent(L,p,q);
    }
}

void sortRumahMakanById (list_parent &L){
    addressp p;
    list_parent L2;
    createListParent(L2);
    p=first(L);

    while (first(L)!=nil){
        deleteFirstParent(L,p);
        insertbyid(L2,p);
    }
    while (first(L2)!=nil){
        deleteFirstParent(L2,p);
        insertLastParent(L,p);
    }
}

addressc menuFavorit (list_parent L, addressp p){
    addressc q=first(firstchild(p));
    addressc Max;
    Max=q;

    while (q!=nil){
        if (info(q).terjual>info(Max).terjual){
            Max=q;
        }
        q=next(q);
    }
    return Max;
}

int profitRumahMakan (list_parent L, addressp p){
    addressc q=first(firstchild(p));
    int total=0;

    while (q!=nil){
        total=total + ((info(q).harga)*(info(q).terjual));
        q=next(q);
    }
    return total;
}

void printIdRumahMakan (list_parent L){
    addressp p=first(L);

    if (p==nil){
        cout << " Kosong";
    }
    else{
        while (p!=nil){
            cout << info(p).id;
            if (next(p)!=nil){
                cout << ", ";
            }
            p=next(p);
        }
    }
}

int MenuTerbanyak (list_parent L, addressp &p){
    int Max=0;
    int x;
    addressp r=first(L);
    addressc q;

    while (r!=nil){
        q=first(firstchild(p));
        x=0;
        while (q!=nil){
            x++;
            q=next(q);
        }
        if ( x > Max ){
            Max = x;
            p=r;
        }
        r=next(r);
    }
    return Max;
}




void gotoxy(int x, int y){
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
