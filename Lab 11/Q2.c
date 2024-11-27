#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *file = fopen("text.txt","a+");

    if (file == NULL)
    {
        printf("Error opening the file.");
        exit(1);
    }

    rewind(file);

    char line[100];
    int i=1;
    while (fgets(line,sizeof(line),file) != NULL)
    {
        printf("line %d: %s",i,line);
        i++;
    }
    
    fclose(file);
}