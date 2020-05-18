#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include <iostream>
#include <stdlib.h> //atoi
#include "list_film.h"
#include "list_relasi.h"
#include "list_sutradara.h"
using namespace std;

void main_controller();
void dummy_data(list_film &f, list_sutradara &s);
void inputStr(string pesan, string &txt);
void inputInt(string pesan, int &bil);
void banner(string text);
void pause();


void addSutradara(list_sutradara &s);
void addFilm(list_film &f);
void addRelasi(list_film &f, list_sutradara s);
void delSutradara(list_film &f, list_sutradara &s);
void delFilm(list_film &f);
void showSutradaraTersibuk(list_film f, list_sutradara s);
void findFilmBySutradara(list_film f, list_sutradara s);
void showFilmDuaSutradara(list_film f);
void showSutradaraTersantai(list_film f, list_sutradara s);
void changeSutradaraName(list_sutradara &s);
void changeFilmTitle(list_film &f);
void showData(list_film f, list_sutradara s);
void showFilmBanyakSutradara(list_film f);
int countInt(int x);
#endif // CONTROLLER_H_INCLUDED
