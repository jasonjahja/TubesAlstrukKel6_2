/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

#ifndef ADTqueue
#define ADTqueue

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../set/set.h"

#define IDX_UNDEFQueue -1
#define IDX_MAXQueue 99

/* Definisi tipe elemen dan indeks pada Queue */
typedef struct {
        Word song[IDX_MAXQueue+1];
        Word album[IDX_MAXQueue+1];
        Word singer[IDX_MAXQueue+1];
        int idxHead;
        int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEADSONG(q) (q).song[(q).idxHead]
#define HEADALBUM(q) (q).album[(q).idxHead]
#define HEADSINGER(q) (q).singer[(q).idxHead]
#define TAILSONG(q) (q).song[(q).idxTail]
#define TAILALBUM(q) (q).album[(q).idxTail]
#define TAILSINGER(q) (q).singer[(q).idxTail]

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q);

boolean IsFullQueue (Queue Q);

int LengthQueue (Queue Q);

void CreateEmptyQueue (Queue * Q);

void enqueueQueue (Queue * Q, Word song, Word album, Word singer);

Song dequeueQueue (Queue * Q);

void displayQueue(Queue q);

#endif