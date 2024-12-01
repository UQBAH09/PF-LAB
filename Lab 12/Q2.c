#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int n;
    printf("Enter number of numbers: ");
    scanf("%d", &n);

    int *array = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 1)
        {
            array[i] --;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    
    free(array);
}