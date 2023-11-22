#ifndef __map_H__
#define __map_H__

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../set/set.h"

/* Kamus Umum */
#define MaxElMap 7
extern const Word Mark;

typedef struct
{
	Word namaAlbum;
	SetofSong listlagu;
	
} Album;

typedef struct
{
	Album listalbum[MaxElMap];

} MapofAlbum;

/* ********** KONSTRUKTOR ********** */
MapofAlbum CreateEmptyAlbum();

/* ********** FUNGSI-FUNGSI ********** */
boolean IsEmptyAlbum(MapofAlbum M);

boolean IsFullAlbum(MapofAlbum M);

int BanyakAlbum(MapofAlbum M);

int IndeksAlbum(MapofAlbum M, Word k);

boolean IsMemberAlbum(MapofAlbum M, Word k);

void AddAlbum(MapofAlbum *M, Word k);

void DelAlbum(MapofAlbum *M, Word k);

Word GetAlbum(MapofAlbum M, Word k);

void DisplayListAlbum (MapofAlbum M);

#endif
