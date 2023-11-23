#include <stdint.h>
#include "node.c"

int main(){
    
    ListBerkait l;
    CreateList(&l);
    printf("%d\n", isEmpty(l));

    ElType val = {.TabWord = "kiwkiw",.Length = 13};
    FIRST(l) = newNode(val);
    
    return 0;
}