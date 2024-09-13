#include<stdio.h>

int main(void){
    int price, discount;
    printf("Enter price of the item: ");
    scanf("%d", &price);

    if (price<1500)
        discount = 7;
    else if (price>1500 && price<3000)
        discount = 12;
    else if (price>3000 && price<5000)
        discount = 22;
    else if (price>5000)
        discount = 35;
    
    printf("The orignal amount is %d and you have saved a total of %d. The final amount after discount is %d.", price, (price*discount)/100, price - (price*discount)/100);
}