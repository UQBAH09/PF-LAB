#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COURSES 8
#define MAX_DEPARTMENTS 3

typedef struct
{
    int courseID;
    char courseName[50];
    char instructorName[50];
    int credits;
} Courses;

typedef struct
{
    char departmentName[50];
    Courses course[MAX_COURSES];
    int totalCourses;
} Department;

typedef struct
{
    Department departments[MAX_DEPARTMENTS];
    int totalDepartments;
} University;

University uni = {.totalDepartments = 0};

void addDepartment();
void addCourse();
void displayDetails();
void calculateTotalCredits();

int main()
{
    int choice;

    while (1)
    {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to Department\n");
        printf("3. Display Details\n");
        printf("4. Calculate Total Credits for a Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addDepartment();
            break;
        case 2:
            addCourse();
            break;
        case 3:
            displayDetails();
            break;
        case 4:
            calculateTotalCredits();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void addDepartment()
{
    if (uni.totalDepartments >= MAX_DEPARTMENTS)
    {
        printf("Maximum number of departments reached.\n");
        return;
    }

    printf("Enter department name: ");
    fgets(uni.departments[uni.totalDepartments].departmentName, 50, stdin);
    strtok(uni.departments[uni.totalDepartments].departmentName, "\n");

    uni.departments[uni.totalDepartments].totalCourses = 0;
    uni.totalDepartments++;

    printf("Department added successfully.\n");
}

void addCourse()
{
    if (uni.totalDepartments == 0)
    {
        printf("No departments available. Please add a department first.\n");
        return;
    }

    int deptIndex;
    printf("Select a department number:\n");
    for (int i = 0; i < uni.totalDepartments; i++)
    {
        printf("%d - %s\n", i + 1, uni.departments[i].departmentName);
    }
    printf("Enter your choice: ");
    scanf("%d", &deptIndex);
    getchar();

    if (deptIndex < 1 || deptIndex > uni.totalDepartments)
    {
        printf("Invalid department selection.\n");
        return;
    }

    deptIndex--;

    if (uni.departments[deptIndex].totalCourses >= MAX_COURSES)
    {
        printf("Maximum number of courses reached for this department.\n");
        return;
    }

    int courseIndex = uni.departments[deptIndex].totalCourses;

    printf("Enter course ID: ");
    scanf("%d", &uni.departments[deptIndex].course[courseIndex].courseID);
    getchar();

    printf("Enter course name: ");
    fgets(uni.departments[deptIndex].course[courseIndex].courseName, 50, stdin);
    strtok(uni.departments[deptIndex].course[courseIndex].courseName, "\n");

    printf("Enter instructor name: ");
    fgets(uni.departments[deptIndex].course[courseIndex].instructorName, 50, stdin);
    strtok(uni.departments[deptIndex].course[courseIndex].instructorName, "\n");

    printf("Enter credits: ");
    scanf("%d", &uni.departments[deptIndex].course[courseIndex].credits);
    getchar();

    uni.departments[deptIndex].totalCourses++;
    printf("Course added successfully.\n");
}

void displayDetails()
{
    if (uni.totalDepartments == 0)
    {
        printf("No departments available.\n");
        return;
    }

    for (int i = 0; i < uni.totalDepartments; i++)
    {
        printf("\nDepartment: %s\n", uni.departments[i].departmentName);
        for (int j = 0; j < uni.departments[i].totalCourses; j++)
        {
            printf("  Course ID: %d\n", uni.departments[i].course[j].courseID);
            printf("  Course Name: %s\n", uni.departments[i].course[j].courseName);
            printf("  Instructor Name: %s\n", uni.departments[i].course[j].instructorName);
            printf("  Credits: %d\n\n", uni.departments[i].course[j].credits);
        }
    }
}

void calculateTotalCredits()
{
    if (uni.totalDepartments == 0)
    {
        printf("No departments available.\n");
        return;
    }

    int deptIndex;
    printf("Select a department number:\n");
    for (int i = 0; i < uni.totalDepartments; i++)
    {
        printf("%d - %s\n", i + 1, uni.departments[i].departmentName);
    }
    printf("Enter your choice: ");
    scanf("%d", &deptIndex);
    getchar();

    if (deptIndex < 1 || deptIndex > uni.totalDepartments)
    {
        printf("Invalid department selection.\n");
        return;
    }

    deptIndex--;

    int totalCredits = 0;
    for (int i = 0; i < uni.departments[deptIndex].totalCourses; i++)
    {
        totalCredits += uni.departments[deptIndex].course[i].credits;
    }

    printf("Total credits for department '%s': %d\n", uni.departments[deptIndex].departmentName, totalCredits);
}
