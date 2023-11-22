#include <stdio.h>
#include "map.h"

const Word Mark = {'\0',0};

/* ********* IMPLEMENTASI FUNGSI-FUNGSI ********* */
MapofAlbum CreateEmptyAlbum()
{
    MapofAlbum M;
    for (int i = 0 ; i < MaxElMap ; i++)
    {
        M.listalbum[i].namaAlbum = Mark;
    }
    return M;
}

boolean IsEmptyAlbum(MapofAlbum M)
{
    return (IsWordEq(M.listalbum[0].namaAlbum, Mark));
}

boolean IsFullAlbum(MapofAlbum M)
{
    return (!IsWordEq(M.listalbum[BanyakAlbum(M)-1].namaAlbum, Mark));
}

int BanyakAlbum(MapofAlbum M)
{
    int count = 0;
    for (int i = 0; i < MaxElMap; i++)
    {
        if (IsWordEq(M.listalbum[i].namaAlbum, Mark))
        {
            return count;
        }
        count++;
    }
    return count;
}

boolean IsMemberAlbum(MapofAlbum M, Word k)
{
    for (int i = 0; i < MaxElMap; i++)
    {
        if (IsWordEq(M.listalbum[i].namaAlbum, k))
        {
            return true;
        }
    }
    return false;
}


Word GetAlbum(MapofAlbum M, Word k)
{
    for (int i = 0; i < MaxElMap; i++)
    {
        if (IsWordEq(M.listalbum[i].namaAlbum, k))
        {
            return k;
        }
    }
    return k;
}

void AddAlbum(MapofAlbum *M, Word k)
{
    if (!IsMemberAlbum(*M, k))
    {
        CopyWordToVar(&(M->listalbum[BanyakAlbum(*M)].namaAlbum), k);   
    }
}


void DelAlbum(MapofAlbum *M, Word k)
{
    int idx = 0;
    if (IsMemberAlbum(*M,k))
    {
            while(IsWordEq((*M).listalbum[idx].namaAlbum, k))
            {
                idx++;
            }
            while (idx < BanyakAlbum(*M))
            {
                    (*M).listalbum[idx] = (*M).listalbum[idx+1];
                    idx++;
            }
            CopyWordToVar(&(*M).listalbum[idx].namaAlbum, Mark);
    }
}

void DisplayListAlbum (MapofAlbum M)
{
    for (int i = 0; i < BanyakAlbum(M); i++)
    {
        printf("     %d. ",i+1);
        TulisWord(M.listalbum[i].namaAlbum);
    }
}

int IndeksAlbum(MapofAlbum M, Word k)
{
    if (IsMemberAlbum(M, k))
    {
        int count = 0;
        for (int i = 0; i < BanyakAlbum(M); i++)
        {
            if (IsWordEq(M.listalbum[count].namaAlbum, k))
            {
                return count;
            }
            count++;
        }
    }
    return -1;
}