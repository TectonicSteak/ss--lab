#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
    char dirName[10], fileName[10][10];
    int fileCount;
} dir[10];

void main()
{
    int i, ch, dirCount, k;
    char f[30], d[30];
    dirCount = 0;
    while (1)
    {
        printf("\n1.Create Directory\n2.Create File\n3.Delete File\n4.Search File\n5.Display\n6.Exit\nEnter Your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Name of Directory:");
            scanf("%s", dir[dirCount].dirName);
            dir[dirCount].fileCount = 0;
            dirCount++;
            printf("\nDirectory created");
            break;
        case 2:
            printf("\nEnter Name of the Directory:");
            scanf("%s", d);
            for (i = 0; i < dirCount; i++)
                if (strcmp(d, dir[i].dirName) == 0)
                {
                    printf("\nEnter Name of the File to Create:");
                    scanf("%s", dir[i].fileName[dir[i].fileCount]);
                    dir[i].fileCount++;
                    printf("\nFile created");
                    break;
                }
            if (i == dirCount)
                printf("\nDirectory %s Not Found!", d);
            break;
        case 3:
            printf("\nEnter Name of the Directory:");
            scanf("%s", d);
            for (i = 0; i < dirCount; i++)
            {
                if(strcmp(d,dir[i].dirName) == 0){
                	printf("\nEnter File name : ");
                	scanf("%s", f);
                	for(k = 0; k<dir[i].fileCount; k++){
                		if(strcmp(f, dir[i].fileName[k]) == 0){
                			strcpy(dir[i].fileName[k],dir[i].fileName[--dir[i].fileCount]);
                			goto jump1;
                		}
                	}
                	printf("\nFile %s Not Found!", f);
                	goto jump1;
                }
            }
            printf("\nDirectory %s Not Found!", d);
        jump1:
            break;
        case 4:
            printf("\nEnter Name of the Directory:");
            scanf("%s", d);
            for (i = 0; i < dirCount; i++)
            {
                if (strcmp(d, dir[i].dirName) == 0)
                {
                    printf("\nEnter the Name of the File to Search:");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fileCount; k++)
                    {
                        if (strcmp(f, dir[i].fileName[k]) == 0)
                        {
                            printf("\nFile %s Found", f);
                            goto jump2;
                        }
                    }
                    printf("\nFile %s Not Found!", f);
                    goto jump2;
                }
            }
            printf("\nDirectory %s Not Found!", d);
        jump2:
            break;
        case 5:
            if (dirCount == 0)
                printf("\nNo Directories!");
            else
            {
                printf("\nDirectory\tFiles");
                for (i = 0; i < dirCount; i++)
                {
                    printf("\n%s\t\t", dir[i].dirName);
                    for (k = 0; k < dir[i].fileCount; k++)
                        printf("\t%s", dir[i].fileName[k]);
                }
            }
            break;
        default:
            exit(0);
        }
    }
}
