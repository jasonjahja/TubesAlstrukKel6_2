#include "Song.h"

#include <stdio.h>

int main()
{
    CurrentStat currentSong;
    char *judul = "Boombayah";
    char *album = "Born to Pink";
    char *penyanyi = "BLACKPINK";
    currentSong.currentplay.judul = toKata(judul);
    currentSong.currentplay.album = toKata(album);
    currentSong.currentplay.penyanyi = toKata(penyanyi);
    currentSong.currentplay.status = 1;

    Queue queue;
    CreateEmptyQueue(&queue);
    songHistory history;
    CreateEmptyStack(&history);

    enqueueQueue(&queue, toKata("LAGU"), toKata("ALBUM"), toKata("JASON"));
    enqueueQueue(&queue, toKata("LAGU2"), toKata("ALBUM2"), toKata("JASON2"));

    displayQueue(queue);
    nextSong(&queue, &history, &currentSong); printf("\n");

    PrintStack(history);
    prevSong(&queue, &history, &currentSong); printf("\n");
    
    displayQueue(queue);
    nextSong(&queue, &history, &currentSong); printf("\n");
    
    displayQueue(queue);
    nextSong(&queue, &history, &currentSong); printf("\n");
    
    displayQueue(queue);
    nextSong(&queue, &history, &currentSong); printf("\n");

    return 0;
}