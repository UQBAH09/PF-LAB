#include <stdio.h>
#include <string.h>

struct car{
	char make[50];
    char model[50];
    int year;
    float price;
    int mileage;
};

void addCar(struct car c[], int *count){
	printf("Enter car make: ");
	scanf("%s", c[*count].make);
	getchar();
	printf("Enter car model: ");
	scanf("%s", c[*count].model);
	getchar();
	printf("Enter car year: ");
	scanf("%d", &c[*count].year);
	printf("Enter car price: ");
	scanf("%f", &c[*count].price);
	printf("Enter car milage: ");
	scanf("%d", &c[*count].mileage);
	(*count)++;
}

void availableCars(struct car c[], int *count){
	printf("\nCars avliable\n");
	for (int i = 0; i < (*count); i++) {
        printf("\nCar %d\n", i + 1);
        printf("Make: %s\n", c[i].make);
        printf("Model: %s\n", c[i].model);
        printf("Year: %d\n", c[i].year);
        printf("Price: $%.2f\n", c[i].price);
        printf("Mileage: %d miles\n\n", c[i].mileage);
    }
}

void searchCars(struct car c[], int *count){
	char searchBy[50];
	printf("\nEnter car make or model: ");
	scanf("%s",searchBy);
	getchar();
	for (int i=0;i<(*count);i++){
		if (strcmp(searchBy,c[i].make) == 0 || strcmp(searchBy,c[i].model) == 0){
			printf("Car found.");
			return;
		}
	}
	printf("Car not found.");
}

int main(void){
	struct car c[100];
	int count = 0,choice;
	while (1){
		printf("Press 1 to add a new car, 2 to display a list of available cars, 3 to search for cars, and 4 to quit: ");
		scanf("%d", &choice);
		switch (choice){
			case 1:
				addCar(c,&count);
				break;
			case 2:
				availableCars(c,&count);
				break;
			case 3:
				searchCars(c,&count);
				break;
			case 4:
				return 0;
			default:
				printf("Wrong input.");
		}
	}
}
