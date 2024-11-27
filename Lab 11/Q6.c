#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Invoice
{
    char partnum[50];
    char discription[100];
    int quantity;
    float price;
};


int main(void){
    struct Invoice i;

    strcpy(i.partnum,"9120");
    strcpy(i.discription, "2 inch screw");
    i.quantity = 100;
    i.price = 0.05;

    if (i.quantity < 0){
        i.quantity = 0;
    }
    if (i.price < 0){
        i.price = 0;
    }

    printf("Item number %s (%s)\n", i.partnum, i.discription);
    printf("Quantity: %d\n", i.quantity);
    printf("Price per peice: %.2f\n",i.price);
    printf("Total cost: %.2f", i.price*i.quantity);

}