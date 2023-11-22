#ifndef __MESINBARIS_H__
#define __MESINBARIS_H__

#include "../../boolean.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"
#include "../mesinbaris/mesinbaris.h"

#define NewLine '\n'
#define Nmax 50
typedef struct 
{
    char kalimat[Nmax];
    int lengthsentence;
} Sentence;

extern Sentence currentLine;
extern Sentence currentInput;

void STARTFILE(FILE* input);

void STARTINPCOMMAND(FILE* input);

void ResetCommand();

void ADVCOMM();

void ADVLINE();

void ADVSENTENCE();

void ADVRECORD();

void GetCommand();

void TulisKalimat(Sentence currentLine);

void CopyCommand();

void CopyLine();

void STARTINPUT(FILE* input);

void CopyInput();

boolean isInputEqual(Sentence Input, Word Kata);

void ResetKalimat();

// Word AccessCommand(Sentence comm, int Idx);

Sentence tokalimat (Sentence kata);

int SentenceLength(Sentence kata);

#endif