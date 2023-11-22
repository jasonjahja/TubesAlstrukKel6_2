/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include <stdio.h>
#include "../../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"

#define NMax 100
#define BLANK ' '
#define NewLine '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean endWord;
extern Word currentWord;

void IgnoreBlanks();

void STARTWORD(FILE* input);

void ADVWORD();

void CopyWord();

boolean isEndWord();

void GetCommand();

void IgnoreNewLine();

void CopyWordToVar(Word *kata1, Word kata2);

void TulisWord(Word kata);

void TulisWordNoNL(Word kata);

boolean IsWordEq (Word kata1, Word kata2);

int WordtoNum (Word kata);

void ResetWord();

void RemoveNewLine(char *str);

Word toKata(char *str); 
/*  Fungsi yang menerima sebuah paramater str bertipe string
    Kemudian mengembalikan elemen bertipe Word yang merupakan hasil transformasi string str */

Word intToWord(int n);

void IgnoreTK();

int stringLength(char *str);
/*  Fungsi yang menerima sebuah parameter str bertipe string
    Kemudian mengembalikan panjang dari string tersebut */

#endif
