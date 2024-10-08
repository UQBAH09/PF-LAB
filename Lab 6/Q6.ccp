#include<stdio.h>
int main(void){
	int num,prime = 1;
	printf("Enter number greater than 1: ");
	scanf("%d",&num);
	for (int i=2;i!=num;i++){
		if(num%i==0){
			prime = 0;
			break;
		}
	}
    
    if (prime){
        printf("This is a prime number.\n");
        printf("\n Fibonacci series %d terms:\n",num);
        
        int a = 0,b = 1;
        int t;
        printf("%d,%d",a,b);
        for (int i=0; i < num-2; i++){
            t = a;
            a = b;
            b = t+b;
            printf(",%d",b);
        } 
    }
    else printf("Not a prime number.");
}
