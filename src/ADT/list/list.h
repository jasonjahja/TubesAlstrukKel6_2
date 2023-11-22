#ifndef __LIST_H__
#define __LIST_H__

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../map/map.h"

/* Kamus Umum */
#define MaxElList 5
typedef struct {

    Word namaPenyanyi;
    MapofAlbum album;

} Penyanyi;

typedef struct {

	Penyanyi listpenyanyi[MaxElList]; 

} ListofPenyanyi; 

/* ********** KONSTRUKTOR ********** */
ListofPenyanyi MakeList();

//* ********** FUNGSI-FUNGSI ********** */
boolean IsEmptyList(ListofPenyanyi L);

boolean IsFullList(ListofPenyanyi L);

int BanyakPenyanyi (ListofPenyanyi L);

boolean isMemberPenyanyi(ListofPenyanyi L, Word X);

int IndeksPenyanyi (ListofPenyanyi L, Word X);

Word GetPenyanyi(ListofPenyanyi L, Word singer);

void AddPenyanyi (ListofPenyanyi *L, Word singer);

void DelPenyanyi (ListofPenyanyi *L, Word singer);

void DisplayListPenyanyi (ListofPenyanyi L);

#endif