#include <stdio.h>
#include "save.h"

int main(){
    const char *filename = "Marcell.txt";
    const char *data = "tes coo berhasil\n";

    save(filename,data);
    return 0;
}