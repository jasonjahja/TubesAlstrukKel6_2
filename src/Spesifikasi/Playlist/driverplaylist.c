#include <stdio.h>
#include "playlist.c"

int main(){

    
    ///////////////////////////////LIST BERKAIT////////////////////////////
    ListBerkait playlistMarcell;

    CreateEmptyPlaylist(&playlistMarcell);

    

    //----------MASUKIN INFO LAGU KE DALAM LINKED LSIT
    infoLagu a = {toKata("Alstrukdat"),toKata("STI vs IF"),toKata("Jason"),0};
    infoLagu b = {toKata("cimahitypebeat"),toKata("STI"),toKata("Afnan"),0};
    infoLagu c = {toKata("PinkVenom"),toKata("BORN PINK"),toKata("BLACKPINk"),0};
    infoLagu d = {toKata("R U Mine?"),toKata("AM"),toKata("Arctic Monkeys"),0};
    infoLagu e = {toKata("Lagu untuk Dia"),toKata("Cibubur"),toKata("Marcell"),0};
    InsVFirst(&playlistMarcell,a);
    InsVLast(&playlistMarcell,b);
    InsVLast(&playlistMarcell,c);
    InsVLast(&playlistMarcell,d);
    InsVLast(&playlistMarcell,e);
    printf("\n==================playlistMarcell(banyak isi playlist = %d)=======\n",NbElmtListBerkait(playlistMarcell));
    PrintNode(playlistMarcell);
    printf("\n================================================================\n");

    printf("\n");
    //////////////////////////////////////////////////////////////////////

    ListofPlaylist kumpulanPlaylist = CreateListPlaylist();
    address p = kumpulanPlaylist.list->First;
    p = playlistMarcell.First;
    
    TulisWord(p->info.Lagu.album);
    TulisWord(p->info.Lagu.judul);
    TulisWord(p->info.Lagu.penyanyi);

    p = p->next;
    TulisWord(p->info.Lagu.album);
    TulisWord(p->info.Lagu.judul);
    TulisWord(p->info.Lagu.penyanyi);
    


    
    ListofPenyanyi LP = MakeList();
    InsertListPlaylist(&kumpulanPlaylist,toKata("Me"));
    InsertListPlaylist(&kumpulanPlaylist,toKata("Love"));
    InsertListPlaylist(&kumpulanPlaylist,toKata("Indo Koplo"));
    // tambahin penyanyi
    AddPenyanyi(&LP,toKata("John Mayer"));
    AddPenyanyi(&LP,toKata("NOSSTRESS"));
    AddPenyanyi(&LP,toKata("BLACKPINK"));

    // tambahin album
    // John Mayer
    AddAlbum(&LP.listpenyanyi[0].album,toKata("Continuum"));
    AddAlbum(&LP.listpenyanyi[0].album,toKata("The Search for Everything"));
    // Nosstress
    AddAlbum(&LP.listpenyanyi[1].album,toKata("Perspektif Bodoh"));
    AddAlbum(&LP.listpenyanyi[1].album,toKata("Ini Bukan Nosstress"));
    
    // BLACKPINK
    AddAlbum(&LP.listpenyanyi[2].album,toKata("BORN PINK"));

    //tambahin lagu
    //John Mayer.Continuum
    AddLagu(&LP.listpenyanyi[0].album.listalbum[0].listlagu,toKata("Gravity"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[0].listlagu,toKata("Slow Dancing in a Burning Room"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[0].listlagu,toKata("Belief"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[0].listlagu,toKata("The Heart of Life"));
    // DisplayListLagu(LP.listpenyanyi[0].album.listalbum[0].listlagu);
    //John Mayer.The Search for Everything
    
    AddLagu(&LP.listpenyanyi[0].album.listalbum[1].listlagu,toKata("Still Feel Like Your Man"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[1].listlagu,toKata("In The Blood"));
    AddLagu(&LP.listpenyanyi[0].album.listalbum[1].listlagu,toKata("Moving On and Getting Over"));
    // DisplayListLagu(LP.listpenyanyi[0].album.listalbum[1].listlagu);
    //Nosstress.Perspektif Bodoh
    
    AddLagu(&LP.listpenyanyi[1].album.listalbum[0].listlagu,toKata("Pegang Tanganku"));
    AddLagu(&LP.listpenyanyi[1].album.listalbum[0].listlagu,toKata("Laguku Untukmu"));
    // DisplayListLagu(LP.listpenyanyi[1].album.listalbum[0].listlagu);
    //Nosstress.Ini Bukan Nosstress
    
    AddLagu(&LP.listpenyanyi[1].album.listalbum[1].listlagu,toKata("Semoga Ya"));
    AddLagu(&LP.listpenyanyi[1].album.listalbum[1].listlagu,toKata("Ya, Kamu"));
    // DisplayListLagu(LP.listpenyanyi[1].album.listalbum[1].listlagu);
    //BLACKPINK.BORN PINK
    
    AddLagu(&LP.listpenyanyi[2].album.listalbum[0].listlagu,toKata("Pink Venom"));
    AddLagu(&LP.listpenyanyi[2].album.listalbum[0].listlagu,toKata("Shut Down"));
    AddLagu(&LP.listpenyanyi[2].album.listalbum[0].listlagu,toKata("Tally"));
    // DisplayListLagu(LP.listpenyanyi[2].album.listalbum[0].listlagu);
    

    
    // playlistCreate(&kumpulanPlaylist);
    playlistAddSong(kumpulanPlaylist,LP);
    

    int indeks = IndeksPenyanyi(LP,toKata("BLACKPINK"));
    printf("%d\n",indeks);

    // DisplayListAlbum(LP.listpenyanyi[0].album);
    // printf("\n");
    // DisplayListAlbum(LP.listpenyanyi[1].album);
    // printf("\n");
    // DisplayListAlbum(LP.listpenyanyi[2].album);
    // printf("\n");
    DisplayListPlaylist(&kumpulanPlaylist);
    return 0;
}