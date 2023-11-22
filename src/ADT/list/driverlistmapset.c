#include <stdio.h>
#include "list.h"

int main() {
    // Create instances of Penyanyi, Album, and SetofSong
    ListofPenyanyi listPenyanyi = MakeList();
    MapofAlbum mapAlbum = CreateEmptyAlbum();
    SetofSong setLagu = CreateEmptySet();

    // Add data to Penyanyi
    Penyanyi penyanyi1, penyanyi2;
    penyanyi1.namaPenyanyi = toKata("Adele");
    penyanyi2.namaPenyanyi = toKata("Ed Sheeran");

    AddPenyanyi(&listPenyanyi, penyanyi1.namaPenyanyi);
    AddPenyanyi(&listPenyanyi, penyanyi2.namaPenyanyi);

    // Add data to Album
    Album album1, album2;
    album1.namaAlbum = toKata("21");
    album2.namaAlbum = toKata("x");

    AddAlbum(&mapAlbum, album1.namaAlbum);
    AddAlbum(&mapAlbum, album2.namaAlbum);

    // Add data to SetofSong
    Word lagu1 = toKata("Rolling in the Deep");
    Word lagu2 = toKata("Someone Like You");

    AddLagu(&setLagu, lagu1);
    AddLagu(&setLagu, lagu2);

    // Display information
    printf("List of Penyanyi:\n");
    DisplayListPenyanyi(listPenyanyi);

    printf("\nList of Album:\n");
    DisplayListAlbum(mapAlbum);

    printf("\nList of Lagu:\n");
    DisplayListLagu(setLagu);

    return 0;
}