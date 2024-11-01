#include<stdio.h>
#include<string.h>
int main(void){
    char user[5][50]={"uqbah","Bob","Hassan","Saad", "Suliman"}, name[50];
	
	printf("Enter Name : ");
	fgets(name,sizeof(name),stdin);
	name[strcspn(name,"\n")]='\0';
	
	int flag=0;
	
	for (int i=0;i<5;i++){
		if (strcmp(user[i],name)==0){
			flag =1;
		}
	}
	if (flag == 1){
		printf("Name found");
	}
	else {
		printf("Name not found");
	}
}