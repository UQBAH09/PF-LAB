#include <stdio.h>

int main(void) {
    int num,a;
    printf("Enter num only till 15: ");
    scanf("%d", &num);
    
    if (num & 1)
        a ++;
    if (num & 2)
        a ++;
    if (num & 4)
        a ++;
    if (num & 8)
        a ++;
    
    printf("%d", a);
}