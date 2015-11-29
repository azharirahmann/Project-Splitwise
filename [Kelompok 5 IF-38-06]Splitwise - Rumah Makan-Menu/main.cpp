#include "list.h"

int main()
{
    list_parent L1;
    list_child L2;
    addressp p,r,s;
    addressc q;
    infotype_parent x1,cari1;
    infotype_child x2, cari2;
    createListChild(L2);
    createListParent(L1);
    int pil,pol;
    char lagi='Y';

    while (lagi=='Y'){
        system("cls");
        cout << endl;
        cout << " ========================================================= \n";
        cout << " *          RESTAURANT MANAGEMENT APPLICATION            * \n"
             << " ========================================================= \n"
             << " *         1. Tambah Rumah Makan                         * \n"
             << " *         2. Edit Rumah Makan                           * \n"
             << " *         3. Cari Rumah Makan Berdasarkan Id            * \n"
             << " *         4. Cari Menu Berdasarkan Id                   * \n"
             << " *         5. Tambah Menu Suatu Rumah Makan              * \n"
             << " *         6. Hapus Menu Suatu Rumah Makan               * \n"
             << " *         7. Hapus Rumah Makan Beserta Menu             * \n"
             << " *         8. Lihat List Menu Suatu Rumah Makan          * \n"
             << " *         9. Lihat List Rumah Makan                     * \n"
             << " *        10. Sort Rumah Makan by Id                     * \n"
             << " *        11. Menu Favorit Suatu Rumah Makan             * \n"
             << " *        12. Keuntungan Suatu Rumah Makan               * \n"
             << " *        13. Menu Terbanyak                             * \n"
             << " *        14. Keluar                                     * \n"
             << " ========================================================= \n \n"
             << " ========================================================= \n"
             << " *         Masukkan Pilihan Anda :                       * \n";
        cout << " ========================================================= \n";
        gotoxy(35,21); cin >> pil;
        cin.ignore();

        if (pil >1 || pil <10){
            pol=pil;
        }
        else{
            lagi='Y';
        }

        switch (pol){
            case 1:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*             TAMBAH RUMAH MAKAN                   * \n"
                     << "==================================================== \n";
                cout << endl;
                TambahRumahMakan(x1);
                p=alokasiParent(x1);
                r=first(L1);

                s=CariRumahMakan(L1,x1);
                if(s==nil){
                    insertLastParent(L1,p);
                    cout << endl;
                    cout << "   INSERT DATA SUKSES ! \n ";
                }
                else{
                    cout << "   ID RUMAH MAKAN SAMA ! \n";
                }

                getch();
                break;


            case 2:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*                EDIT RUMAH MAKAN                  * \n"
                     << "==================================================== \n";
                cout << endl;

                cout << "    List Id Rumah Makan : "; printIdRumahMakan(L1);
                cout << endl;
                cout << "    Masukkan Id Rumah Makan : ";
                getline(cin,cari1.id);
                p=CariRumahMakan(L1,cari1);

                if (p==nil){
                    cout << endl;
                    cout << "    ID RUMAH MAKAN TIDAK DITEMUKAN ";
                }
                else{
                    cout << endl;
                    editRumahMakan(L1,p);
                }
                getch();
                break;

            case 3:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*        CARI RUMAH MAKAN BERDASARKAN ID           * \n"
                     << "==================================================== \n";
                cout << endl;
                cout << "    Masukkan ID :  ";
                getline(cin,cari1.id);

                p=CariRumahMakan(L1,cari1);
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
                }
                getch();
                break;


            case 4:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*             CARI MENU BERDASARKAN ID             * \n"
                     << "==================================================== \n";
                cout << endl;

                cout << "    List Id Rumah Makan : "; printIdRumahMakan(L1);
                cout << endl;

                cout << "    Masukkan Id Rumah Makan : ";
                getline(cin,x1.id);
                cout << "    Masukkan Id Menu        : ";
                getline(cin,x2.id);

                p=CariRumahMakan(L1,x1);
                q=cariMenu2(L1,p,x2);

                cout << endl << endl;
                if (p==nil){
                    cout << "    RUMAH MAKAN TIDAK DITEMUKAN \n";
                }
                else{
                    if(q!=nil){
                        cout << "    MENU DITEMUKAN \n \n";

                        cout << "    ID Menu   : " << info(q).id << endl;
                        cout << "    Nama Menu : " << info(q).nama << endl;
                        cout << "    Harga     : " << info(q).harga << endl;
                    }
                    else{
                        cout << endl;
                        cout << "    MENU TIDAK DITEMUKAN \n \n";
                    }
                }
                getch();
                break;


            case 5:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*         TAMBAH MENU SUATU RUMAH MAKAN            * \n"
                     << "==================================================== \n";
                cout << endl;

                cout << "    List Id Rumah Makan : "; printIdRumahMakan(L1);
                cout << endl;
                TambahMenuSuatuRumahMakan(L1,x2);
                getch();
                break;

            case 6:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*          HAPUS MENU SUATU RUMAH MAKAN            * \n"
                     << "==================================================== \n";
                cout << endl;

                cout << "    List Id Rumah Makan : "; printIdRumahMakan(L1);
                cout << endl;
                hapusMenuRumahMakan(L1);
                getch();
                break;

            case 7:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*         HAPUS RUMAH MAKAN BESERTA MENU           * \n"
                     << "==================================================== \n";
                cout << endl;

                cout << "    List Id Rumah Makan : "; printIdRumahMakan(L1);
                cout << endl;
                hapusRumahMakan(L1);
                getch();
                break;

            case 8:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*        LIHAT LIST MENU SUATU RUMAH MAKAN         * \n"
                     << "==================================================== \n";
                cout << endl;

                cout << "    List Id Rumah Makan : "; printIdRumahMakan(L1);
                cout << endl;
                lihatMenuRumahMakan(L1);
                getch();
                break;


            case 9:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*               LIHAT LIST RUMAH MAKAN             * \n"
                     << "==================================================== \n";
                cout << endl;

                printinfo(L1);
                getch();
                break;

            case 10:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*              SORT RUMAH MAKAN BY ID              * \n"
                     << "==================================================== \n";
                cout << endl;

                if (first(L1)==nil){
                    cout << endl;
                    cout << "    LIST MASIH KOSONG \n";
                }
                else{
                    char Sort;
                    Sort='W';

                    while (Sort!='Y' && Sort !='N'){
                        cout << "    Sort Rumah Makan By Id ? Y/N : ";
                        cin >> Sort;
                    }

                    if (Sort=='Y'){
                        sortRumahMakanById(L1);
                        cout << "    SORT RUMAH MAKAN BERHASIL ! \n";
                        cout << endl;
                        printinfo(L1);
                    }
                }

                getch();
                break;

            case 11:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*         MENU FAVORIT SUATU RUMAH MAKAN           * \n"
                     << "==================================================== \n";
                cout << endl;

                cout << "    List Id Rumah Makan : "; printIdRumahMakan(L1);
                cout << endl;

                cout << "    Masukkan Id Rumah Makan : ";
                getline(cin,cari1.id);

                p=CariRumahMakan(L1,cari1);
                cout << endl;
                if (p==nil){
                    cout << "    RUMAH MAKAN TIDAK ADA \n";
                }
                else{
                    cout << "    RUMAH MAKAN DITEMUKAN ! \n \n";

                    q=menuFavorit(L1,p);
                    if (q==nil){
                        cout << "   MENU KOSONG \n";
                    }
                    else{
                        cout << "    Menu Favorit : " << info(q).nama <<endl;
                        cout << "    Terjual      : " << info(q).terjual << endl << endl;
                    }
                }
                getch();
                break;

            case 12:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*          KEUNTUNGAN SUATU RUMAH MAKAN            * \n"
                     << "==================================================== \n";
                cout << endl;

                cout << "    List Id Rumah Makan : "; printIdRumahMakan(L1);
                cout << endl;

                cout << "    Masukkan Id Rumah Makan : ";
                getline(cin,cari1.id);

                p=CariRumahMakan(L1,cari1);

                cout << endl;
                if (p==nil){
                    cout << "    RUMAH MAKAN TIDAK ADA \n";
                }
                else{
                    int x;
                    x=profitRumahMakan(L1,p);
                    cout << "    Keuntungan Rumah Makan " << info(p).nama << " adalah " << x;
                }

                getch();
                break;

            case 13:
                system("cls");
                cout << endl;
                cout << "==================================================== \n"
                     << "*                  MENU TERBANYAK                  * \n"
                     << "==================================================== \n";
                cout << endl;

                if (first(L1)==nil){
                    cout << "    RUMAH MAKAN TIDAK ADA \n";
                }
                else{
                    p=first(L1);
                    int x=MenuTerbanyak(L1,p);
                    if (x==0){
                        cout << "    MENU TIDAK ADA \n";
                    }
                    else{
                        cout << "    Rumah Makan " << info(p).nama << " Memiliki Menu " << endl;
                        cout << "    Terbanyak, yaitu " << x << " Buah Menu";
                    }
                }

                getch();
                break;

            case 14:
                lagi='N';
                break;

            default:
                lagi='Y';

        }
    }

    getch();
    return 0;
}
