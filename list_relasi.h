#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED
#include <iostream>
#include "list_sutradara.h"
using namespace std;

typedef struct elmRelasi *adr_relasi;
struct elmRelasi{
    adr_sutradara info;
    adr_relasi next;
};
struct list_relasi{
    adr_relasi first;
    adr_relasi last;
};
void createList(list_relasi &r);
void printInfo(list_relasi r);
adr_relasi findElm(list_relasi r, adr_sutradara x);
void insertElm(list_relasi &r, adr_sutradara x);
void deleteElm(list_relasi &r, adr_relasi p);
#endif // LIST_RELASI_H_INCLUDED
