#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct directory{
	char dirName[50];
	char fileName[50][50];
	int fileCount;
}dir;

void main(){
	int i,j,ch,n;
	char temp[50];
	dir.fileCount = 0;
	printf("Enter root directory name : ");
	scanf("%s",dir.dirName);
	
	while(1){
		printf("\n1.Insert File\n2.View Files\nEnter choice :");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				if(dir.fileCount == 50)
					break;
				printf("Enter file : ");
				scanf("%s",temp);
				for (i = 0; i < dir.fileCount; i++)
                {
                    if (strcmp(dir.fileName[i], temp) == 0)
                    {
                        printf("File already exists\n");
                        break;
                    }
                }
                if(i == dir.fileCount)
					strcpy(dir.fileName[dir.fileCount++],temp);
				break;
			case 2:
				j = 0;
				while(j<dir.fileCount){
					printf("%s\n",dir.fileName[j]);
					j++;
				}
				break;
			default:
				printf("Enter correct choice");
				scanf("%d",&ch);				
		}
	}
}
