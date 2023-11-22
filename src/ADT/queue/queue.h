#ifndef ADTqueue_H
#define ADTqueue_H

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
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead = IDX_UNDEFQueue dan idxTail = IDX_UNDEFQueue */

boolean IsFullQueue (Queue Q);
/* Mengirim true jika tabel penampung elemen-elemen Q sudah penuh */
/* yaitu ketika IDX_HEAD=0 dan IDX_TAIL=CAPACITY-1 */

int LengthQueue (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

void CreateEmptyQueue (Queue * Q);
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan idxHead dan idxTail bernilai IDX_UNDEFQueue */

/* *** Primitif Add/Delete *** */
void enqueueQueue (Queue * Q, Word song, Word album, Word singer);
/* Proses: Menambahkan elemen song, album, dan singer pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. song, album, dan singer menjadi elemen pada TAIL yang baru, idxTail "mundur".*/

Song dequeueQueue (Queue * Q);
/* Menghapus elemen HEAD pada queue sesuai aturan FIFO */
/* Mengembalikan elemen HEAD tersebut dengan tipe data Song */
/* Semua elemen disebelah kanan digeser agar rata kiri, idxTail "maju" */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; masing-masing elemen memiliki song, album, dan singer yang dimasukkan kedalam kurung
   kurawal {song,album,singer}. Antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [{song1,album1,singer1},{song2,album2,singer2},...,{songn,albumn,singern}] */
/* Jika q kosong: []*/

#endif