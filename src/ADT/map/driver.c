#include <stdio.h>
#include "map.h"

int main() {
    MapofAlbum albumCollection = CreateEmptyAlbum();
    Word albumName;

    printf("--------ALBUM COLLECTION APPLICATION--------\n");

    // Add albums to the collection
    printf("Adding albums to the collection...\n");
    AddAlbum(&albumCollection, toKata("Album1"));
    AddAlbum(&albumCollection, toKata("Album2"));
    AddAlbum(&albumCollection, toKata("Album3"));

    // Display the list of albums
    printf("\nCurrent Album Collection:\n");
    DisplayListAlbum(albumCollection);

    // Check if a specific album is in the collection
    albumName = toKata("Album2");
    if (IsMemberAlbum(albumCollection, albumName)) {
        printf("\n%s is in the album collection.\n", albumName.TabWord);
    } else {
        printf("\n%s is not in the album collection.\n", albumName.TabWord);
    }

    // Add another album to the collection
    printf("\nAdding another album to the collection...\n");
    AddAlbum(&albumCollection, toKata("Album4"));

    // Display the updated list of albums
    printf("\nUpdated Album Collection:\n");
    DisplayListAlbum(albumCollection);

    // Check again if a specific album is in the updated collection
    albumName = toKata("Album3");
    if (IsMemberAlbum(albumCollection, albumName)) {
        printf("\n%s is in the album collection.\n", albumName.TabWord);
    } else {
        printf("\n%s is not in the album collection.\n", albumName.TabWord);
    }

    printf("\n--------END OF APPLICATION--------\n");

    return 0;
}