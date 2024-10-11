#include<stdio.h>

int main(void){
	int sum;
	int num[15];
	
	for (int i=0;i<15;i++){
		int n;
		printf("Enter element %d: ",i);
		scanf("%d",&n);
		num[i]= n;
	}
	for (int i=0;i<15;i++){
		sum += num[i];
	}
	printf("The sum is %d.",sum);
}