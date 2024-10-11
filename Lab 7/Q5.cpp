#include<stdio.h>

int main(void){
	int sum, limit = 20;
	int num[limit];
	
	for (int i=0;i<limit;i++){
		int n;
		printf("Enter element %d: ",i);
		scanf("%d",&n);
		num[i]= n;
	}
	for (int i=0;i<(limit/2);i++){
		int x = num[i];
		num[i] = num[limit-i-1];
		num[limit-1-i] = x;
	}
	for (int i=0;i<limit;i++){
		printf("%d ",num[i]);
	}
}