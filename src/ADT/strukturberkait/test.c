#include <stdio.h>
#include "../mesinbaris/mesinbaris.c"
#include "../mesinkarakter/mesinkarakter.c"
#include "../mesinkata/mesinkata.c"
#include "../set/set.c"

int main(){
    Word a = toKata("lagu 1");
    Word b = toKata("lagu 2");
    Word c = toKata("kampret");

    SetofSong kalimat = {{a,b,c}};
    TulisWord(toKata(kalimat.Lagu[0].album.TabWord));


    {{"Marcell","SuksesBesar","JandaMuda"}}
    return 0;

}