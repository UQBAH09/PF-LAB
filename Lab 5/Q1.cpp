#include<stdio.h>

int main(void){
	int age, citizen;
	printf("Enter age ");
	scanf("%d", &age);
	printf("Enter citizenship (1 for true and 0 for false) ");
	scanf("%d", &citizen);
	
	if (age > 18 && citizen == 1){
		printf("You can vote.");
	}
	else{
		printf("You can't vote");
	}
}