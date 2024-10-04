#include<stdio.h>
int main(void){
	int num,flag = 0;
	printf("Enter number: ");
	scanf("%d",&num);
	for (int i=2;i!=num;i++){
		if(num%i==0){
			printf("Not a prime number.");
			flag = 1;
			break;
		}
	}
	if (flag==0) printf("It is a prime number.");
}
