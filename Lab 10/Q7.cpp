#include <stdio.h>

void bubbleSort(int arr[],int size,int i,int j){
	if (i == size-1){
		return;
	}
	if (j == size-1){
		bubbleSort(arr, size, i + 1, 0);
		return;
	}
	if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
    }
	
	
	bubbleSort(arr,size,i,j+1);
}

int main(void){
	int arr[] = {2,6,3,7,4,8,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i=0,j=0;
	bubbleSort(arr,size,i,j);
	
	printf("Bubble sorted array is: ");
	for (int i=0;i<size;i++){
		printf(" %d",arr[i]);
	}
}
