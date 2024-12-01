#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findHighestFrequency(int arr[], int size) {
    int maxFreq = 0;
    int mostFrequent = 0;

    for (int i = 0; i < size; i++) {
        int freq = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                freq++;
            }
        }

    if (freq > maxFreq || (freq == maxFreq && arr[i] < mostFrequent)) {
        maxFreq = freq;
        mostFrequent = arr[i];
    }
    }

    printf("%d\n", mostFrequent);
}

int main(void){
    int n;
    printf("Enter number of test cases: ");
    scanf("%d", &n);

    int **array = malloc(sizeof(int *) * n);

    int testcases[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter number of numbers: ");
        scanf("%d", &testcases[i]);

        array[i] = malloc(sizeof(int) * testcases[i]);

        for (int j = 0; j < testcases[i]; j++)
        {
            printf("  Enter number %d: ",j+1);
            scanf("%d", &array[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        findHighestFrequency(array[i], testcases[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        free(array[i]);
    }
    free(array);
    
}