#include<stdio.h>
int main(void){
	int num,a,sum = 0;
	printf("Enter number: ");
	scanf("%d",&num);
	a = num;
	while (a>0){
	    int cube = a%10; 
	    sum += (cube*cube*cube);
	    a = a/10;
	}
	if (sum == num){
	    printf("It is a Armstrong number.");
	}
	else printf("It is not a Armstrong number.");
}
