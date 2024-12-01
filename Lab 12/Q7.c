#include <stdio.h>
#include <stdlib.h>

int main(void){
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of coloms: ");
    scanf("%d", &col);
    
    int **array = calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        array[i] = calloc(col, sizeof(int));
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    *(*(array + 1) + 0) = 9;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        free(array[i]);
    }
    free(array);
    
}