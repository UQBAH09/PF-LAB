#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Phone
{
    int araeCode;
    int exchange;
    int number;
};


int main(void){
    struct Phone myNum;
    struct Phone yourNum;

    myNum.araeCode = 212;
    myNum.exchange = 767;
    myNum.number = 8900;

    printf("Enter area number: ");
    scanf("%d",&yourNum.araeCode);
    printf("Enter exchange number: ");
    scanf("%d",&yourNum.exchange);
    printf("Enter number: ");
    scanf("%d",&yourNum.number);

    printf("My number is (%d) %d-%d\n",myNum.araeCode,myNum.exchange,myNum.number);
    printf("Your number is (%d) %d-%d\n",yourNum.araeCode,yourNum.exchange,yourNum.number);
}