#include <stdio.h>
#include "List.h"

void list_default(ListofPenyanyi L)
{  
    printf("\nDaftar Penyanyi :\n");
    for (int i = 0; i < BanyakPenyanyi(L); i++)
    {
        printf("\t %d. ", i+1);
        TulisWord(L.listpenyanyi[i].namaPenyanyi);
    }
    printf("\nIngin melihat album yang ada? (Y/N) : ");
    GetInput();

    if (IsWordEq(toKata(currentInput.TabWord), toKata("Y"))) 
    {
        printf("Pilih penyanyi untuk melihat album mereka : ");
        GetInput();
        int idxlagu = IndeksPenyanyi(L, currentInput);
        
        printf("\nDaftar Album oleh %s : \n", currentInput.TabWord);
        for (int j = 0; j < BanyakAlbum(L.listpenyanyi[idxlagu].album); j++)
        {
            printf("\t %d. ", j+1);
            TulisWord(L.listpenyanyi[idxlagu].album.listalbum[j].namaAlbum);
        }

        printf("\nIngin melihat lagu yang ada? (Y/N) : ");
        GetInput(); 

        if (IsWordEq(toKata(currentInput.TabWord), toKata("Y")))
        {
            printf("Pilih album untuk melihat lagu yang ada di album : ");
            GetInput();
            printf("\n");
            int idxalbum = IndeksAlbum(L.listpenyanyi[idxlagu].album, currentInput);

            printf("Daftar lagu di %s: \n", currentInput.TabWord);
            for (int k = 0; k < BanyakLagu(L.listpenyanyi[idxlagu].album.listalbum[idxalbum].listlagu); k++)
            {
                printf("\t %d. ", k+1);
                TulisWord(L.listpenyanyi[idxlagu].album.listalbum[idxalbum].listlagu.Lagu[k].judul);
            }
        }
    }
}

void list_playlist(ListofPlaylist L)
{
    
}