#ifndef stack_H
#define stack_H

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"

#define Nil -1
#define MaxEl 100

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

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(songHistory S);
boolean IsFullStack(songHistory S);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(songHistory * S, Word song, Word album, Word singer);

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(songHistory * S, Word* song, Word* album, Word* singer);

void PrintStack(songHistory S);

#endif