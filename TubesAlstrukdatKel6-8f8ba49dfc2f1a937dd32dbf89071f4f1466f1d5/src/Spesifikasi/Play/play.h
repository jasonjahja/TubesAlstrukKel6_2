#ifndef Play_H
#define Play_H

#include "../../boolean.h"
#include "../../ADT/mesinbaris/mesinbaris.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/set/set.h"
#include "../../ADT/map/map.h"
#include "../../ADT/list/list.h"
#include "../../ADT/stack/stack.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/listdin/listdin.h"
#include "../../ADT/strukturberkait/listberkait.h"

typedef struct
{ 
    Song currentplay;
    Word playlist;
    int statusPL;
} CurrentStat;

void CreateEmptyCurrentStat (CurrentStat *current);

void playSong (ListofPenyanyi daftarpenyanyi, CurrentStat * currentStat, songHistory * history, Queue * queue);

void playPlaylist(ListofPlaylist daftarplaylist, CurrentStat * CurrentStat, songHistory * history, Queue * queue);

#endif