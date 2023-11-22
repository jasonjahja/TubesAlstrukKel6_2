#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void queueSong (ListofPenyanyi daftarpenyanyi, Queue * queue)
{
    if (!IsFullQueue(*queue))
    {
        printf("Daftar Penyanyi:\n");
        for (int i = 0; i < BanyakPenyanyi(daftarpenyanyi); i++)
        {
            printf("%d. ", i+1);
            TulisWord(daftarpenyanyi.listpenyanyi[i].namaPenyanyi);
        }

        printf("Masukkan nama penyanyi yang dipilih: ");
        STARTINPCOMMAND(stdin);
        Word inp = toKata(currentLine.kalimat);
        int IDPenyanyi = IndeksPenyanyi(daftarpenyanyi, inp);

        while (IDPenyanyi == -1)
        {
            printf("Nama penyanyi tidak terdaftar!\n");
            printf("Masukkan nama penyanyi yang dipilih: ");
            STARTINPCOMMAND(stdin);
            Word inp = toKata(currentLine.kalimat);
            IDPenyanyi = IndeksPenyanyi(daftarpenyanyi, inp);
        }

        if (IDPenyanyi != -1)
        {
            printf("Daftar Album:\n");
            for (int j = 0; j < BanyakAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album); j++)
            {
                printf("%d. ", j+1);
                TulisWord(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[j].namaAlbum);
            }

            printf("Masukkan nama album yang dipilih: ");
            STARTINPCOMMAND(stdin);
            Word inp = toKata(currentLine.kalimat);
            int IDAlbum = IndeksAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album, inp);
            
            while (IDAlbum == -1)
            {
                printf("Nama album tidak terdaftar!\n");
                printf("Masukkan nama album yang dipilih: ");
                STARTINPCOMMAND(stdin);
                Word inp = toKata(currentLine.kalimat);
                IDAlbum = IndeksAlbum(daftarpenyanyi.listpenyanyi[IDPenyanyi].album, inp);
            }

            if (IDAlbum != -1)
            {
                printf("Daftar Lagu:\n"); 
                for (int k = 0; k < BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu); k++)
                {
                    printf("%d. ", k+1);
                    TulisWord(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[k].judul);
                }

                printf("Masukkan ID lagu yang dipilih: ");
                STARTINPCOMMAND(stdin);
                Word inp = toKata(currentLine.kalimat);
                int IDLagu = WordtoNum (inp) - 1;

                while (IDLagu <= -1 && IDLagu > BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
                {
                    printf("ID Lagu tidak terdaftar!\n");
                    printf("Masukkan ID lagu yang dipilih: ");
                    STARTINPCOMMAND(stdin);
                    Word inp = toKata(currentLine.kalimat);
                    IDLagu = WordtoNum (inp) - 1;
                }

                if (IDLagu < BanyakLagu(daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu))
                {
                    Word song = daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul;
                    Word album = daftarpenyanyi.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].namaAlbum;
                    Word singer = daftarpenyanyi.listpenyanyi[IDPenyanyi].namaPenyanyi;
                    enqueueQueue(queue, song, album, singer);

                    printf("Menambahkan lagu. . .\n");
                    printf("Berhasil menambahkan lagu \""); TulisWordNoNL(song);
                    printf("\" oleh \""); TulisWordNoNL(singer); printf("\" ke queue.\n");
                }
            }
        }
    }

    else
    {
        printf("Queue penuh! Tidak dapat menambahkan lagu ke queue.\n");
    }
}

void queuePlaylist(ListofPlaylist daftarplaylist, Queue * queue)
{
    printf("Masukkan ID Playlist: ");
    STARTINPCOMMAND(stdin);
    Word inp = toKata(currentLine.kalimat);
    int IDPlaylist = WordtoNum(inp) - 1;

    while (IDPlaylist <= -1 && IDPlaylist > (daftarplaylist.nEff - 1))
    {
        printf("ID Playlist tidak terdaftar!\n");
        printf("Masukkan ID Playlist: ");
        STARTINPCOMMAND(stdin);
        Word inp = toKata(currentLine.kalimat);
        inp = toKata(currentLine.kalimat);
        IDPlaylist = WordtoNum(inp) - 1;
    }

    address P = daftarplaylist.list[IDPlaylist].First;
    int ctr = 0;

    while (P != NilNode)
    {
        ctr++;
        P = Next(P);
    }

    if ((ctr-1) > IDX_MAXQueue)
    {
        printf("Queue penuh! Tidak dapat menambahkan lagu ke queue\n");
    }
    else
    {
        P = daftarplaylist.list[IDPlaylist].First;
        while (P != NilNode)
        {
            enqueueQueue(queue, P->info.Lagu.judul, P->info.Lagu.album, P->info.Lagu.penyanyi);
            P = Next(P);
        }

        printf("Berhasil menambahkan playlist \""); TulisWord(daftarplaylist.namaPlaylist[IDPlaylist]); printf("\" ke queue.\n");
    }
}

void queueSwap (Queue * queue, int id1, int id2)
{
    int idx1 = id1-1;
    int idx2 = id2-1;

    if ((idx1 < 0 || idx1 > (*queue).idxTail) && (idx2 < 0 || idx2 > (*queue).idxTail))
    {
        printf("Mencari lagu dengan urutan ke %d dan %d dalam queue. . .\n", id1, id2);
        printf("Lagu dengan urutan ke %d dan %d tidak ada.\n");
    }
    else if (idx1 < 0 || idx1 > (*queue).idxTail)
    {
        printf("Mencari lagu dengan urutan ke %d dan %d dalam queue. . .\n", id1, id2);
        printf("Lagu dengan urutan ke %d tidak ada.\n", id1);
    }
    else if (idx2 < 0 || idx2 > (*queue).idxTail)
    {
        printf("Mencari lagu dengan urutan ke %d dan %d dalam queue. . .\n", id1, id2);
        printf("Lagu dengan urutan ke %d tidak ada.\n", id2);
    }
    else
    {
        Song temp;
        temp.judul = (*queue).song[idx2];
        temp.album = (*queue).album[idx2];
        temp.penyanyi = (*queue).singer[idx2];

        (*queue).song[idx2] = (*queue).song[idx1];
        (*queue).album[idx2] = (*queue).album[idx1];
        (*queue).singer[idx2] = (*queue).singer[idx1];

        (*queue).song[idx1] = temp.judul;
        (*queue).album[idx1] = temp.album;
        (*queue).singer[idx1] = temp.penyanyi;

        printf("Mencari lagu dengan urutan ke %d dan %d dalam queue. . .\n", id1, id2);
        printf("Lagu \""); TulisWordNoNL((*queue).song[idx2]); 
        printf("\" berhasil ditukar dengan \""); TulisWordNoNL((*queue).song[idx1]); printf("\".\n");
    }
}

void queueRemove (Queue * queue, int id)
{
    int idx = id-1;
    if (idx < 0 || idx > (*queue).idxTail)
    {
        printf("Mencari lagu dengan urutan ke %d dalam queue. . .\n", id);
        printf("Lagu dengan urutan ke %d tidak ada.\n", id);
    }
    else
    {
        Word song = (*queue).song[idx];
        Word album = (*queue).album[idx];
        Word singer = (*queue).singer[idx];
        dequeueSong(queue, id); 
        printf("Mencari lagu dengan urutan ke %d dalam queue. . .\n", id);
        printf("Lagu \""); TulisWordNoNL(song);
        printf("\" oleh \""); TulisWordNoNL(singer);
        printf("\" telah dihapus dari queue.\n");
    }
}

void queueClear (Queue * queue)
{
    CreateEmptyQueue(queue);
    printf("Mengosongkan queue. . .\n");
    printf("Queue berhasil dikosongkan.\n");
}

void dequeueSong (Queue * queue, int id)
{
    for (int i = id-1; i < IDX_TAIL(*queue); i++)
    {
        (*queue).song[i] = (*queue).song[i+1];
        (*queue).album[i] = (*queue).album[i+1];
        (*queue).singer[i] = (*queue).singer[i+1];
    }

    (*queue).idxTail--;
}