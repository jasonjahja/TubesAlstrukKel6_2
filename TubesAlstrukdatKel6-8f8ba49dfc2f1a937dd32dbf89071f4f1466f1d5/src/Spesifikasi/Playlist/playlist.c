#include <stdio.h>
#include "playlist.h"
#include "../../ADT/strukturberkait/listberkait.c"
#include "../../ADT/listdin/listdin.c"
#include "../../ADT/mesinbaris/mesinbaris.c"
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/list/list.c"
#include "../../ADT/map/map.c"
#include "../../ADT//set/set.c"

void playlistCreate(ListofPlaylist *L){
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTWORD(stdin);
    TulisKalimat(currentLine);
    DisplayListPlaylist(L);
}
void playlistAdd(ListBerkait *L);
void playlistSwap(ListBerkait *L);
void playlistRemove(ListBerkait *L);
void playlistDelete(ListBerkait *L);

int main(){
    ListofPlaylist kumpulanPlaylist = CreateListPlaylist();
    playlistCreate(&kumpulanPlaylist);

    return 0;
}