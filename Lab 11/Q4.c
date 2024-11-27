#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee
{
    char name[50];
    char DoB[11];
    int ID;
    char department[50];
    float salary;
};

void addEmployee(struct Employee e[], int *count){
    getchar();
    printf("Name: ");
    fgets(e[*count].name, 50, stdin);
    e[*count].name[strcspn(e[*count].name, "\n")] = '\0';
    
    printf("Date of Birth: ");
    fgets(e[*count].DoB, 50, stdin);
    e[*count].DoB[strcspn(e[*count].DoB, "\n")] = '\0';

    printf("Employee ID: ");
    scanf("%d", &e[*count].ID);
    getchar();
    
    printf("Department: ");
    fgets(e[*count].department, 50, stdin);
    e[*count].department[strcspn(e[*count].department, "\n")] = '\0';
    
    printf("Salary: ");
    scanf("%f", &e[*count].salary);

    (*count)++;
}

void delEmployee(struct Employee e[],int count){
    int empID;
    printf("Enter employee ID to delete: ");
    scanf("%d", &empID);

    for (int i = 0; i < count; i++)
    {
        if (empID == e[i].ID){
            e[i].ID = -1;
        }
    }    
}

void viewEmployee(struct Employee e[],int count){
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (e[i].ID != -1)
        {
            printf("Employee %d\n", i + 1);
            printf("Name: %s\n", e[i].name);
            printf("Date of Birth: %s\n", e[i].DoB);
            printf("Employee ID: %d\n", e[i].ID);
            printf("Department: %s\n", e[i].department);
            printf("Salary: %.2f\n", e[i].salary);
            printf("--------------------------------------------------\n");
        }
    }
}

int main(){
    struct Employee e[100];
    
    int choice = 0, count = 0;
    
    while (choice != 4)
    {    
        printf("Press 1 to add an employee, 2 to delete an employee, 3 to display all employess and 4 to exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addEmployee(e,&count);
            break;

        case 2:
            delEmployee(e,count);
            break;    

        case 3:
            viewEmployee(e,count);
            break;

        case 4:
            return 0;

        default:
            printf("Wrong choice.\n");
            break;
        }
    }
}