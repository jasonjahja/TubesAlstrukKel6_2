#include <stdio.h>
#include "mesinbaris.h"

boolean endLine;
boolean EndSentence;

Sentence currentInput;
Sentence currentLine;
Sentence currentInput;

void STARTFILE(FILE* input)
{
    START(input);
    IgnoreNewLine();
    if (currentChar == '\0')
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyLine();
    }
}
void STARTINPCOMMAND(FILE* input)
{
    START(input);
    IgnoreNewLine();
    if (currentChar == ';')
    {
        EndSentence = true;
    }
    else
    {
        EndSentence = false;
        CopyCommand();
    }
}

void STARTINPUT(FILE* input)
{
    START(input);
    IgnoreNewLine();
    if (currentChar == ';')
    {
        EndSentence = true;
    }
    else
    {
        EndSentence = false;
        CopyLine();
    }
}

void CopyInput()
{
    ResetCommand();  // Reset array
    int i = 0;
    while ((currentChar != ';') && (currentChar != '\n') && (currentChar != EOF))
    {
        currentInput.kalimat[i] = currentChar;
        // printf("%c", CC);
        i++;
        ADV();
        
    }
    currentInput.lengthsentence = i;
}

// Cmment dulu yak gan
// void STARTKALIMAT(FILE* input)
// {
//     START(input);
//     IgnoreBlanks();


//     if (currentChar == '\0')
//     {
//         EndSentence = true;
//     }
//     else
//     {
//         EndSentence = false;
//         CopyWord();
//     }
// }


//komen dulu yak
// void CopyLine()
// {
//     ResetKalimat();
//     currentLine.lengthsentence = 0;
//     while ((currentChar != NewLine) && (currentChar != EOF))
//     {
//         if (currentLine.lengthsentence < Nmax)
//         { // jika lebih akan terpotong
//             currentLine.kalimat[currentLine.lengthsentence++] = currentWord;
//             ADVWORD();
//         }
//         else
//             break;
//     }
// }

void ResetCommand() { // dibenerin 
    for (int i = 0; i < sizeof(currentLine.kalimat) ; i++) {
        currentLine.kalimat[i] = '\0';
        currentLine.lengthsentence = 0;
    }
}


void ResetInput(){
    for (int i = 0; i < sizeof(currentInput.kalimat) ; i++) {
        currentInput.kalimat[i] = '\0';
        currentInput.lengthsentence = 0;
    }
}

void CopyCommand() {
    ResetCommand();  // Reset array
    int i = 0;
    while ((currentChar != ';') && (currentChar != ' ') && (currentChar != EOF))
    {
        currentLine.kalimat[i] = currentChar;
        // printf("%c", CC);
        i++;
        ADV();
        
    }
    currentLine.lengthsentence = i;
}

void CopyLine() {
    ResetKalimat();  // Reset array
    int i = 0;
    while ((currentChar != '\n') && (currentChar != ';') && (currentChar != EOF))
    {
        currentLine.kalimat[i] = currentChar;
        // printf("%c", CC);
        i+= 1;
        ADV();
        
    }
    currentLine.lengthsentence = i;
}

void ADVCOMM() {
    IgnoreBlanks();
    if (currentChar != ';')
    {
        endLine = false;
        CopyCommand();
    } 
    else
    {
        endLine = true;
    }
}

void ADVLINE()
{
    IgnoreBlanks();
    if (currentChar != '\n')
    {
        endLine = false;
        CopyLine();
    } 
    else
    {
        endLine = true;
    }
}

void ADVSENTENCE(){
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == '\n'){
        EndSentence = true;
    } 
    else
    {
        EndSentence = false;
        CopyLine();
    }
}

void ADVRECORD() {
    IgnoreBlanks();
    IgnoreNewLine();
    IgnoreTK();
    if (currentChar == ';') {
        EndSentence = true;
    }
    else {
        EndSentence = false;
        CopyLine();
    }
}

void GetCommand()
{
    currentLine.lengthsentence = 0;
    STARTINPCOMMAND(stdin);
}
    // STARTLINE(stdin); << awalnya

void GetInput()
{
    currentInput.lengthsentence = 0;
    STARTINPUT(stdin);
}

// nambah fungsi TulisKalimat
void TulisKalimat(Sentence currentLine) {
    for (int i = 0; i < currentLine.lengthsentence; i++) {
        if (currentLine.kalimat[i]!= '\n'){
            printf("%c", currentLine.kalimat[i]);
        }
    }
    printf("\n");
}

boolean isInputEqual(Sentence Input, Word Kata)
{   
    boolean equal = true;
    if (Input.lengthsentence == Kata.Length)
    {
        int i = 0;
        while (i < Input.lengthsentence && equal)
        {
            if (Input.kalimat[i] != Kata.TabWord[i])
            {
                equal = false;
            }
            else
            {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

void ResetKalimat(){ // dibenerin 
    int i;
    currentWord.Length = 0;
    currentLine.lengthsentence = 0;
    
    for (i = 0; i < NMax ; i++)
    {
        currentWord.TabWord[i] = '\0';
        currentLine.kalimat[i] = '\0';
    }
}

// Word AccessCommand(Sentence baris, int Idx)
// {
//     int count = 0, i = 0;
//     Word out;
//     out.Length = 0;

//     while (i < comm.lengthsentence && count <= Idx) {
//         out = comm.kalimat[i];
//         if (comm.TabWord[i] != ' ') {
//             out.Length++;
//         }
//         if (comm.TabWord[i] == ' ') {
//             if (count < Idx) {
//                 out.Length = 0;
//             }
//             count++;
//         }
//         i++;
//     }
//     return out;
// }

//komen dulu, ga ada di header
// boolean isEndLine() 
// {
//     return endLine;
// }

// Sentence tokalimat (Sentence kata)
// {
//     Sentence kalimat;
//     kalimat.lengthsentence = SentenceLength(kata);

//     for (int i = 0; i < kalimat.lengthsentence; i++)
//     {
//         kalimat.kalimat[i] = kata.kalimat[i];
//     }
//     return kalimat;
// }

// int SentenceLength(Sentence kata) {
// /*  Fungsi yang menerima sebuah parameter str bertipe string
//     Kemudian mengembalikan panjang dari string tersebut */
//     int len = 1;
//     int i = 0;
//     while (kata.kalimat[i].TabWord != '\0') 
//     {
//         if (currentChar == BLANK)
//         {
//             len++;
//         }
//         i++;
//     }
//     return len;
// }  