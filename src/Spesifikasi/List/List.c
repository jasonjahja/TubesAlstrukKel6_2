#include <stdio.h>
#include "List.h"

void list_default(ListofPenyanyi L)
{
    char *a = "Y";
    printf("\n");
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < BanyakPenyanyi(L); i++)
    {
        printf("\t %d. ", i+1);
        TulisWord(L.listpenyanyi[i].namaPenyanyi);
        printf("Panjang Kata = %d\n", L.listpenyanyi[i].namaPenyanyi.Length);
    }
    printf("\n");
    printf("Ingin melihat album yang ada? (Y/N) : ");
    STARTINPCOMMAND(stdin);
    TulisWord(toKata(currentLine.kalimat));
    printf("Panjang Kata = %d\n", currentLine.lengthsentence);

    if (IsWordEq(toKata(currentLine.kalimat), toKata(a))) 
    {
        printf("Pilih penyanyi untuk melihat album mereka : ");
        GetCommand();
        TulisWord(toKata(currentLine.kalimat));
        printf("Panjang Kata = %d\n", currentLine.lengthsentence);
        int idxlagu = IndeksPenyanyi(L, toKata(currentLine.kalimat));
        
        printf("IDXLAGU = %d\n", idxlagu);
        
        printf("\n");
        printf("Daftar Album oleh ");
        TulisWordNoNL((L).listpenyanyi[idxlagu].namaPenyanyi);
        printf(" :\n");
        for (int j = 0; j < BanyakAlbum(L.listpenyanyi[idxlagu].album); j++)
        {
            printf("\t %d. ", j+1);
            TulisWord(L.listpenyanyi[idxlagu].album.listalbum[j].namaAlbum);
        }

        printf("\n");   
        printf("Ingin melihat lagu yang ada? (Y/N) : ");
        GetCommand();
        printf("\n");

        if (IsWordEq(toKata(currentLine.kalimat), toKata(a)))
        {
            printf("Pilih album untuk melihat lagu yang ada di album : ");
            GetCommand();

            printf("\n");
            int idxalbum = IndeksAlbum(L.listpenyanyi[idxlagu].album, toKata(currentLine.kalimat));

            printf("Daftar lagu di ");
            TulisWordNoNL(L.listpenyanyi[idxlagu].album.listalbum[idxalbum].namaAlbum);
            printf(" :\n");
            for (int k = 0; k < BanyakLagu(L.listpenyanyi[idxlagu].album.listalbum[idxalbum].listlagu); k++)
            {
                printf("\t %d. ", k+1);
                TulisWord(L.listpenyanyi[idxlagu].album.listalbum[idxalbum].listlagu.Lagu[k].judul);
            }
        }
    }
}