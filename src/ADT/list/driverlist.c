#include <stdio.h>
#include "list.h"

// const Word Mark = {'\0',0};
// Sentence currentLine;

int main() {

    printf("--------START OF DRIVER--------\n");
    printf("Halo\n");
    
    Penyanyi singer1, singer2, singer3, singer4;
    char* penyanyi1 = {"Adele"};
    char* penyanyi2 = {"Maliq"};
    char* penyanyi3 = {"Tulus"};
    char* penyanyi4 = {"Blackpink"};

    ListofPenyanyi list1 = MakeList();

    printf("ListBerhasilDibuat\n");

    if (IsEmptyList(list1))
    {
        printf("ListKosong\n");
    }

    printf("----------------------\n");

    singer1.namaPenyanyi = toKata(penyanyi1);
    singer2.namaPenyanyi = toKata(penyanyi2);
    singer3.namaPenyanyi = toKata(penyanyi3);
    singer4.namaPenyanyi = toKata(penyanyi4);

    printf("Penyanyi1 ke-1 adalah = ");
    TulisWord(singer1.namaPenyanyi);
    printf("Penyanyi1 ke-2 adalah = ");
    TulisWord(singer2.namaPenyanyi);
    printf("Penyanyi1 ke-3 adalah = ");
    TulisWord(singer3.namaPenyanyi);
    printf("Penyanyi1 ke-4 adalah = ");
    TulisWord(singer4.namaPenyanyi);
    
    printf("Menambah 3 penyanyi\n");
    printf("^^^^^^^^^\n");
    AddPenyanyi(&list1, singer1.namaPenyanyi);
    AddPenyanyi(&list1, singer2.namaPenyanyi);
    AddPenyanyi(&list1, singer3.namaPenyanyi);

    if (IsEmptyList(list1))
    {
        printf("ListMasihKosong:(\n");
    }

    printf("Total penyanyi sekarang = %d\n", BanyakPenyanyi(list1));

    printf("----------------------\n");

    if (isMemberPenyanyi(list1,singer4.namaPenyanyi))
    {
        printf("%s ada di list penyanyi\n", singer1.namaPenyanyi.TabWord);
    }
    else
    {
        printf("%s tidak ada di list penyanyi\n", singer4.namaPenyanyi.TabWord);
    }

    printf("Menghapus %s dari indeks ke %d\n", GetPenyanyi(list1, singer1.namaPenyanyi), IndeksPenyanyi(list1, singer3.namaPenyanyi));
    printf("^^^^^^^^^\n");
    DelPenyanyi(&list1, singer1.namaPenyanyi);
    DelPenyanyi(&list1, singer4.namaPenyanyi); /*TEST DELETE*/
    printf("Total penyanyi sekarang = %d\n", BanyakPenyanyi(list1));

    printf("----------------------\n");

    printf("DAFTAR LIST PENYANYI : \n");
    DisplayListPenyanyi(list1);

    printf("--------END OF DRIVER--------\n");

    return 0;
}