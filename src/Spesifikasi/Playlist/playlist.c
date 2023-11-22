#include <stdio.h>
#include "playlist.h"
#include "../../Spesifikasi/Start/Start.c"
#include "../../ADT/listdin/listdin.c"
#include "../../ADT/strukturberkait/listberkait.c"
#include "../../ADT/mesinbaris/mesinbaris.c"
#include "../../ADT/mesinkata/mesinkata.c"
#include "../../ADT/mesinkarakter/mesinkarakter.c"
#include "../../ADT/list/list.c"
#include "../../ADT/map/map.c"
#include "../../ADT/set/set.c"


void playlistCreate(ListofPlaylist *L){
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTINPUT(stdin);
    InsertListPlaylist(L,toKata(currentLine.kalimat));
    printf("\nPlaylist ");
    TulisWordNoNL(toKata(currentLine.kalimat));
    printf(" berhasil dibuat!\n");
    printf("Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");

}

void playlistAddSong(ListofPlaylist L,ListofPenyanyi LP){
    infoLagu lagu;
    printf("\nDaftar Penyanyi : \n");
    DisplayListPenyanyi(LP);
    printf("Masukkan Nama Penyanyi yang dipilih : ");


    STARTINPUT(stdin);
    Word penyanyi = toKata(currentLine.kalimat);
    int IDPenyanyi = IndeksPenyanyi(LP,penyanyi);
    // printf("Penyanyi >> ");
    // TulisWord(penyanyi);
    // printf("ID PENYANYI >> %d\n",IDPenyanyi);

    while (!isMemberPenyanyi(LP,penyanyi)){
        printf("Nama penyanyi tidak terdaftar!\n");
        printf("Masukkan nama penyanyi yang dipilih: ");
        STARTINPUT(stdin);
        penyanyi = toKata(currentLine.kalimat);
        IDPenyanyi = IndeksPenyanyi(LP,penyanyi);
        printf("Penyanyi >> ");
        TulisWord(penyanyi);

    }
    if (isMemberPenyanyi(LP,penyanyi)){
        lagu.Lagu.penyanyi = toKata(currentLine.kalimat);
        printf("\nDaftar Album oleh ");
        TulisWordNoNL(penyanyi);
        printf(" :\n");
        printf("ID Penyanyi = %d\n",IDPenyanyi);
        DisplayListAlbum(LP.listpenyanyi[IDPenyanyi].album);
        printf("\nMasukkan Judul Album yang dipilih : ");

        STARTINPUT(stdin);
        Word namaAlbum = toKata(currentLine.kalimat);
        int IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum);
        printf("Nama Album >> ");
        TulisWord(namaAlbum);
        printf("ID Album >> %d\n",IDAlbum);

        while (!IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
            printf("Nama album tidak terdaftar!\n");
            printf("Masukkan nama album yang dipilih: ");
            STARTINPUT(stdin);
            namaAlbum = toKata(currentLine.kalimat);
            IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album, namaAlbum);
            printf("Nama Album >> ");
            TulisWord(namaAlbum);
        }

        if (IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
            lagu.Lagu.album = toKata(currentLine.kalimat);
            printf("\nDaftar Lagu Album ");
            TulisWordNoNL(namaAlbum);
            printf(" oleh ");
            TulisWord(penyanyi);
            DisplayListLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu);

            printf("Masukkan ID lagu yang dipilih: ");
            STARTINPUT(stdin);
            int IDLagu = WordtoNum(toKata(currentLine.kalimat))-1;
            // printf("vvvv\n");
            // TulisWord(toKata(currentLine.kalimat));
            // printf("ID LAGU >> %d\n",IDLagu);
            // TulisWord(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul);
            Word judulLagu = IndeksSong(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,IDLagu);
            // printf("Judul Lagu >> ");
            // TulisWord(toKata(currentLine.kalimat));
            // TulisWord(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul);
            while (!IsMemberLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul)){
                printf("ID Lagu tidak terdaftar!\n");
                printf("Masukkan ID lagu yang dipilih: ");
                STARTINPUT(stdin);
                
                judulLagu = toKata(currentLine.kalimat);
                IDLagu = WordtoNum(toKata(currentLine.kalimat))-1;
                // printf("Judul Lagu >> ");
                // TulisWord(judulLagu);
                // printf("============ ");
            }

            if (IsMemberLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul)){
                lagu.Lagu.judul = toKata(currentLine.kalimat);
                printf("Daftar Playlist Pengguna :\n");
                DisplayListPlaylist(&L);
                printf("Masukkan ID Playlist yang dipilih : ");
                STARTINPUT(stdin);
                // TulisWord(toKata(currentLine.kalimat));
                int IDPlaylist = WordtoNum(toKata(currentLine.kalimat))-1;
                Word namaPlaylist = GetListPlaylist(L,IDPlaylist);
                // TulisWord(namaPlaylist);
                // printf("ID PLAYLIST = %d\n",IDPlaylist);
                // printf("nama Playlist = ");
                // TulisWord(namaPlaylist);
                while (!isMemberListPlaylist(L,namaPlaylist)){
                    printf("ID Playlist tidak terdaftar!\n");
                    printf("Masukkan ID Playlist yang dipilih: ");
                    STARTINPUT(stdin);
                    namaPlaylist = toKata(currentLine.kalimat);
                    // TulisWord(namaPlaylist);
                    IDPlaylist = WordtoNum(toKata(currentLine.kalimat))-1;
                }
                if (isMemberListPlaylist(L,namaPlaylist)){
                    lagu.Lagu.status = 0;
                    InsVLast(L.list,lagu);
                    printf("Lagu dengan judul ");
                    printf("'");
                    TulisWordNoNL(judulLagu);
                    printf("'");
                    printf(" pada album ");
                    TulisWordNoNL(namaAlbum);
                    printf(" oleh penyanyi ");
                    TulisWordNoNL(penyanyi);
                    printf(" berhasil ditambahkan ke dalam playlist ");
                    TulisWordNoNL(namaPlaylist);
                    printf(".\n");
                    // DisplayListPlaylist(&L);

                }

            }
        }


    }

}
void playlistAddAlbum(ListofPlaylist *L,ListofPenyanyi LP);
void playlistSwap(ListofPlaylist *L,int idx,int x,int y){
    ElmtList *p1  =L->list[idx].First; 
    ElmtList *p2  =L->list[idx].First;

    for (int i = 0; i < x;i ++){
        p1 = p1->next;
    }
    for (int i = 0; i < y;i ++){
        p2 = p2->next;
    }

    Song temp = p1->info.Lagu;
    p1->info.Lagu = p2->info.Lagu;
    p2->info.Lagu = temp;

    printf("Berhasil menukar lagu dengan nama '");
    TulisWordNoNL(p1->info.Lagu.judul);
    printf("' dengan '");
    TulisWordNoNL(p2->info.Lagu.judul);
    printf("' di playlist '");
    TulisWordNoNL(*(L->namaPlaylist));
    printf("'.\n");

}
void playlistRemove(ListofPlaylist *L,int rowsong,int idx){
    ElmtList *p = L->list[idx].First;
    ElmtList *prev = NULL;

    for (int i = 0;i <rowsong && p != NULL;i++){
        prev = p;
        p =p->next;
    }
    if (prev == NULL){
        L->list[idx].First = p->next;
    } else{
        prev->next = p->next;
    }
    Dealokasi(&p);


}
void playlistDelete(ListofPlaylist *L,int idx){
    ElmtList *curr = L->list->First;
    ElmtList *prev = NULL;

    for (int i = 0; i < idx; i++){
        prev = curr;
        curr = curr->next;
    }

    if (prev != NULL){
        prev->next = curr->next;
    } else{
        L->list->First = curr->next;
    }
    Dealokasi(&curr);
    L->nEff--;
}

