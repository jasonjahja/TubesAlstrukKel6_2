#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "ADT/list/list.h"
#include "ADT/listdin/listdin.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinbaris/mesinbaris.h"
#include "ADT/queue/queue.h"
#include "ADT/set/set.h"
#include "ADT/map/map.h"
#include "ADT/stack/stack.h"
#include "ADT/strukturberkait/listberkait.h"

#include "Spesifikasi/Inisialisasi/Inisialisasi.h"
#include "Spesifikasi/Start/Start.h"
#include "Spesifikasi/Load/Load.h"
#include "Spesifikasi/List/List.h"
#include "Spesifikasi/Play/Play.h"
#include "Spesifikasi/Queue/Queue.h"
#include "Spesifikasi/Song/Song.h"
// #include "Spesifikasi/Playlist/Playlist.h"
#include "Spesifikasi/Status/Status.h"
#include "Spesifikasi/Save/Save.h"
#include "Spesifikasi/Help/help.h"

int main() {

    Word word_start = {"START", 5};
    Word word_load = {"LOAD", 4};
    Word word_list = {"LIST", 4};
    Word word_play = {"PLAY", 4};
    Word word_queue = {"QUEUE", 5};
    Word word_song = {"SONG", 4};
    Word word_playlist = {"PLAYLIST", 8};
    Word word_status = {"STATUS", 6};
    Word word_save = {"SAVE", 4};
    Word word_quit = {"QUIT", 4};
    Word word_help = {"HELP", 4};
    Word word_default = {"DEFAULT", 7};
    Word word_swap = {"SWAP", 4};
    Word word_remove = {"REMOVE", 6};
    Word word_clear = {"CLEAR", 5};
    Word word_next = {"NEXT", 4};
    Word word_previous = {"PREVIOUS", 8};
    Word word_create = {"CREATE", 6};
    Word word_add = {"ADD", 3};
    Word word_delete = {"DELETE", 6};
    Word word_album = {"ALBUM", 5};

    songHistory SH; CreateEmptyStack(&SH);
    CurrentStat CS; CreateEmptyCurrentStat(&CS);
    Queue Q; CreateEmptyQueue(&Q);
    ListofPenyanyi LP; LP = MakeList();
    ListofPlaylist LPl; LPl = CreateListPlaylist();

    Inisialisasi();

    boolean running = true;
    boolean started = false;

    while (running)
    {
        printf(">> "); 
        GetCommand();

        if (IsWordEq(currentWord, word_start)) {
            if (!started)
            {
                startConfig(&LP);          
                started = true;
            }   
            else
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_load)) {
            if (!started) {
                ADVCOMM();
                started = true;
                Load(&LP, currentWord, &started);
            } else {
                printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_list)) {
            ADVCOMM();
            if (IsWordEq(currentWord, word_default)) {
                // List();
            }
            else if (IsWordEq(currentWord, word_playlist)) {
                // List();
            }
            else
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_play)) {
            ADVCOMM();
            if (IsWordEq(currentWord, word_song)) {
                playSong(LP, &CS, &SH, &Q);
            }
            else if (IsWordEq(currentWord, word_playlist)) {
                playPlaylist(LPl, &CS, &SH, &Q);
            }
            else
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_queue)) {
            ADVCOMM();
            if (IsWordEq(currentWord, word_song)) {
                if (!started)
                {
                    printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                    ADVCOMM();
                }
                else
                {   
                    queueSong(LP, &Q);
                }  
            }
            else if (IsWordEq(currentWord, word_playlist)) {
                // queuePlaylist();
            }
            else if (IsWordEq(currentWord, word_swap)) {
                int id1 = WordtoNum(currentWord);
                ADVCOMM(); int id2 = WordtoNum(currentWord);
                queueSwap(&Q, id1, id2);
            }
            else if (IsWordEq(currentWord, word_remove)) {
                int id = WordtoNum(currentWord);
                queueRemove(&Q, id);
            }
            else if (IsWordEq(currentWord, word_clear)) {
                queueClear(&Q);
            }
            else
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_song)) {
            ADVCOMM();
            if (IsWordEq(currentWord, word_next)) {
                nextSong(&Q, &SH, &CS);
            }
            else if (IsWordEq(currentWord, word_previous)) {
                prevSong(&Q, &SH, &CS);
            }
            else
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_playlist)) {
            ADVCOMM();
            if (IsWordEq(currentWord, word_create)) {
                // Song();
            }
            else if (IsWordEq(currentWord, word_add)) {
                // List();
            }
            else if (IsWordEq(currentWord, word_swap)) {
                // List();
            }
            else if (IsWordEq(currentWord, word_remove)) {
                // List();
            }
            else if (IsWordEq(currentWord, word_delete)) {
                // List();
            }
            else
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
        }

        else if (IsWordEq(currentWord, word_status)) {
            Status(CS, Q);
        }

        else if (IsWordEq(currentWord, word_save)) {
            if (!started)
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n\n");
                ADVCOMM();
            }
            else
            {
                // SaveFile(&LP,&AP, &QL, &RL, CCommand.TabLine);
            }
        }

        else if (IsWordEq(currentWord, word_quit)) {
            printf("\nLogged Out!\n\n");
            running = false;
        }

        else if (IsWordEq(currentWord, word_help)) {
            Help(started);
        }

        else {
            printf("Command tidak diketahui!\n\n");
        }
    }
    return 0;
}