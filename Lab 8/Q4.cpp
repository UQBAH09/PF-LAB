#include <stdio.h>

int main(void){
	int m,n;
	printf("Enter diminsion m: ");
	scanf("%d",&m);
	printf("Enter diminsion n: ");
	scanf("%d",&n);
	
	int mat1[m][n];
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Enter number: ");
			scanf("%d", &mat1[i][j]);
		}
	}
	int mat2[m][n];
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			printf("Enter number: ");
			scanf("%d", &mat2[i][j]);
		}
	}
	int sum=0;
	
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			mat1[i][j] += mat2[i][j];
		}
		
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
		printf(" %d ",mat1[i][j]);
		}
		printf("\n");
	}
}