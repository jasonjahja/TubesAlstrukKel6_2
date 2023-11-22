#ifndef __Playlist_H__
#define __Playlist_H__

#include "../../boolean.h"
#include "../../ADT/strukturberkait/listberkait.h"
#include "../../ADT/listdin/listdin.h"
#include "../../ADT/mesinbaris/mesinbaris.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/list/list.h"
#include "../../ADT/map/map.h"
#include "../../ADT//set/set.h"

void playlistCreate(ListofPlaylist *L);
void playlistAdd(ListBerkait *L);
void playlistSwap(ListBerkait *L);
void playlistRemove(ListBerkait *L);
void playlistDelete(ListBerkait *L);



#endif