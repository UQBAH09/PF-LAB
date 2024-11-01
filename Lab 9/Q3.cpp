#include<stdio.h>
#include<string.h>
int main(void){
    char user[]="admin",pass[]="1234",username[50],password[50];
	
	printf("Enter UserName : ");
	fgets(username,sizeof(username),stdin);
	username[strcspn(username,"\n")]='\0';
	
	printf("Enter Password : ");
	fgets(password,sizeof(password),stdin);
	password[strcspn(password,"\n")]='\0';
	
	if(strcmp(pass,password)==0 && strcmp(user,username)==0){
		printf("\n Access Granted");
	}
	else{
		printf("\n Access Denied");
	}
}