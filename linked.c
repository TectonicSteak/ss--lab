#include <stdio.h>

int main() {
    int f[5000] = {0}; // initialize array to 0
    int p, i, st, len, j, c, k, a;

    // get number of blocks already allocated and their indices
    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);
    printf("Enter blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }

    // allocate files
    do {
        // get starting bloc4k index and length
        printf("Enter index starting block and length: ");
        scanf("%d%d", &st, &len);

        // check if starting block is already allocated
        if (f[st] == 1) {
            printf("%d starting block is already allocated\n", st);
            continue;
        }

        // allocate required number of blocks
        k = len;
        for (j = st; j < (st + k); j++) {
            if (f[j] == 0) {
                f[j] = 1;
                printf("%d-------->%d\n", j, f[j]);
            } else {
                printf("%d Block is already allocated\n", j);
                k++;
            }
        }

        // ask user if they want to enter more files
        printf("Do you want to enter more file (Yes - 1/No - 0): ");
        scanf("%d", &c);
    } while (c == 1);

    return 0;
}

