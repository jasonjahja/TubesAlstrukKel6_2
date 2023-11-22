#ifndef song_H
#define song_H

#include "../../boolean.h"
#include "../../ADT/queue/queue.h"
#include "../../ADT/stack/stack.h"
#include "../../ADT/map/map.h"
#include "../../ADT/list/list.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../Play/Play.h"

void nextSong(Queue *queue, songHistory *history, CurrentStat * currentSong);

void prevSong(Queue *queue, songHistory *history, CurrentStat * currentSong);

void enqueueFirstQueue (Queue * Q, Word song, Word album, Word singer);

#endif