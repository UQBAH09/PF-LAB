#include <stdio.h>

int main(void){
	int nut, bolt,washer;
	printf("Number of bolts: ");
	scanf("%d", &bolt);
	printf("Number of nuts: ");
	scanf("%d", &nut);
	printf("Number of washers: ");
	scanf("%d", &washer);
	
	if (bolt > nut){
		printf("Cheak the order:	too few nuts\n");
	}
	else if (bolt*2 > washer){
		printf("Cheak the order:	too few washers\n");
	}
	
	printf("Total Cost:		%d", bolt*5+nut*3+washer*1);	
	
}