#include<stdio.h>
int main(void){
	int num = 1;
	do{
		if (num<0) printf("no\n");
		printf("Enter number: ");
		scanf("%d",&num);
	}
	while(num<0);
	printf("hell yeah ~<%d>~", num);
}
