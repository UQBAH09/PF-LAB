#include<stdio.h>
#include<string.h>

void print(char name[50],int size, int i){
	if (size<i){
		return;
	}
	printf("%c", name[i]);
	print(name, size, i+1);
}

int main(void){
	char name[] = "UQBAH KHAN";
	int size = strlen(name) -1;
	int i=0;
	print(name, size, i);
}