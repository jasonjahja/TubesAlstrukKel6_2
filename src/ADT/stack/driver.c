#include <stdio.h>
#include "stack.h"

int main() {
    songHistory S;
    CreateEmptyStack(&S);
    
    printf("Isi stack setelah dibuat (seharusnya kosong): "); 
    PrintStack(S); printf("\n");

    printf("Angka akan bernilai 1 jika kosong (seharusnya 1): %d\n", IsEmptyStack(S));
    printf("Angka akan bernilai 1 jika penuh (seharusnya 0): %d\n\n", IsFullStack(S));

    PushStack(&S, toKata("Apple"), toKata("Banana"), toKata("Cherry"));
    PushStack(&S, toKata("Apple2"), toKata("Banana2"), toKata("Cherry2"));
    
    printf("Isi stack setelah push: ");
    PrintStack(S); printf("\n");

    printf("Angka akan bernilai 1 jika kosong (seharusnya 0): %d\n", IsEmptyStack(S));
    printf("Angka akan bernilai 1 jika penuh (seharusnya 0): %d\n\n", IsFullStack(S));

    Word song;
    Word album;
    Word singer;

    PopStack(&S, &song, &album, &singer);

    printf("Isi elemen yang di pop (seharusnya {Apple2,Banana2,Cherry2}): {");
    TulisWordNoNL(song);
    printf(",");
    TulisWordNoNL(album);
    printf(",");
    TulisWordNoNL(singer);
    printf("}\n\n");

    PrintStack(S);
    return 0;
}