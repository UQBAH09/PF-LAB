#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int numStd;
    printf("Enter number of students: ");
    scanf("%d", &numStd);

    int numGrade[numStd];
    int **array = malloc(sizeof(int *) * numStd);

    for (int i = 0; i < numStd; i++)
    {
        printf("Enter number of grades for student %d: ",i+1);
        scanf("%d", &numGrade[i]);

        array[i] = malloc(sizeof(int) * numGrade[i]);
    }

    for (int i = 0; i < numStd; i++)
    {
        printf("Enter Grade for student %d: \n", i+1);
        for (int j = 0; j < numGrade[i]; j++)
        {
            printf("  Grade %d: ", j+1);
            scanf("%d", &array[i][j]);
        }
        
    }
    

    for (int i = 0; i < numStd; i++)
    {
        printf("Student %d Grades: ",i+1);
        for (int j = 0; j < numGrade[i]; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    

    for (int i = 0; i < numStd; i++)
    {
        free(array[i]);
    }
    free(array);
}