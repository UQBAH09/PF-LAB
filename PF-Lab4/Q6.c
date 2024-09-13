#include<stdio.h>

int main(void){
    int num1;
    int num2;
    
    printf("Enter number 1: ");
    scanf("%d",&num1);
	printf("Enter number 2: ");
    scanf("%d",&num2);
    
    if (num1>num2){
    	if (num1>100)
    		printf("First number is significantly larger");
	}
	else if (num1<0){
    		printf("First number is negative and smaller");
	}
	else if (num1 == num2){
		printf("Both numbers are equal");
	}
}