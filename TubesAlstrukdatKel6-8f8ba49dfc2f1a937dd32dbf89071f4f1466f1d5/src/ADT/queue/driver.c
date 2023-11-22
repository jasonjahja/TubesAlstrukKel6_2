#include <stdio.h>
#include "queue.h"

int main() {
    Queue Q;
    CreateEmptyQueue(&Q);
    
    printf("Isi queue setelah dibuat (seharusnya kosong): "); 
    displayQueue(Q); printf("\n");

    printf("Angka akan bernilai 1 jika kosong (seharusnya 1): %d\n", IsEmptyQueue(Q));
    printf("Angka akan bernilai 1 jika penuh (seharusnya 0): %d\n\n", IsFullQueue(Q));

    printf("Jumlah elemen queue setelah dibuat (seharusnya 0): %d\n\n", LengthQueue(Q)); 

    enqueueQueue(&Q, toKata("Apple"), toKata("Banana"), toKata("Cherry"));
    enqueueQueue(&Q, toKata("Apple2"), toKata("Banana2"), toKata("Cherry2"));
    
    printf("Isi queue setelah enqueue: ");
    displayQueue(Q); printf("\n");

    printf("Angka akan bernilai 1 jika kosong (seharusnya 0): %d\n", IsEmptyQueue(Q));
    printf("Angka akan bernilai 1 jika penuh (seharusnya 0): %d\n\n", IsFullQueue(Q));

    Song dequeuedWord = dequeueQueue(&Q);
    printf("Elemen yang di-dequeue: {");
    TulisWordNoNL(dequeuedWord.judul);
    printf(",");
    TulisWordNoNL(dequeuedWord.album);
    printf(",");
    TulisWordNoNL(dequeuedWord.penyanyi);
    printf("}\n\n");

    printf("Isi queue setelah dequeue: ");
    displayQueue(Q); printf("\n");

    return 0;
}