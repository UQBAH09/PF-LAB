#include<stdio.h>

int main(void){
    int marks;
    
    printf("Enter your marks: ");
    scanf("%d",&marks);

    if (marks >= 90){
        printf("Your grade is A");
    }
    else if (marks >= 80 && marks <=89){
        printf("Your grade is B");
    }
    else if (marks >= 70 && marks <=79){
        printf("Your grade is C");
    }
    else if (marks >= 60 && marks <=69){
        printf("Your grade is D");
    }
    else if (marks < 60){
        printf("Your grade is F");
    }
}