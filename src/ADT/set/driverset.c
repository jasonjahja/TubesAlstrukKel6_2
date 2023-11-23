#include <stdio.h>
#include "set.h"  // Include the set ADT header file

Sentence currentLine;
const Word Mark = {'\0',0};

int main() {
    SetofSong songSet = CreateEmptySet();  // Create an empty set of songs
    Word songTitle;

    int choice;
    do {
        printf("\n==== Song Set Menu ====\n");
        printf("1. Add Song\n");
        printf("2. Display Songs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the title of the song: ");
                GetCommand();;  // Assuming STARTWORD initializes currentWord
                CopyWordToVar(&songTitle, currentWord);  // Copy the input word to songTitle
                AddLagu(&songSet, songTitle);  // Add the song to the set
                break;
            case 2:
                printf("\n=== Song List ===\n");
                DisplayListLagu(songSet);  // Display the list of songs
                printf("\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}