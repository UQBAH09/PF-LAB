#include<stdio.h>

int main(void){
    int units;
    float total;
    
    printf("Enter total units: ");
    scanf("%d", &units);

    if (units<=30)
        total = units*0.6;
    else if (units<=110)
        total = 30*0.6 + (units-30)*0.85;
    else if (units<=210)
        total = 30*0.6 + 80*0.85 + (units-110)*1.3;
    else
        total = 30*0.6 + 80*0.85 + 100*1.3 + (units-210)*1.6;
    
    printf("Your total bill is Rs.%.2f", total*1.15);
    }