#include <stdio.h>

int main(void){
	int mat[3][3];
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			printf("Enter number: ");
			scanf("%d", &mat[i][j]);
		}
	}
	
	int srow = 0,scol = 0;
	
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			srow += mat[i][j];
		}
		printf("The sum of row %d is %d \n", i+1, srow);
		srow = 0;
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			scol += mat[j][i];
		}
		printf("The sum of coloum %d is %d \n", i+1, scol);
		scol = 0;
	}
}