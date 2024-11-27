#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *file = fopen("text.txt","r+");
    FILE *filecopy = fopen("textcopy.txt", "w+");

    if (file == NULL || filecopy == NULL)
    {
        printf("Error opening the file.");
        exit(1);
    }

    char line[100];
    while (fgets(line,sizeof(line),file) != NULL)
    {
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] >= 'a' && line[i] <='z'){
                line[i] = line[i] - ('a' - 'A');
            }
        }
        fprintf(filecopy, "%s",line);
    }
    
    fclose(file);
}