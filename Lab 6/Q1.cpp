#include<stdio.h>
int main(void){
	int num,sum =1;
	printf("Enter number to find factorial: ");
	scanf("%d",&num);
	if (num>=0){
		for (int i=1;i<=num;i++){
			sum *= i;
		}
		printf(" The factorial is %d", sum);
	}
	else printf("Wrong input.");
}
