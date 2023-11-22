#ifndef stack_H
#define stack_H

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"

#define MaxEl 100
#define Nil -1
/* Nil adalah stack dengan elemen kosong */

typedef struct { 
  Word song[MaxEl]; 
  Word album[MaxEl]; 
  Word singer[MaxEl]; 
  int TOP; 
} songHistory;

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTopSong(S) (S).song[(S).TOP]
#define InfoTopAlbum(S) (S).album[(S).TOP]
#define InfoTopSinger(S) (S).singer[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(songHistory *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(songHistory S);
/* Mengirim true jika songHistory S kosong: TOP bernilai NIL */

boolean IsFullStack(songHistory S);
/* Mengirim true jika tabel penampung nilai elemen songHistory penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(songHistory * S, Word song, Word album, Word singer);
/* Menambahkan song, album, dan singer sebagai elemen songHistory S. */
/* I.S. S mungkin kosong, tabel penampung elemen songHistory TIDAK penuh */
/* F.S. song,album,dan singer menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(songHistory * S, Word* song, Word* album, Word* singer);
/* Menghapus song, album, dan singer dari songHistory S. */
/* I.S. S tidak mungkin kosong */
/* F.S. song, album, dan singer adalah elemen TOP yang lama, TOP berkurang 1 */

/* *** Display songHistory *** */
void PrintStack(songHistory S);
/* Proses : Menuliskan isi singHistory dengan traversal dan ditulis di antara kurung 
   siku; masing-masing elemen memiliki song, album, dan singer yang dimasukkan kedalam kurung
   kurawal {song,album,singer}. Antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. S boleh kosong */
/* F.S. Jika S tidak kosong: [{song1,album1,singer1},{song2,album2,singer2},...,{songn,albumn,singern}] */
/* Jika S kosong: []*/


#endif