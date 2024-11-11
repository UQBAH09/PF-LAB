#include <stdio.h>

int main() {
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < N - i; j++) {
            printf(". ");
        }
        for (int j = 0; j <= i; j++) {
            printf("o");
        }
        printf("\n");
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N - i; j++) {
            printf(". ");
        }
        for (int j = 0; j <= i; j++) {
            printf("o");
        }
        printf("\n");
    }

    return 0;
}

