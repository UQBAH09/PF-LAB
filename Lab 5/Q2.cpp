#include<stdio.h>

int main(void){
	int a1, a2, a3;
	printf("Enter angle 1 ");
	scanf("%d", &a1);
	printf("Enter angle 2 ");
	scanf("%d", &a2);
	printf("Enter angle 3 ");
	scanf("%d", &a3);
	
	if (a1 > 0 && a2 > 0 && a3 > 0){
		if (a1 + a2 + a3 == 180)
			printf("Triangle is valid.");
		else
			printf("Triangle is not valid.");
	}
	else
		printf("invalid angle provided.");
}