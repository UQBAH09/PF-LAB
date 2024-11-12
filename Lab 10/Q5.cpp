#include<stdio.h>
#include<string.h>

int sumof(int num, int sum){
	if (num == 0){
		return sum;
	}
	sum += num%10;
	num /= 10;
	
	sumof(num,sum);
}

int main(void){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	int sum=0;
	printf("The sum is %d",sumof(num,sum));
}
