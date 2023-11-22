#include "Song.h"
#include <stdio.h>
#include <time.h>

void nextSong(Queue *queue, songHistory *history, CurrentStat *currentSong)
{
    int t = 1; /* untuk animasi delay 1*/
    if (currentSong->currentplay.status == 0)
    {
        if (!IsEmptyQueue(*queue))
        {
            printf("Memutar lagu selanjutnya. . .\n");
            printf("Memainkan lagu \"");
            TulisWordNoNL(HEADSONG(*queue));
            printf("\" oleh \"");
            TulisWordNoNL(HEADSINGER(*queue));
            printf("\"\n");
            currentSong->currentplay.judul = HEADSONG(*queue);
            currentSong->currentplay.album = HEADALBUM(*queue);
            currentSong->currentplay.penyanyi = HEADSINGER(*queue);
            currentSong->currentplay.status = 1;
            dequeueQueue(queue);
        }
        else
        {
            printf("Tidak ada lagu dalam antrian.\n");
            printf("Tidak ada lagu yang dapat diputar.\n");
        }
    }
    else
    {
        if (!IsEmptyQueue(*queue))
        {
            printf("Memutar lagu selanjutnya. . .\n");
            printf("Memainkan lagu \"");
            TulisWordNoNL(HEADSONG(*queue));
            printf("\" oleh \"");
            TulisWordNoNL(HEADSINGER(*queue));
            printf("\"\n");
            PushStack(history, currentSong->currentplay.judul, currentSong->currentplay.album, currentSong->currentplay.penyanyi);
            currentSong->currentplay.judul = HEADSONG(*queue);
            currentSong->currentplay.album = HEADALBUM(*queue);
            currentSong->currentplay.penyanyi = HEADSINGER(*queue);
            dequeueQueue(queue);
        }
        else
        {
            printf("Tidak ada lagu dalam antrian.\n");
            printf("Memutar kembali lagu. . .\n");
            printf("Memainkan lagu \"");
            TulisWordNoNL(currentSong->currentplay.judul);
            printf("\" oleh \"");
            TulisWordNoNL(currentSong->currentplay.penyanyi);
            printf("\"\n");
        }
    }
}

void prevSong(Queue *queue, songHistory *history, CurrentStat *currentSong)
{
    if (currentSong->currentplay.status != 0)
    {
        if (!IsEmptyStack(*history))
        {
            enqueueFirstQueue(queue, (*currentSong).currentplay.judul, (*currentSong).currentplay.album, (*currentSong).currentplay.penyanyi);
            printf("Memutar lagu sebelumnya. . .\n");
            PopStack(history, &(currentSong->currentplay.judul), &(currentSong->currentplay.album), &(currentSong->currentplay.penyanyi));
            printf("Memainkan lagu \"");
            TulisWordNoNL(currentSong->currentplay.judul);
            printf("\" oleh \"");
            TulisWordNoNL(currentSong->currentplay.penyanyi);
            printf("\"\n");
        }
        else
        {
            printf("Riwayat lagu kosong.\n");
            printf("Memutar kembali lagu. . .\n");
            printf("Memainkan lagu \"");
            TulisWordNoNL(currentSong->currentplay.judul);
            printf("\" oleh \"");
            TulisWordNoNL(currentSong->currentplay.penyanyi);
            printf("\"\n");
        }
    }
    else
    {
        printf("Belum ada lagu yang diputar.\n");
    }
}

void enqueueFirstQueue (Queue * Q, Word song, Word album, Word singer)
{
    if (IsEmptyQueue(*Q))
    {
        enqueueQueue(Q, song, album, singer);
    }
    else
    {
        IDX_TAIL(*Q)++;
        for (int i = IDX_TAIL(*Q); i >=0; i--)
        {
            (*Q).song[i] = (*Q).song[i-1];
            (*Q).album[i] = (*Q).album[i-1];
            (*Q).singer[i] = (*Q).singer[i-1];
        }

        HEADSONG(*Q) = song;
        HEADALBUM(*Q) = album;
        HEADSINGER(*Q) = singer;
    }
}