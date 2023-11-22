#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(songHistory *S)
{
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(songHistory S)
{
    return (Top(S) == Nil);
}

boolean IsFullStack(songHistory S)
{
    return (Top(S) == MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(songHistory * S, Word song, Word album, Word singer)
{
    if (IsEmptyStack(*S))
    {
        Top(*S) = 0;
        InfoTopSong(*S) = song;
        InfoTopAlbum(*S) = album;
        InfoTopSinger(*S) = singer;
    }
    else
    {
        Top(*S)++;
        InfoTopSong(*S) = song;
        InfoTopAlbum(*S) = album;
        InfoTopSinger(*S) = singer;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(songHistory * S, Word* song, Word* album, Word* singer)
{
    *song = InfoTopSong(*S);
    *album = InfoTopAlbum(*S);
    *singer = InfoTopSinger(*S);
    if (Top(*S) == 0)
    {
        Top(*S) = Nil;
    }
    else
    {
        Top(*S)--;
    }
}

void PrintStack(songHistory S) {
    songHistory revStack;
    CreateEmptyStack(&revStack);
 
    Word songg;
    Word albumm;
    Word singerr;
    while (!IsEmptyStack(S)) {
        PopStack(&S, &songg, &albumm, &singerr);
        PushStack(&revStack, songg, albumm, singerr);
    }

    printf("[");
    while (!IsEmptyStack(revStack)) {
        PopStack(&revStack, &songg, &albumm, &singerr);
        printf("{");
        TulisWordNoNL(songg);
        printf(",");
        TulisWordNoNL(albumm);
        printf(",");
        TulisWordNoNL(singerr);
        printf("}");
        if (Top(S) >= 0) {
            printf(",");
        }
    }
    printf("]\n");
}