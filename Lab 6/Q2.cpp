#include<stdio.h>
int main(void){
	int num,i = 1;
	printf("Enter number: ");
	scanf("%d",&num);
	if (num>=1){
		while(i<=num){
			if (i%2==0){
				printf("%d \n", i);
			}
			i++;		
		}
	}
	else printf("Wrong input.");
}
