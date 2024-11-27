#include<stdio.h>
#include<string.h>

struct Rectangle{
    float lenght;
    float width;
};

float area(struct Rectangle r){
    return r.lenght*r.width;
}

float parameter(struct Rectangle r){
    return 2*(r.lenght + r.width);
}

int main(void){
    struct Rectangle r;

    printf("Enter lenght: ");
    scanf("%f", &r.lenght);
    printf("Enter width: ");
    scanf("%f", &r.width);

    printf("The area of the rectangel is %.2f.\n", area(r));
    printf("The parameter of the rectangel is %.2f.", parameter(r));
}
