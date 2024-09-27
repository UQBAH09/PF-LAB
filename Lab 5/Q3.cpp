#include<stdio.h>

int main(void){
	int grade;
	printf("Enter grade ");
	scanf("%d", &grade);

	(grade>=90)? printf("A"): printf("");
	(grade>=80 && grade<89)? printf("B"): printf("");
	(grade>=70 && grade<79)? printf("C"): printf("");
	(grade>=60 && grade<69)? printf("D"): printf("");
	(grade<60)? printf("E"): printf("");
}