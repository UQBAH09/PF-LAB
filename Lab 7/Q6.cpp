#include<stdio.h>

int main(void){
	int sum, limit=5;
	int num[limit];
	
	for (int i=0;i<limit;i++){
		int n;
		printf("Enter element %d: ",i);
		scanf("%d",&n);
		num[i]= n;
	}
	int min=num[0], max=num[0];
	for (int i=0;i<limit;i++){
		if (num[i]>max){
			max = num[i];
		}
	}
	for (int i=0;i<limit;i++){
		if (num[i]<min){
			min = num[i];
		}
	}
	printf("Maximum Number = %d\n",max);
	printf("Minimum Number = %d",min);
}