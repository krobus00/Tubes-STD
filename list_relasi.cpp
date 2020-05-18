#include "list_relasi.h"

void createList(list_relasi &r)
{
    r.first = NULL;
    r.last = NULL;
}
void printInfo(list_relasi r)
{
    adr_relasi p = r.first;
    if(p != NULL)
    {
        int i = 1;
        cout << "Daftar sutradara : " << endl;
        while(p != NULL)
        {
            cout << "-> ";
            if(p == r.first)
            {
                cout << "Sutradara : ";
            }
            else
            {
                cout << "Asisten sutradara " << i << " : ";
                i++;
            }
            cout << p->info->info << endl;
            p = p->next;
        }
    }
    else
    {
        cout << "Tidak memiliki sutradara, silahkan tambahkan sutradara untuk film ini." << endl;
    }
}
adr_relasi findElm(list_relasi r, adr_sutradara x)
{
    adr_relasi p = r.first;
    while(p != NULL)
    {
        if(p->info == x)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void insertElm(list_relasi &r, adr_sutradara x)
{
    adr_relasi elm = new elmRelasi;
    elm->info = x;
    elm->next = NULL;

    if(r.first != NULL)
    {
        r.last->next = elm;
        r.last = elm;
    }
    else
    {
        r.first = elm;
        r.last = elm;
    }
}
void deleteElm(list_relasi &r, adr_relasi p)
{
    adr_relasi del;
    if(p != NULL && r.first != NULL)
    {
        adr_relasi q = r.first;
        adr_relasi s;
        while(q != NULL && q != p)
        {
            s = q;
            q = q->next;
        }
        if(p == r.first)
        {
            del = r.first;
            r.first = del->next;
        }
        else if(p == r.last)
        {
            del = r.last;
            r.last = s;
            s->next = NULL;
        }
        else
        {
            del = s->next;
            s->next = del->next;

        }
        if(r.last == NULL || r.first == NULL)
        {
            r.first = NULL;
            r.last = NULL;
        }
        delete del;
    }
    else
    {
        cout << "Terjadi kesalahan saat menghapus sutradara pada film!" << endl;
    }
}
