#include <stdio.h>
#include "mesinkata.h"  // Gantilah "mesinkata.h" dengan nama file header yang sesuai
#include "../mesinbaris/mesinbaris.h"

int main() {
    FILE *input;
    Word command;

    // Buka file untuk dibaca
    input = fopen("../../../save/input.txt", "r");

    if (input == NULL) {
        printf("Error: Tidak dapat membuka file input.txt\n");
        return 1;
    }

    // Inisialisasi
    endWord = false;
    currentWord.Length = 0;
    currentLine.lengthsentence = 0;

    //Baca dan tampilkan kata dari file input
    STARTWORD(input);
    while (!endWord) {
        TulisWord(currentWord);
        ADVWORD();
        break;
    }

    // Reset kalimat dan tampilkan setelah reset
    //ResetKalimat();
    printf("Setelah ResetKalimat(): ");
    TulisWord(currentWord);
    ResetKalimat();
    printf("Setelah ResetKalimat(): ");
    TulisWord(currentWord);

    // Lakukan proses ADVWORD setelah reset dan tampilkan
    printf("ADVWORD setelah ResetKalimat(): ");
    ADVWORD();
    TulisWord(currentWord);

    // Lakukan proses ADVWORD setelah reset dan tampilkan
    printf("ADVWORD setelah ResetKalimat(): ");
    ADVWORD();
    TulisWord(currentWord);

    // // Lakukan proses ADVWORD setelah reset dan tampilkan
    // printf("ADVWORD setelah ResetKalimat(): ");
    // ADVWORD();
    // TulisWord(currentWord);

    // Uji fungsi AccessCommand dan tampilkan hasilnya
    // command = AccessWord(toKata("Hello World!"), 1);
    // printf("AccessWord(toKata(\"Hello World!\"), 1): ");
    // TulisWord(command);

    // Uji fungsi CopyWordToVar dan tampilkan hasilnya
    // Word destination;
    // CopyWordToVar(&destination, toKata("Copy this!"));
    // printf("CopyWordToVar(&destination, toKata(\"Copy this!\")): ");
    // TulisWord(destination);

    // Uji fungsi WordtoNum dan tampilkan hasilnya
    int num = WordtoNum(toKata("12345"));
    printf("WordtoNum(toKata(\"12345\")): %d\n", num);

    // Tutup file
    fclose(input);

    return 0;
}