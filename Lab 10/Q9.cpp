#include <stdio.h>
#include <string.h>

struct Employee {
    int emp_id;
    char name[50];
    char department[50];
    float salary;
};

int main(void){
	int n;
	printf("Enter number of employees: ");
	scanf("%d",&n);
	
	struct Employee employees[100];
	for (int i=0;i<n;i++){
		printf("\nEnter details for employee %d\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        getchar();
        fgets(employees[i].name, 50, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';
        printf("Department: ");
        fgets(employees[i].department, 50, stdin);
        employees[i].department[strcspn(employees[i].department, "\n")] = '\0';
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
	}
	
	printf("\nEmployee Details:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d\n", i + 1);
        printf("Employee ID: %d\n", employees[i].emp_id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("--------------------------------------------------\n");
    }
}
