#ifndef LIST_FILM_H_INCLUDED
#define LIST_FILM_H_INCLUDED
#include <iostream>
#include "list_relasi.h"
using namespace std;
typedef string infotype_film;
typedef struct elmFilm *adr_film;
struct elmFilm{
    infotype_film info;
    list_relasi relasi;
    adr_film next;
};
struct list_film{
    adr_film first;
    adr_film last;
};
void createList(list_film &f);
void printInfo(list_film f);
adr_film findElm(list_film f, infotype_film x);
void insertElm(list_film &f, infotype_film x);
void deleteElm(list_film &f, adr_film p);

int countFilm(list_film f);
#endif // LIST_FILM_H_INCLUDED
