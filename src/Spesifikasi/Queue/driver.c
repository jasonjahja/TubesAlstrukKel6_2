// gcc -o driver driver.c queue.c ../../ADT/mesinbaris/mesinbaris.c ../../ADT/mesinkata/mesinkata.c ../../ADT/list/list.c ../../ADT/map/map.c ../../ADT/set/set.c ../../ADT/mesinkarakter/mesinkarakter.c ../../ADT/stack/stack.c ../../ADT/listdin/listdin.c ../../ADT/queue/queue.c ../../ADT/strukturberkait/listberkait.c ../../Spesifikasi/List/List.c ../../Spesifikasi/Play/play.c
#include "Queue.h"
#include <stdio.h>

int main() {
    // Initialize your data structures
    ListofPenyanyi LP;

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
    
    ListofPlaylist daftarplaylist;
    
    Queue queue;
    CreateEmptyQueue(&queue);

    // Assume you have initialized LP and daftarplaylist before using the functions

    // Test queueSong function
    queueSong(LP, &queue);
    queueSong(LP, &queue);

    // Test queuePlaylist function
    // queuePlaylist(daftarplaylist, &queue);

    // Test queueSwap function
    int id1, id2;
    printf("Enter two song IDs to swap: ");
    scanf("%d %d", &id1, &id2);
    queueSwap(&queue, id1, id2);

    // Test queueRemove function
    int removeId;
    printf("Enter the song ID to remove: ");
    scanf("%d", &removeId);
    queueRemove(&queue, removeId);

    // Test queueClear function
    queueClear(&queue);

    // Display the final state of the queue
    printf("Final state of the queue:\n");
    // Add code to display the contents of the queue if needed

    return 0;
}
