#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mesinbaris/mesinbaris.h"

int main() {
    Word a = {"jason", 5};
    Word b = {"jahja", 5};
    GetCommand();
    if (isInputEqual(currentLine, a)) {
        printf("%s\n", currentLine.kalimat);
        printf("benar\n");
        ADVCOMM();
        if(isInputEqual(currentLine, b)) {
            printf("%s\n", currentLine.kalimat);
            printf("benar\n");
        }
    }
    return 0;
}