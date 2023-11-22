#include <stdio.h>
#include "mesinbaris.c"
#include "../mesinkata/mesinkata.c"
#include "../mesinkarakter/mesinkarakter.c"

static FILE *pita;


int main(){

    pita = fopen("filedrivermesinbaris.txt","r");
    if (pita == NULL){
        printf("Gagal membuka file\n");
        return 1;
    }

    STARTFILE(pita);
    TulisWord(toKata(currentLine.kalimat));
    int jumlahpenyanyi = atoi(currentLine.kalimat);    
    for(int i = 0 ;i < jumlahpenyanyi;i++){
        ADVWORD();
        // TulisWord(toKata(currentLine.kalimat));
        // TulisKalimat(currentLine);
        int jumlahAlbum = WordtoNum(currentWord);

        // printf("jumlah album -> %d ",jumlahAlbum);
        TulisWord(currentWord);
        ADVSENTENCE();
        TulisKalimat(currentLine);
        
      
        for (int j = 0; j<jumlahAlbum;j++){
            ADVWORD();
            int banyakLagu = WordtoNum(currentWord);

            TulisWord(currentWord); 
            ADVSENTENCE();
            

            TulisKalimat(currentLine);
   
            for(int k = 0; k<banyakLagu;k++){
                ADVSENTENCE();
                TulisKalimat(currentLine);

            }
            
        }

    }
    
    fclose(pita);
    return 0;
}