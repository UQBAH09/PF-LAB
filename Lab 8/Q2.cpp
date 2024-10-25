#include <stdio.h>

int main(void){
	int mat[4][4];
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			printf("Enter number: ");
			scanf("%d", &mat[i][j]);
		}
	}
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			if (mat[i][j] < 0)
				mat[i][j] = 0;
		}
	}
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
		printf(" %d ",mat[i][j]);
		}
		printf("\n");
	}
}