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
    Song CS; CS.status = 0;

    // inisialisasi

    boolean running = true;
    boolean started = false;

    while (running)
    {
        printf(">> "); GetCommand();
        

        if (isInputEqual(currentLine, word_start)) {
            if (!started)
            {
                // Start(); komen bentar
                // startConfig();             
                started = true;
            }   
            else
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n");
            }
        }

        else if (isInputEqual(currentLine, word_load)) {
            if (!started) {
                ADVCOMM();
                // Load(currentLine);
                started = true;
            } else {
                printf("ERROR: Command tidak dapat dieksekusi!\n");
            }
        }

        else if (isInputEqual(currentLine, word_list)) {
            ADVCOMM();
            if (isInputEqual(currentLine, word_default)) {
                // List();
            }

            else if (isInputEqual(currentLine, word_playlist)) {
                // List();
            }
        }

        else if (isInputEqual(currentLine, word_play)) {
            ADVCOMM();
            if (isInputEqual(currentLine, word_song)) {
                // Song();
            }
            
            else if (isInputEqual(currentLine, word_playlist)) {
                // List();
            }
        }

        else if (isInputEqual(currentLine, word_queue)) {
            ADVCOMM();
            if (isInputEqual(currentLine, word_song)) {
                if (!started)
                {
                    printf("ERROR: Command tidak dapat dieksekusi!\n");
                }
                else
                {   
                    // QueueAddLagu(&LP, &QL, &CS);
                }  
            }
            
            else if (isInputEqual(currentLine, word_playlist)) {
                // List();
            }

            else if (isInputEqual(currentLine, word_swap)) {
                // List();
            }

            else if (isInputEqual(currentLine, word_remove)) {
                // List();
            }

            else if (isInputEqual(currentLine, word_clear)) {
                // List();
            }
        }

        else if (isInputEqual(currentLine, word_song)) {
            ADVCOMM();
            if (isInputEqual(currentLine, word_next)) {
                // List();
            }

            else if (isInputEqual(currentLine, word_previous)) {
                // List();
            }
        }

        else if (isInputEqual(currentLine, word_playlist)) {
            ADVCOMM();
            if (isInputEqual(currentLine, word_create)) {
                // Song();
            }
            
            else if (isInputEqual(currentLine, word_add)) {
                // List();
            }

            else if (isInputEqual(currentLine, word_swap)) {
                // List();
            }

            else if (isInputEqual(currentLine, word_remove)) {
                // List();
            }

            else if (isInputEqual(currentLine, word_delete)) {
                // List();
            }
        }

        else if (isInputEqual(currentLine, word_status)) {
            // List();
        }

        else if (isInputEqual(currentLine, word_save)) {
            if (!started)
            {
                printf("ERROR: Command tidak dapat dieksekusi!\n");
            }
            else
            {
                // SaveFile(&LP,&AP, &QL, &RL, CCommand.TabLine);
            }
        }

        else if (isInputEqual(currentLine, word_quit)) {
            printf("Logged Out!\n");
            running = false;
        }

        else if (isInputEqual(currentLine, word_help)) {
            Help(started);
        }
    }
    return 0;
}