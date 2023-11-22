#ifndef NEWSTRUCT_H
#define NEWSTRUCT_H

#include "../map/map.h"
#include "../queue/queue.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../list/list.h"
#include "../set/set.h"
// #include "../map/map.h"
// #include "../stack/stack.c"

typedef struct 
{
    Word namaPenyanyi;
    MapofAlbum Album;
} Penyanyi;

typedef struct 
{
    SetofSong playlist;
}Playlist;

typedef struct
{
    Queue Song;
    Playlist playlist;
} User;

typedef struct 
{
    SetofSong lagu;
    Penyanyi singer;
}Song;

#endif
