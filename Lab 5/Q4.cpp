#include<stdio.h>

int main(void){
	int amount, membership;
	printf("Enter amouint ");
	scanf("%d", &amount);
	printf("Enter membership (1 for true and 0 for false) ");
	scanf("%d", &membership);
	
	(amount > 100 && membership == 1)? printf("Discount applied."):printf("Discount not applied.");
}