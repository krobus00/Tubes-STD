#include "list_sutradara.h"

void createList(list_sutradara &s)
{
    s.first = NULL;
    s.last = NULL;
}
void printInfo(list_sutradara s)
{
    adr_sutradara p = s.first;
    if(p != NULL)
    {
        cout << "Daftar sutradara yang ada : " << endl;
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
        cout << "Daftar sutradara masih kosong, silahkan tambahkan sutradara." << endl;
    }
}
adr_sutradara findElm(list_sutradara s, infotype_sutradara x)
{
    adr_sutradara p = s.first;
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
void insertElm(list_sutradara &s, infotype_sutradara x)
{
    adr_sutradara elm = new elmSutradara;
    elm->info = x;
    elm->next = NULL;

    adr_sutradara p = s.first;

    if(p != NULL)
    {
        s.last->next = elm;
        s.last = elm;
    }
    else
    {
        s.first = elm;
        s.last = elm;
    }
}
void deleteElm(list_sutradara &s, adr_sutradara p)
{
   adr_sutradara del;
    if(p != NULL && s.first != NULL)
    {
        adr_sutradara q = s.first;
        adr_sutradara r;
        while(q != NULL && q != p)
        {
            r = q;
            q = q->next;
        }
        if(p == s.first)
        {
            del = s.first;
            s.first = del->next;
        }
        else if(p == s.last)
        {
            del = s.last;
            s.last = r;
            r->next = NULL;
        }
        else
        {
            del = r->next;
            r->next = del->next;

        }
        if(s.last == NULL || s.first == NULL)
        {
            s.first = NULL;
            s.last = NULL;
        }
        delete del;
    }
    else
    {
        cout << "Terjadi kesalahan saat menghapus sutradara!" << endl;
    }
}
