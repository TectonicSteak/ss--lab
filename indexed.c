#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[20];
    int start;
    int length;
};

struct file indexBlock[50];

int check(int size) {
    int i, free_space = 0;
    for (i = 0; i < 50; i++) {
        if (strlen(indexBlock[i].name) == 0) {
            free_space++;
        }
    }
    if (free_space < size) {
        return 0;
    } else {
        return 1;
    }
}

void allocate() {
    int i, size, free_space;
    char name[20];
    printf("\nEnter file name: ");
    scanf("%s", name);
    printf("\nEnter starting block index: ");
    scanf("%d", &i);
    printf("\nEnter length of file: ");
    scanf("%d", &size);

    free_space = 0;
    for (i = 0; i < 50; i++) {
        if (strlen(indexBlock[i].name) == 0) {
            free_space++;
        }
    }

    if (free_space < size) {
        printf("Not enough free space on disk to allocate file.\n");
        return;
    }

    for (i = 0; i < 50; i++) {
        if (strlen(indexBlock[i].name) == 0) {
            strcpy(indexBlock[i].name, name);
            indexBlock[i].start = i;
            indexBlock[i].length = size;
            break;
        }
    }

    printf("\nFile allocated.");
    printf("\nFile name: %s", indexBlock[i].name);
    printf("\nStarting block index: %d", indexBlock[i].start);
    printf("\nLength of file: %d", indexBlock[i].length);
}

int main() {
    int i, d;

    for (i = 0; i < 50; i++) {
        strcpy(indexBlock[i].name, "");
        indexBlock[i].start = -1;
        indexBlock[i].length = -1;
    }

    do {
        printf("\n1. Allocate file\n2. Exit\n");
        scanf("%d", &d);
        switch (d) {
            case 1:
                allocate();
                break;

            default:
                printf("Try again");
        }
    } while (d != 2);

    return 0;
}
