// gcc -o driver driver.c start.c ../../ADT/mesinbaris/mesinbaris.c ../../ADT/mesinkata/mesinkata.c ../../ADT/list/list.c ../../ADT/map/map.c ../../ADT/set/set.c ../../ADT/mesinkarakter/mesinkarakter.c ../../ADT/stack/stack.c ../../ADT/listdin/listdin.c ../../ADT/queue/queue.c ../../ADT/strukturberkait/listberkait.c ../../Spesifikasi/List/List.c ../../Spesifikasi/Play/play.c

#include <stdio.h>
#include "Start.h"

int main(){

    ListofPenyanyi ListPenyanyi = MakeList();

    startConfig(&ListPenyanyi);
    printf("\n\n\n");
    list_default(ListPenyanyi);
    

    return 0;
}