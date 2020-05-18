#include "controller.h"
void dummy_data(list_film &f, list_sutradara &s)
{
    insertElm(f, "Nanti kita cerita tentang hari ini");
    insertElm(f, "One day");
    insertElm(f, "Bandung renjana");
    insertElm(f, "Avengers: infinity war");
    //printInfo(f);
    insertElm(s, "Angga Dwimas Sasongko");
    insertElm(s, "Banjong Pisanthanakun");
    insertElm(s, "Sukmana Sudinar");
    insertElm(s, "Joe Russo");
    insertElm(s, "Anthony Russo");
    //printInfo(s);
    adr_film p;
    adr_sutradara q;
    p = findElm(f,"Nanti kita cerita tentang hari ini");
    q = findElm(s,"Angga Dwimas Sasongko");
    insertElm(p->relasi,q);
    p = findElm(f,"One day");
    q = findElm(s,"Banjong Pisanthanakun");
    insertElm(p->relasi,q);
    p = findElm(f,"Bandung renjana");
    q = findElm(s,"Sukmana Sudinar");
    insertElm(p->relasi,q);
    p = findElm(f,"Avengers: infinity war");
    q = findElm(s,"Joe Russo");
    insertElm(p->relasi,q);
    p = findElm(f,"Avengers: infinity war");
    q = findElm(s,"Anthony Russo");
    insertElm(p->relasi,q);
    p = findElm(f,"Bandung renjana");
    q = findElm(s,"Joe Russo");
    insertElm(p->relasi,q);
    p = findElm(f,"One day");
    q = findElm(s,"Joe Russo");
    insertElm(p->relasi,q);
}
void main_controller()
{
    list_film f;
    list_sutradara s;

    int pilihMenu;
    createList(f);
    createList(s);
    string dummy;
    inputStr("Ingin menambahkan dummy data ?(y/n)",dummy);
    while(dummy != "y" && dummy != "n")
    {
        cout << "silahkan ketik y untuk menambah dan n untuk tidak menambahkan!" <<endl;
        inputStr("Ingin menambahkan dummy data ?",dummy);
    }
    if(dummy == "y")
    {
        dummy_data(f,s);
    }
    while(true)
    {
        system("CLS");
        banner("MENU");
        cout << "1. Tambah sutradara (A)" << endl;
        cout << "2. Tambah film (B)" << endl;
        cout << "3. Tambah sutradara pada film (C)" << endl;
        cout << "4. Menghapus sutradara (D)" << endl;
        cout << "5. Menghapus film (E)" << endl;
        cout << "6. Tampil Sutradara tersibuk (F)" << endl;
        cout << "7. Tampil film dengan sutradara tertentu (G)" << endl;
        cout << "8. Tampil film yang terdiri dari 2 sutradara (H)" << endl;
        cout << "9. Tampil asisten sutradara tersantai (I)" << endl;
        cout << "10. Ganti nama sutradara (BONUS 1)" << endl;
        cout << "11. Ganti judul film (BONUS 2)" << endl;
        cout << "12. Tampil semua data (BONUS 3)" << endl;
        cout << "13. Tampil film dengan sutradara terbanyak (BONUS 4)" << endl;
        cout << "14. Info Kelompok" << endl;
        cout << "15. Keluar" << endl;
        inputInt("Pilih menu", pilihMenu);
        while(pilihMenu < 1 || pilihMenu > 15)
        {
            cout << "Silahkan pilih menu yang tersedia." << endl;
            inputInt("Pilih menu", pilihMenu);
        }
        system("CLS");
        switch(pilihMenu)
        {
        case 1:
            banner("TAMBAH SUTRADARA BARU");
            addSutradara(s);
            pause();
            break;
        case 2:
            banner("TAMBAH FILM BARU");
            addFilm(f);
            pause();
            break;
        case 3:
            banner("TAMBAH SUTRADARA PADA FILM");
            addRelasi(f,s);
            pause();
            break;
        case 4:
            banner("HAPUS SUTRADARA");
            delSutradara(f,s);
            pause();
            break;
        case 5:
            banner("HAPUS FILM");
            delFilm(f);
            pause();
            break;
        case 6:
            banner("TAMPILKAN SUTRADARA TERSIBUK");
            showSutradaraTersibuk(f,s);
            pause();
            break;
        case 7:
            banner("CARI FILM BERDASARKAN SUTRADARA");
            findFilmBySutradara(f,s);
            pause();
            break;
        case 8:
            banner("TAMPILKAN FILM DENGAN DUA SUTRADARA");
            showFilmDuaSutradara(f);
            pause();
            break;
        case 9:
            banner("TAMPILKAN ASISTEN SUTRADARA TERSANTAI");
            showSutradaraTersantai(f,s);
            pause();
            break;
        case 10:
            banner("GANTI NAMA SUTRADARA");
            changeSutradaraName(s);
            pause();
            break;
        case 11:
            banner("GANTI JUDUL FILM");
            changeFilmTitle(f);
            pause();
            break;
        case 12:
            banner("TAMPILKAN SEMUA DATA YANG ADA");
            showData(f,s);
            pause();
            break;
        case 13:
            banner("TAMPILKAN FILM DENGAN SUTRADARA TERBANYAK");
            showFilmBanyakSutradara(f);
            pause();
            break;
        case 14:
            banner("INFO KELOMPOK");
            cout << "Disusun oleh : " << endl;
            cout << "1. Michael Putera Wardana (1301194056)" << endl;
            cout << "2. Yogi Firgiawan (1301194228)" << endl;
            pause();
            break;
        case 15:
            banner("EXIT PROGRAM");
            pause();
            exit(0);
        }
    }
}
void pause()
{
    system("pause");
}
void addSutradara(list_sutradara &s)
{
    infotype_sutradara x;
    inputStr("Nama sutradara",x);
    while(findElm(s,x) != NULL)
    {
        cout << "Sutradara " << x << " sudah pernah ditambahkan." << endl;
        inputStr("Nama sutradara",x);
    }
    insertElm(s,x);
    cout << "Sutradara " << x << " berhasil ditambahkan." << endl;
    printInfo(s);
}
void addFilm(list_film &f)
{
    infotype_sutradara x;
    inputStr("Judul film",x);
    while(findElm(f,x) != NULL)
    {
        cout << "Film " << x << " sudah pernah ditambahkan." << endl;
        inputStr("Judul film",x);
    }
    insertElm(f,x);
    cout << "Film " << x << " berhasil ditambahkan." << endl;
    printInfo(f);
}
void addRelasi(list_film &f, list_sutradara s)
{
    if(f.first != NULL && s.first != NULL)
    {
        string x;
        adr_film p;
        adr_sutradara q;
        inputStr("Judul film",x);
        p = findElm(f,x);
        while(p == NULL)
        {
            cout << "Film " << x << " tidak ditemukan." << endl;
            printInfo(f);
            inputStr("Judul film",x);
            p = findElm(f,x);
        }
        inputStr("Nama sutradara",x);
        q = findElm(s,x);
        while(q == NULL)
        {
            cout << "Sutradara " << x << " tidak ditemukan." << endl;
            printInfo(s);
            inputStr("Nama sutradara",x);
            q = findElm(s,x);
        }
        insertElm(p->relasi,q);
        cout << "Film " << p->info << endl;
        printInfo(p->relasi);
    }else{
        cout << "Daftar sutradara atau film tidak ada" << endl;
    }
}
void delSutradara(list_film &f, list_sutradara &s)
{
    if(s.first != NULL)
    {
        infotype_sutradara x;
        inputStr("Nama sutradara",x);
        adr_sutradara q = findElm(s,x);
        while(q == NULL)
        {
            cout << "Sutradara " << x << " tidak ditemukan." << endl;
            printInfo(s);
            inputStr("Nama sutradara",x);
            q = findElm(s,x);
        }
        adr_film p = f.first;
        adr_relasi r;
        while(p != NULL)
        {
            r = findElm(p->relasi,q);
            if(r != NULL)
            {
                deleteElm(p->relasi,r);
                cout << x << " tidak lagi menjadi sutradara dalam film " << p->info << endl;
            }
            p = p->next;
        }
        deleteElm(s,q);
        cout << "Sutradara " <<  x << " berhasil dihapus" << endl;
    }
    else
    {
        cout << "Daftar sutradara tidak ada" << endl;
    }
}
void delFilm(list_film &f)
{
    if(f.first != NULL)
    {
        infotype_film x;
        adr_film p;
        inputStr("Judul film",x);
        p = findElm(f,x);
        while(p == NULL)
        {
            cout << "Film " << x << " tidak ditemukan." << endl;
            printInfo(f);
            inputStr("Judul film",x);
            p = findElm(f,x);
        }
        if(p->relasi.first != NULL)
        {
            while(p->relasi.first != NULL)
            {
                deleteElm(p->relasi,p->relasi.first);
            }
        }
        deleteElm(f,p);
        cout << "Film " << x << " berhasil dihapus." << endl;
    }
    else
    {
        cout << "Daftar film tidak ada" << endl;
    }
}
void showSutradaraTersibuk(list_film f, list_sutradara s)
{
    int max = 0;
    adr_sutradara sibuk;
    adr_film p = f.first;
    adr_sutradara q = s.first;
    if(p != NULL && q != NULL)
    {
        while(q != NULL)
        {
            int i = 0;
            p = f.first;
            while(p != NULL)
            {
                if(p->relasi.first != NULL && p->relasi.first->info== q)
                {
                    i++;
                }
                p = p->next;
            }
            if(i > max)
            {
                max = i;
                sibuk = q;
            }
            q = q->next;
        }
    }
    if(max == 0)
    {
        cout << "Sutradara tersibuk tidak ditemukan";
    }
    else
    {
        cout << "Sutradara tersibuk adalah " << sibuk->info << " mengerjakan sebanyak " << max << " film";
    }
    cout << endl;
}
void findFilmBySutradara(list_film f, list_sutradara s)
{
    if(s.first != NULL)
    {
        infotype_sutradara x;
        inputStr("Nama sutradara",x);
        adr_sutradara q = findElm(s,x);
        while(q == NULL)
        {
            cout << "Sutradara " << x << " tidak ditemukan." << endl;
            inputStr("Nama sutradara",x);
            q = findElm(s,x);
        }
        adr_film p = f.first;
        int i = 1;
        while(p != NULL)
        {
            if(findElm(p->relasi,q))
            {
                if(i == 1)
                {
                    cout << "Daftar film yang dikerjakan oleh " << q->info << " : " << endl;
                }
                cout << i << ". " << p->info << endl;
                i++;
            }
            p = p->next;
        }
        if(i == 1)
        {
            cout << "Sutradara " << x << " belum pernah mengerjakan film" << endl;
        }
    }
    else
    {
        cout << "Daftar sutradara tidak ada.";
    }
    cout << endl;
}
void showFilmDuaSutradara(list_film f)
{
    int no = 1;
    if(f.first != NULL)
    {
        adr_film p = f.first;
        cout << "Daftar film dengan dua sutradara :" << endl;
        while(p != NULL)
        {
            if(p->relasi.first != NULL)
            {
                adr_relasi r = p->relasi.first;
                int i = 0;
                while(r != NULL)
                {
                    i++;
                    r = r->next;
                }
                if(i == 2)
                {
                    cout << no << ". " << p->info << endl;
                    no++;
                }
            }
            p = p->next;
        }
    }
    if(no == 1)
    {
        cout << "Film dengan dua sutradara tidak ditemukan" << endl;
    }
    cout << endl;
}
void showSutradaraTersantai(list_film f, list_sutradara s)
{
    int min = countFilm(f)+1;
    adr_sutradara santai;
    adr_film p = f.first;
    adr_sutradara q = s.first;
    if(p != NULL && q != NULL)
    {
        while(q != NULL)
        {
            int i = 0;
            p = f.first;
            while(p != NULL)
            {
                adr_relasi r = findElm(p->relasi, q);
                if(r != NULL && r != p->relasi.first )
                {
                    i++;
                }

                p = p->next;
            }
            if(i < min)
            {
                min = i;
                santai = q;
            }
            q = q->next;
        }
        if(min == 0)
        {
            cout << santai->info << " merupakan asisten sutradara tersantai karena belum pernah mengerjakan film sebagai asisten sutradara";
        }
        else
        {
            cout << "Asisten sutradara tersantai adalah " << santai->info << " mengerjakan sebanyak " << min << " film";
        }

    }
    else
    {
        cout << "Asisten sutradara tersantai tidak ditemukan";
    }
    cout << endl;
}
void changeSutradaraName(list_sutradara &s)
{
    if(s.first != NULL)
    {
        infotype_sutradara x;
        infotype_sutradara y;
        inputStr("Nama sutradara",x);
        adr_sutradara q = findElm(s,x);
        while(q == NULL)
        {
            cout << "Sutradara " << x << " tidak ditemukan." << endl;
            inputStr("Nama sutradara",x);
            q = findElm(s,x);
        }
        inputStr("Nama sutradara pengganti",y);
        while(findElm(s,y) != NULL)
        {
            cout << "Sutradara " << x << " sudah ada." << endl;
            inputStr("Nama sutradara pengganti",y);
        }
        q->info = y;
        cout << "nama Sutradara " << x << " telah diganti dengan " << y << endl;
    }
    else
    {
        cout << "Daftar sutradara tidak ada";
    }
    cout << endl;
}
void changeFilmTitle(list_film &f)
{
    if(f.first != NULL)
    {
        infotype_film x;
        infotype_film y;
        inputStr("Nama film",x);
        adr_film q = findElm(f,x);
        while(q == NULL)
        {
            cout << "film " << x << " tidak ditemukan." << endl;
            inputStr("Nama film",x);
            q = findElm(f,x);
        }
        inputStr("Nama film pengganti",y);
        while(findElm(f,y) != NULL)
        {
            cout << "film " << x << " sudah ada." << endl;
            inputStr("Nama film pengganti",y);
        }
        q->info = y;
        cout << "Judul film " << x << " telah diganti dengan " << y << endl;
    }
    else
    {
        cout << "Daftar film tidak ada";
    }
    cout << endl;
}
void showData(list_film f, list_sutradara s)
{
    adr_film p = f.first;
    if(p != NULL)
    {
        cout << "Daftar film yang ada : " << endl;
        int i = 1;
        while(p != NULL)
        {
            cout << i << ". " << p->info << endl;
            i++;
            p = p->next;
        }
    }
    else
    {
        cout << "Daftar film masih kosong, silahkan tambahkan film." << endl;
    }

    cout << endl;
    adr_sutradara q = s.first;
    if(q != NULL)
    {
        cout << "Daftar sutradara yang ada : " << endl;
        int i = 1;
        while(q != NULL)
        {
            cout << i << ". " << q->info << endl;
            i++;
            q = q->next;
        }
    }
    else
    {
        cout << "Daftar sutradara masih kosong, silahkan tambahkan sutradara." << endl;
    }
    cout << endl;

    p = f.first;
    if(p != NULL)
    {
        cout << "Daftar film dan sutradaranya : " << endl;
        int i = 1;
        while(p != NULL)
        {
            cout << i << ". " << p->info << endl;
            printInfo(p->relasi);
            cout << endl;
            i++;
            p = p->next;
        }
        cout << endl;
    }

}
void showFilmBanyakSutradara(list_film f)
{
    adr_film p = f.first;
    adr_relasi q;
    if(p != NULL)
    {
        cout << "Film dengan sutradara terbanyak adalah : " << endl;
        int imax = 0;
        adr_film pmax = NULL;
        int i = 0;
        while(p != NULL)
        {
            q = p->relasi.first;
            i = 0;
            while(q != NULL)
            {
                i++;
                q = q->next;
            }
            if(i > imax)
            {
                imax = i;
                pmax = p;
            }
            p = p->next;
        }
        if(pmax == NULL)
        {
            cout << "Tidak ditemukan";
        }
        else
        {
            cout << pmax->info;
        }
        cout << endl;
    }
    else
    {
        cout << "Daftar film tidak ada" << endl;
    }
}
void inputStr(string pesan, string &txt)
{
    cout << pesan << " : ";
    getline(cin,txt);
    while(txt == "")
    {
        cout << "Input tidak boleh kosong\n";
        cout << pesan << " : ";
        getline(cin,txt);
    }
}
void inputInt(string pesan, int &bil)
{
    string i;
    inputStr(pesan,i);
    int panjang = i.length();
    if(i == "0")
    {
        bil = 0;
    }
    else
    {
        bil = atoi(i.c_str());
        while(bil == 0 || countInt(bil)/panjang < 1)
        {
            cout << "Masukan angka dengan benar\n";
            inputStr(pesan,i);
            panjang = i.length();
            bil = atoi(i.c_str());
        }
    }
}
void banner(string text)
{
    int i = text.length();
    for(int j = 0; j<i+4; j++)
    {
        cout << "=";
    }

    cout <<endl << "= ";
    cout << text;
    cout << " =" << endl;

    for(int j = 0; j<i+4; j++)
    {
        cout << "=";
    }
    cout << endl;
}
int countInt(int x)
{
    int i=0;
    while(x>0)
    {
        x/=10;
        i++;
    }
    return i;
}
