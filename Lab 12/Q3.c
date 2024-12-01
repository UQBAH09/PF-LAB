#include <stdio.h>
#include <stdlib.h>

// Function to double the size of the array
void doubleSize(float **array, int *size)
{
    float *newArray = realloc(*array, sizeof(float) * (*size) * 2);
    if (!newArray)
    {
        printf("Memory allocation failed!\n");
        exit(1); // Exit the program on failure
    }
    *array = newArray;
    *size *= 2;
    printf("Array size doubled to %d.\n", *size);
}

// Function to reduce the array size to half
void halfSize(float **array, int *size)
{
    if (*size > 1)
    {
        float *newArray = realloc(*array, sizeof(float) * (*size) / 2);
        if (!newArray)
        {
            printf("Memory allocation failed!\n");
            exit(1); // Exit the program on failure
        }
        *array = newArray;
        *size /= 2;
        printf("Array size halved to %d.\n", *size);
    }
}

// Function to add a new number to the array
void addNum(float **array, int *count, int *size)
{
    if (*count >= *size)
    {
        doubleSize(array, size);
    }
    printf("Enter new number: ");
    scanf("%f", &(*array)[*count]);
    (*count)++;
}

// Function to display all numbers in the array
void displayNum(float array[], int count)
{
    printf("The numbers in the array are: ");
    for (int i = 0; i < count; i++)
    {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Function to remove the last number from the array
void removeNum(float **array, int *count, int *size)
{
    if (*count == 0)
    {
        printf("Array is empty. Please first add a number.\n");
        return;
    }
    (*count)--;

    // Check if the array size should be halved
    if (*count <= (*size) / 4)
    {
        halfSize(array, size);
    }
}

// Main function
int main(void)
{
    float *array = (float *)malloc(sizeof(float) * 4);
    if (!array)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int count = 0, size = 4, choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Add a number\n");
        printf("2. Display numbers\n");
        printf("3. Remove the last number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addNum(&array, &count, &size);
            break;
        case 2:
            displayNum(array, count);
            break;
        case 3:
            removeNum(&array, &count, &size);
            break;
        case 4:
            printf("Exiting...\n");
            free(array);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
