#ifndef LIST_SUTRADARA_H_INCLUDED
#define LIST_SUTRADARA_H_INCLUDED
#include <iostream>
using namespace std;
typedef string infotype_sutradara;
typedef struct elmSutradara *adr_sutradara;
struct elmSutradara{
    infotype_sutradara info;
    adr_sutradara next;
};
struct list_sutradara{
    adr_sutradara first;
    adr_sutradara last;
};

void createList(list_sutradara &s);
void printInfo(list_sutradara s);
adr_sutradara findElm(list_sutradara s, infotype_sutradara x);
void insertElm(list_sutradara &s, infotype_sutradara x);
void deleteElm(list_sutradara &s, adr_sutradara p);


#endif // LIST_SUTRADARA_H_INCLUDED
