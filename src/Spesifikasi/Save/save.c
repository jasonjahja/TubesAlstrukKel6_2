#include <stdio.h>
#include "Save.h"
// #include <sys/stat.h>
#include <unistd.h>
// #include <string.h>
// #include <errno.h>

//Save 1
// int save(const char *filename,const Node *S){
    
//     FILE *file = fopen(filename,"w");
//     while(S->next != NULL){
//         fprintf(file,"%d\n", S->info);
//         S = S->next;
//     }

//     fclose(file);
//     return 1;
// }

//Save 2
void Save(const char *filename, const char *data){
    const char *parent_dir = "../../save";
    char path[255];
    snprintf(path,sizeof(path),"%s/%s",parent_dir,filename);

    // char directoryPath[255];
    // strncpy(directoryPath, path, strrchr(path, '/') - path + 1);
    // directoryPath[strrchr(path, '/') - path + 1] = '\0';

    // if (access(path,F_OK) == -1){
    //     printf("Menyimpan...\n");
    //     printf("Membuat directory...\n");
    //     if (mkdir(path,0777) == 0){
    //         printf("Directory %s dibuat.\n",path);
    //     } else{
    //     // perror("Failed to create directory");
    //     printf("Gagal membuat directory %s\n", path);
    //     // return;
    //     }
    // } else{
    //     printf("Directory %s sudah ada.\n",path);
    // }

    FILE *file = fopen(path,"w");
    if(file != NULL){
        fputs(data,file);
        fclose(file);
        printf("File tersimpan\n");
    } else{
        fclose(file);
        printf("%s\n",path);
        printf("Gagal menyimpan : \n");
    }
}

    // pita = fopen("../save/config.txt", "r");
    // if (pita == NULL) {
    //     printf("Gagal membuka file");
    //     return 1;
    // }
    // while (STARTWORD(pita) && !feof(pita)){
    //     TulisWord(currentWord);
    //     int jumlahpenyanyi = WordtoNum(currentWord);    

    //     while (jumlahpenyanyi > 0 ) {
    //     // printf("\n~~~~~~~~~~PENYANYI(%d)~~~~~~~~~~~~~~~~\n",jumlahpenyanyi);

    //         ADVWORD();
    //         TulisWord(currentWord);
    //         int jumlahAlbum = WordtoNum(currentWord);

    //         while (jumlahAlbum > 0){
    //             // printf("\n==========ALBUM(%d)============\n",jumlahAlbum);
    //             ADVWORD();
    //             TulisWord(currentWord);
    //             int banyakLagu = WordtoNum(currentWord);
            
    //             // printf("\n---------LAGU-----------\n");
    //             banyakLagu--;
    //             while (banyakLagu > 0){     
    //                 ADVWORD();
    //                 TulisWord(currentWord);
    //                 banyakLagu--;
    //             }
    //             ADVWORD();
    //             TulisWord(currentWord);            
    //             jumlahAlbum--;                
    //         }
    //         jumlahpenyanyi--;
    //     }
    // }
    // fclose(pita);
    // return 0;