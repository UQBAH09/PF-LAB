#include<stdio.h>
#include<string.h>

void reverse(char str[50],int i){
	if (i < 0){
		return;
	}
	printf("%c", str[i]);
	
	reverse(str,i-1);
}

int main(void){
	char str[50];
	printf("Enter a sentence: ");
	fgets(str, sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	int i = strlen(str)-1;
	reverse(str,i);
}