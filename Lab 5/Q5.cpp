#include<stdio.h>

int main(void){
	int num;
	printf("Enter num ");
	scanf("%d", &num);
	if (!(num & 1))
		printf("Even");
	else printf("Odd");
}