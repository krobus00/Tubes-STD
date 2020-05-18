#include "list_film.h"

void createList(list_film &f)
{
    f.first = NULL;
    f.last = NULL;
}
void printInfo(list_film f)
{
    adr_film p = f.first;
    if(p != NULL)
    {
        cout << "Daftar film yang ada : " << endl;
        int i = 1;
        while(p != NULL)
        {
            cout << i << ". " << p->info << endl;
            printInfo(p->relasi);
            cout << endl;
            i++;
            p = p->next;
        }
    }
    else
    {
        cout << "Daftar film masih kosong, silahkan tambahkan film." << endl;
    }
}
adr_film findElm(list_film f, infotype_film x)
{
    adr_film p = f.first;
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
void insertElm(list_film &f, infotype_film x)
{
    adr_film elm = new elmFilm;
    createList(elm->relasi);

    elm->info = x;
    elm->next = NULL;

    adr_film p = f.first;

    if(p != NULL)
    {
        f.last->next = elm;
        f.last = elm;
    }
    else
    {
        f.first = elm;
        f.last = elm;
    }
}
void deleteElm(list_film &f, adr_film p)
{
    adr_film del;
    if(p != NULL && f.first != NULL)
    {
        adr_film q = f.first;
        adr_film r;
        while(q != NULL && q != p)
        {
            r = q;
            q = q->next;
        }
        if(p == f.first)
        {
            del = f.first;
            f.first = del->next;
        }
        else if(p == f.last)
        {
            del = f.last;
            f.last = r;
            r->next = NULL;
        }
        else
        {
            del = r->next;
            r->next = del->next;

        }
        if(f.last == NULL || f.first == NULL)
        {
            f.first = NULL;
            f.last = NULL;
        }
        delete del;
    }
    else
    {
        cout << "Terjadi kesalahan saat menghapus film!" << endl;
    }
}
int countFilm(list_film f)
{
    adr_film p = f.first;
    int i = 0;
    while(p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}
