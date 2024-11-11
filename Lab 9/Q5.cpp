#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char text[100];
	int textint[100],key[100],cypher[100];
	char word[] = "Qubits";
	int len = strlen(word);
	
	printf("Enter text: ");
	fgets(text,sizeof(text),stdin);
	text[strcspn(text,"\n")]='\0';
	
	for(int i=0,j=0;text[i] != '\0';i++,j++){
		if (j==len){
			j=0;
		}
		key[i] = (int)word[j] - 64;
	}
	
	for(int i=0;text[i] != '\0';i++){
		if (text[i] == ' '){
			textint[i] = 20;
			continue;
		}
		else{
			textint[i] =  (int)text[i] - 64;
		}
	}
	
	for(int i=0;key[i]!=NULL;i++){
		
		cypher[i] = textint[i] + key[i];
		cypher[i] %= 26;
		cypher[i] += 64;
	}
	cypher[strlen(text)] = '\0';
	
	printf("Cypher text is: ");
	for(int i=0;cypher[i]!='\0';i++){
		printf("%c",(char)cypher[i]);
	}
}
