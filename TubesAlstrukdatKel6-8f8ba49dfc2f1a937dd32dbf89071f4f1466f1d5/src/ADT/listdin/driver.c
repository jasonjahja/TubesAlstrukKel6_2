#include <stdio.h>
#include "listdin.h"

int main() {
    // Create a list of playlists
    ListofPlaylist playlistCollection = CreateListPlaylist();

    // Insert playlists into the collection
    InsertListPlaylist(&playlistCollection, toKata("Playlist1"));
    InsertListPlaylist(&playlistCollection, toKata("Playlist2"));
    printf("^^^^^^^^^^^^^^^^^^^ 1ST STEP ^^^^^^^^^^^^^^^^^^^^^^^\n");

    // Display the list of playlists
    printf("List of Playlists:\n");
    DisplayListPlaylist(&playlistCollection);
    printf("^^^^^^^^^^^^^^^^^^^ 2ND STEP ^^^^^^^^^^^^^^^^^^^^^^^\n");

    // Check if a playlist is a member of the collection
    Word searchPlaylist = toKata("Playlist2");
    if (isMemberListPlaylist(playlistCollection, searchPlaylist)) {
        printf("this playlist is in the collection : ");
        TulisWord(searchPlaylist);
        printf("\n");
    } else {
        printf("this playlist isn't in the collection : ");
        TulisWord(searchPlaylist);
        printf("\n");
    }

    printf("^^^^^^^^^^^^^^^^^^^ 3RD STEP ^^^^^^^^^^^^^^^^^^^^^^^\n");

    // Get the index of a playlist in the collection
    int index = IndexListPlaylist(playlistCollection, searchPlaylist);
    if (index >= 0) {
        TulisWord(searchPlaylist);
        printf(" is at index %d in the collection.\n", index);
    } else {
        TulisWord(searchPlaylist);
        printf(" %s is not found in the collection.\n");
    }

    printf("^^^^^^^^^^^^^^^^^^^ 4TH STEP ^^^^^^^^^^^^^^^^^^^^^^^\n");

    // Delete a playlist from the collection
    Word deletedPlaylist;
    deletedPlaylist = toKata("Playlist1");
    DeleteListPlaylist(&playlistCollection, deletedPlaylist);
    printf("Deleted Playlist: ");
    TulisWord(deletedPlaylist);
    printf("\n");

    printf("^^^^^^^^^^^^^^^^^^^ 5TH STEP ^^^^^^^^^^^^^^^^^^^^^^^\n");

    // Display the updated list of playlists
    printf("Updated List of Playlists:\n");
    DisplayListPlaylist(&playlistCollection);

    printf("^^^^^^^^^^^^^^^^^^^ 6TH STEP ^^^^^^^^^^^^^^^^^^^^^^^\n");

    return 0;
}