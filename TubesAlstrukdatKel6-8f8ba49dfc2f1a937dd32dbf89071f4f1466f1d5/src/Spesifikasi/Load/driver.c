// gcc -o driver driver.c Load.c ../../ADT/mesinbaris/mesinbaris.c ../../ADT/mesinkata/mesinkata.c ../../ADT/list/list.c ../../ADT/map/map.c ../../ADT/set/set.c ../../ADT/mesinkarakter/mesinkarakter.c ../../ADT/stack/stack.c ../../ADT/listdin/listdin.c ../../ADT/queue/queue.c ../../ADT/strukturberkait/listberkait.c ../../Spesifikasi/List/List.c ../../Spesifikasi/Play/play.c
#include <stdio.h>
#include <stdlib.h>
#include "Load.h"

int main() {
    ListofPenyanyi LP;
    Sentence CL = {"test.txt", 10};
    load(&LP, CL);
    return 0;
}