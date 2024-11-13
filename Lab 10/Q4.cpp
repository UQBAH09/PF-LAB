#include <stdio.h>
#include <string.h>

struct TravelPackage {
    char packageName[50];
    char destination[50];
    int duration;
    float cost;
    int seatsAvailable;
};

void bookPackage(struct TravelPackage t[], int *count){
	printf("Enter package name: ");
	scanf("%s", t[*count].packageName);
	getchar();
	printf("Enter destination: ");
	scanf("%s", t[*count].destination);
	getchar();
	printf("Enter duration: ");
	scanf("%d", &t[*count].duration);
	printf("Enter cost: ");
	scanf("%f", &t[*count].cost);
	printf("Enter seats available (0 for no & 1 for yes): ");
	scanf("%d", &t[*count].seatsAvailable);
	(*count)++;
}

void availablePackages(struct TravelPackage t[], int *count){
	printf("\nAvailable Travel Packages:\n");
	for (int i = 0; i < (*count); i++) {
        printf("\nPackage %d\n", i + 1);
        printf("Name: %s\n", t[i].packageName);
        printf("Destination: %s\n", t[i].destination);
        printf("Duration: %d days\n", t[i].duration);
        printf("Cost: $%.2f per person\n", t[i].cost);
        printf("Seats Available: %d\n", t[i].seatsAvailable);
    }
}

int main(void){
	struct TravelPackage t[100];
	int count = 0,choice;
	while (1){
		printf("\nPress 1 to book a travel package, 2 to display a list of available packages, and 3  to quit: ");
		scanf("%d", &choice);
		switch (choice){
			case 1:
				bookPackage(t,&count);
				break;
			case 2:
				availablePackages(t,&count);
				break;
			case 3:
				return 0;
			default:
				printf("Wrong input.");
		}
	}
}
