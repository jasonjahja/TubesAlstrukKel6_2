#include <stdio.h>
#include "Playlist.h"


void playlistCreate(ListofPlaylist *L){
    printf("\nMasukkan nama playlist yang ingin dibuat : ");
    STARTINPUT(stdin);
    InsertListPlaylist(L,currentInput);
    printf("\nPlaylist ");
    TulisWordNoNL(currentInput);
    printf(" berhasil dibuat!\n");
    printf("Silahkan \nmasukkan lagu - lagu artis terkini kesayangan Anda!\n");

}

void playlistAddSong(ListofPlaylist L,ListofPenyanyi LP){
    infoLagu lagu;
    printf("\nDaftar Penyanyi : \n");
    DisplayListPenyanyi(LP);
    printf("\nMasukkan Nama Penyanyi yang dipilih : ");


    STARTINPUT(stdin);
    Word penyanyi = currentInput;
    int IDPenyanyi = IndeksPenyanyi(LP,penyanyi);
    printf("Penyanyi >> ");
    TulisWord(penyanyi);
    printf("%d\n", penyanyi.Length);

    while (!isMemberPenyanyi(LP,penyanyi)){
        printf("Nama penyanyi tidak terdaftar!\n");
        printf("\nMasukkan nama penyanyi yang dipilih: ");
        STARTINPUT(stdin);
        penyanyi = currentInput;
        IDPenyanyi = IndeksPenyanyi(LP,penyanyi);
        printf("Penyanyi >> ");
        TulisWord(penyanyi);

    }
    if (isMemberPenyanyi(LP,penyanyi)){
        lagu.Lagu.penyanyi = currentInput;
        printf("\nDaftar Album oleh ");
        TulisWordNoNL(penyanyi);
        printf(" :\n");
        DisplayListAlbum(LP.listpenyanyi[IDPenyanyi].album);
        printf("\nMasukkan Judul Album yang dipilih : ");

        STARTINPUT(stdin);
        Word namaAlbum = currentInput;
        int IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum);
        // printf("Nama Album >> ");
        // TulisWord(namaAlbum);
        // printf("ID Album >> %d\n",IDAlbum);

        while (!IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
            printf("Nama album tidak terdaftar!\n");
            printf("\nMasukkan nama album yang dipilih: ");
            STARTINPUT(stdin);
            namaAlbum = currentInput;
            IDAlbum = IndeksAlbum(LP.listpenyanyi[IDPenyanyi].album, namaAlbum);
            // printf("Nama Album >> ");
            // TulisWord(namaAlbum);
        }

        if (IsMemberAlbum(LP.listpenyanyi[IDPenyanyi].album,namaAlbum)){
            lagu.Lagu.album = currentInput;
            printf("\nDaftar Lagu Album ");
            TulisWordNoNL(namaAlbum);
            printf(" oleh ");
            TulisWord(penyanyi);
            DisplayListLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu);

            printf("\nMasukkan ID lagu yang dipilih: ");
            STARTINPUT(stdin);
            int IDLagu = WordtoNum(currentInput)-1;
            // printf("vvvv\n");
            // TulisWord(currentInput);
            // printf("ID LAGU >> %d\n",IDLagu);
            // TulisWord(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul);
            Word judulLagu = IndeksSong(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,IDLagu);
            // printf("Judul Lagu >> ");
            // TulisWord(currentInput);
            // TulisWord(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul);
            while (!IsMemberLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul)){
                printf("ID Lagu tidak terdaftar!\n");
                printf("\nMasukkan ID lagu yang dipilih: ");
                STARTINPUT(stdin);
                
                IDLagu = WordtoNum(currentInput)-1;
                judulLagu = IndeksSong(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,IDLagu);
                // printf("Judul Lagu >> ");
                // TulisWord(judulLagu);
                // printf("============ ");
            }

            if (IsMemberLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul)){
                printf("Ada ga lagunya ? >>> %d\n",IsMemberLagu(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu,LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul));
                // printf("Panjang list playlist >> %d\n",);
                printf("Nama Lagu >>> ");
                TulisWord(LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul);
                lagu.Lagu.judul = LP.listpenyanyi[IDPenyanyi].album.listalbum[IDAlbum].listlagu.Lagu[IDLagu].judul;
                printf("Daftar Playlist Pengguna :\n");
                DisplayListPlaylist(&L);
                printf("\nMasukkan ID Playlist yang dipilih : ");
                STARTINPUT(stdin);
                // TulisWord(currentInput);
                int IDPlaylist = WordtoNum(currentInput)-1;
                Word namaPlaylist = GetListPlaylist(L,IDPlaylist);
                // TulisWord(namaPlaylist);
                // printf("ID PLAYLIST = %d\n",IDPlaylist);
                // printf("nama Playlist = ");
                // TulisWord(namaPlaylist);
                while (!isMemberListPlaylist(L,namaPlaylist)){
                    printf("ID Playlist tidak terdaftar!\n");
                    printf("\nMasukkan ID Playlist yang dipilih: ");
                    STARTINPUT(stdin);
                    IDPlaylist = WordtoNum(currentInput)-1;
                    namaPlaylist = GetListPlaylist(L,IDPlaylist);
                }
                if (isMemberListPlaylist(L,namaPlaylist)){
                    lagu.Lagu.status = 0;
                    InsVLast(&L.list[IDPlaylist],lagu);
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
                }

            }
        }


    }

}
// void playlistAddAlbum(ListofPlaylist *L,ListofPenyanyi LP);
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
void playlistDelete(ListofPlaylist *L){
    printf("Daftar Playlist Pengguna : \n");
    DisplayListPlaylist(L);

    printf("\nMasukkan ID Playlist yang dipilih : ");
    STARTINPUT(stdin);
    TulisWord(currentInput);
    int IDPlaylist = WordtoNum(currentInput);

    printf("%d\n",IDPlaylist);

    ElmtList *curr = L->list->First;
    ElmtList *prev = NULL;

    for (int i = 0; i < IDPlaylist ; i++){
        prev = curr;
        curr = curr->next;
        TulisWord(curr->info.Lagu.judul);
    }

    if (prev != NULL){
        prev->next = curr->next;
    } else{
        L->list->First = curr->next;
    }
    Dealokasi(&curr);
    L->nEff--;
}

