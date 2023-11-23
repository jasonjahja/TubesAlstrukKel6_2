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

    address P = playlistMarcell.list[0].First;
    
    P->info.Lagu.judul = toKata("Alstrukdat");
    P->info.Lagu.album = toKata("STI ANJG");
    P->info.Lagu.penyanyi = toKata("Marceng");
    printf("---------\n");
    P = Next(P);
    P->info.Lagu.judul = toKata("PinkVenom");
    P->info.Lagu.album = toKata("Born Pink");
    P->info.Lagu.penyanyi = toKata("BLACKPINK");

    // playPlaylist(playlistMarcell, &CS, &SH, &Q);

    return 0;
}