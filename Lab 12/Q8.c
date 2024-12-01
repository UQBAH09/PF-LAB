#include <stdio.h>
#include <stdlib.h>

int main(void){
    int size;
    printf("Enter the total number of points in the facility: ");
    scanf("%d", &size);

    float *array = (float *)malloc(sizeof(float) * size);

    for (int i = 0; i < size; i++)
    {
        printf("  Enter fee for point %d: ", i+1);
        scanf("%f", &array[i]);
    }

    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    printf("Total Profit for the facility: $%.2f", sum);

    free(array);
}