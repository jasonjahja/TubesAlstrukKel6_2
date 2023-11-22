// gcc -o driver play.c ../../ADT/mesinbaris/mesinbaris.c ../../ADT/mesinkata/mesinkata.c ../../ADT/list/list.c ../../ADT/map/map.c ../../ADT/set/set.c ../../ADT/mesinkarakter/mesinkarakter.c ../../ADT/stack/stack.c ../../ADT/listdin/listdin.c ../../ADT/queue/queue.c ../../ADT/strukturberkait/listberkait.c
#include <stdio.h>
#include "Play.h"

int main(){
    // void playSong (ListofPenyanyi daftarpenyanyi, CurrentStat * currentSong, songHistory * history, Queue * queue)

    CurrentStat CS; CreateEmptyCurrentStat(&CS);
    ListofPenyanyi LP;
    songHistory SH; CreateEmptyStack(&SH);
    Queue Q; CreateEmptyQueue(&Q);

    AddPenyanyi(&LP,toKata("Jason"));
    AddPenyanyi(&LP,toKata("Afnan"));
    AddPenyanyi(&LP,toKata("Marcen"));
    AddPenyanyi(&LP,toKata("Hanans"));
    AddPenyanyi(&LP,toKata("Grcy"));

    AddAlbum(&(LP.listpenyanyi[0].album),toKata("JAS"));
    AddAlbum(&(LP.listpenyanyi[0].album),toKata("JAS1"));
    AddAlbum(&(LP.listpenyanyi[0].album),toKata("JAS2"));

    AddAlbum(&(LP.listpenyanyi[1].album),toKata("NAN"));
    AddAlbum(&(LP.listpenyanyi[1].album),toKata("NANA"));
    AddAlbum(&(LP.listpenyanyi[1].album),toKata("NANU"));

    AddLagu(&(LP.listpenyanyi[0].album.listalbum[0].listlagu),toKata("Halo bro"));
    AddLagu(&(LP.listpenyanyi[0].album.listalbum[0].listlagu),toKata("Halo cok"));

    AddLagu(&(LP.listpenyanyi[0].album.listalbum[1].listlagu),toKata("Halo brow"));
    AddLagu(&(LP.listpenyanyi[0].album.listalbum[1].listlagu),toKata("Halo brokk"));

    // playSong(LP, &CS, &SH, &Q);

    // playplaylist
    ListofPlaylist playlistMarcell;
    playlistMarcell = CreateListPlaylist();
    InsertListPlaylist(&playlistMarcell, toKata("Playlist gue"));
    InsertListPlaylist(&playlistMarcell, toKata("HAI"));
    DisplayListPlaylist(&playlistMarcell);

    printf("%d\n",playlistMarcell.list->First->info.Lagu.judul.TabWord);
    printf("%d\n",playlistMarcell.Capacity);
    
    address P = playlistMarcell.list[1].First;
    printf("%d\n",P);    

    P->info.Lagu.judul = toKata("Alstrukdat");
    TulisWord(P->info.Lagu.judul);
    P->info.Lagu.album = toKata("STI ANJG");
    P->info.Lagu.penyanyi = toKata("Marceng");
    P->info.Lagu.status = 0;
    printf("---------\n");
    P->info.Lagu.judul = toKata("PinkVenom");
    P->info.Lagu.album = toKata("Born Pink");
    P->info.Lagu.penyanyi = toKata("BLACKPINK");

    // playPlaylist(playlistMarcell, &CS, &SH, &Q);

    return 0;
}