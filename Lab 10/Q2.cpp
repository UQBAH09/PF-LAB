#include<stdio.h>
#include<string.h>

void percentage(int num,int i){
	if (i>100){
		return;
	}
	float per = (num*i)/100;
	printf("%d percent = %.2f \n",i,per);
	percentage(num,i+1);
	
}

int main(void){
	int num;
	printf("Add a value split in percentage: ");
	scanf("%d", &num);
	int i=1;
	percentage(num,i);
}