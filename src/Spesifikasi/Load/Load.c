#include <stdio.h>
#include <stdlib.h>
#include "Load.h"

static FILE *pita;
Sentence currentLine;

void load() {

    ListofPenyanyi ListPenyanyi = MakeList();
    // Sentence namaPenyanyi;
    // Sentence namaAlbum;
    // Sentence namaLagu;


    pita = fopen("../../save/test.txt","r");
    if (pita == NULL){
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }

    (STARTFILE(pita));
    TulisKalimat(currentLine);
    int jumlahpenyanyi = atoi(currentLine.kalimat);
    // printf(" --> jumlah PENYANYI = %d\n",jumlahpenyanyi);    

    // printf("\n LOOP JUMLAH PENYANYI \n");    
    for(int i = 0;i < jumlahpenyanyi;i++) {
        ADVWORD();
        int jumlahAlbum = WordtoNum(currentWord);
        TulisWord(currentWord); // print jumlah album penyanyi

        ADVSENTENCE();
        TulisKalimat(currentLine); // print penyanyi
        AddPenyanyi(&ListPenyanyi, toKata(currentLine.kalimat));
        
        // di sini nanti penyanyi disimpen ke List
        // AddPenyanyi(&ListPenyanyi,currentLine.kalimat);

    
        // printf("\n LOOP JUMLAH ALBUM \n");    
        for (int j = 0; j<jumlahAlbum;j++) {
            ADVWORD();
            int banyakLagu = WordtoNum(currentWord);
            
            TulisWord(currentWord); // Jumlah lagu di satu album
            ADVSENTENCE();
            AddAlbum(&ListPenyanyi.listpenyanyi[i].album, toKata(currentLine.kalimat));

            TulisKalimat(currentLine); // Nama album

            // printf("DUARRRR!!!! = >>>");
            // di sini nanti masukin album ke Map
            // printf(" --> jumlah ALBUM = %d\n",jumlahAlbum);
            // printf("\n LOOP JUMLAH LAGU \n");    
            for(int k = 0; k<banyakLagu;k++) {
                ADVSENTENCE();
                // printf("lagu = %d\n",banyakLagu);
                TulisKalimat(currentLine);
                AddLagu(&ListPenyanyi.listpenyanyi[i].album.listalbum[j].listlagu, toKata(currentLine.kalimat));
                // printf(" --> jumlah LAGU = %d\n",banyakLagu);
                // di sini nanti lagu disimpen ke Set
                // InsertSet(&Lagu,currentWord);
            }
            
        }

    }
    // ADVSENTENCE();
    // DisplayListPenyanyi(ListPenyanyi);
    // printf("SELESAI\n");
    //printf("\nDUARRRR!!!! = >>>\n");

    ADVLINE(); //lanjut ke baris selanjutnya, ke lagu yang sedang dimainkan

    //CREATEEMPTYQUEUE();
    ADVRECORD();
    TulisKalimat(currentLine); //print lagu yang sedang dimainkan, penyanyi
    //Sentence namaPenyanyi = currenLine;

    ADVRECORD();
    TulisKalimat(currentLine); //print lagu yang sedang dimainkan, album
    //Sentence namaAlbum = currentLine;

    ADVRECORD();
    TulisKalimat(currentLine); //print lagu yang sedang dimainkan, lagu
    //Sentence namaLagu = currentLine;
    //enqueueQueue(INISIALISASIQUEUE, namaPenyanyi, namaAlbum, namaLagu);

    ADVWORD(); //lanjut ke baris selanjutnya

    int rQueue = WordtoNum(currentWord);

    //printf("\nJUMLAH RIWAYAT LAGU DALAM QUEUE:");
    TulisWord(currentWord); // print jumlah riwayat lagu dalam queue

    ADVLINE(); //lanjut ke baris selanjutnya, isi riwayat lagu dalam queue

    //printf("\nLOOP RIWAYAT LAGU:\n");
    for (int l = 0; l < rQueue; l++) {
        ADVRECORD();
        //Sentence namaPenyanyi = currentLine;
        TulisKalimat(currentLine);

        ADVRECORD();
        //Sentence namaAlbum = currentLine;
        TulisKalimat(currentLine);

        ADVRECORD();
        //Sentence namaLagu = currentLine;
        TulisKalimat(currentLine);

        //enqueueQueue(INISIALISASIQUEUE, namaPenyanyi, namaAlbum, namaLagu);

        ADVLINE(); //lanjut ke lagu selanjutnya yang isinya riwayat lagu dalam queue
        //printf("\n=====\n");
    }
    
    ADVWORD(); //lanjut ke baris jumlah record riwayat pemutaran lagu
    int rPemutarLagu = WordtoNum(currentWord);

    //printf("\nJUMLAH RECORD RIWAYAT PEMUTARAN LAGU:");
    TulisWord(currentWord); // print jumlah record riwayat pemutaran lagu

    ADVLINE(); //lanjut ke baris selanjutnya, isi riwayat pemutaran lagu

    //CREATEEMPTYSTACK();
    //printf("\nLOOP RECORD RIWAYAT PEMUTARAN LAGU:\n");
    for (int l = 0; l < rPemutarLagu; l++) {
        ADVRECORD();
        //Sentence namaPenyanyi = currentLine;
        TulisKalimat(currentLine);

        ADVRECORD();
        //Sentence namaAlbum = currentLine;
        TulisKalimat(currentLine);

        ADVRECORD();
        //Sentence namaLagu = currentLine;
        TulisKalimat(currentLine);

        //PushStack(INISIALISASISTACK, namaPenyanyi, namaAlbum, namaLagu);

        ADVLINE(); //lanjut ke baris selanjutnya
    }

    ADVWORD();
    int jPlaylist = WordtoNum(currentWord); //jumlah playlist
    //printf("\nLOOP JUMLAH PLAYLIST:");
    TulisWord(currentWord); //print jumlah playlist

    //CreateListDin();
    for (int l = 0; l < jPlaylist; l++) {
        ADVWORD();
        int jLagu = WordtoNum(currentWord); //jumlah lagu dalam playlist
        //printf("\nJUMLAH LAGU DALAM PLAYLIST:");
        TulisWord(currentWord); //print jumlah lagu dalam playlist

        ADVSENTENCE();
        TulisKalimat(currentLine); //print nama playlist
        //insertLast_ListDin(currentLine);

        ADVLINE();

        //CreateEmpty(); //createempty list berkait
        //printf("\nLOOP NAMA LAGU:\n");
        for (int l = 0; l < jLagu; l++) {
            //infoType Data
            ADVRECORD();
            //Data.namaPenyanyi = currentLine;
            TulisKalimat(currentLine);

            ADVRECORD();
            //Data.namaAlbum = currentLine;
            TulisKalimat(currentLine);

            ADVRECORD();
            //Data.namaLagu = currentLine;
            TulisKalimat(currentLine);
            //InsVLast();

            ADVLINE();
        }
    }
    fclose(pita);
}

// int main() {
//     load();
//     return 0;
// }


        // for (int a = 0; a < 3; a++) {
        //     ADVRECORD();
        //     TulisKalimat(currentLine); //agar print penyanyi;album;lagu dapat terpisah
        
        // }

            // for (int a = 0; a < 3; a++) {
            //     ADVRECORD();
            //     TulisKalimat(currentLine); //print nama nama lagu dalam playlist agar terpisah dari penyanyi;album;lagu
                
            // }